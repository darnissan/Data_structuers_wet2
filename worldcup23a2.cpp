#include "worldcup23a2.h"
#include "wet2util.h"
#define TIE 0
#define FIRST_TEAM_BY_ABILITY 1
#define FIRST_TEAM_BY_STRENTH 2
#define SECOND_TEAM_BY_ABILITY 3
#define SECOND_TEAM_BY_STRENTH 4
template <class T>
void pathCompression(ReversedTreeNode<T> *node, ReversedTreeNode<T> *root);
template <class T>
ReversedTreeNode<T> *findRootReversedTree(ReversedTreeNode<T> *node);
world_cup_t::world_cup_t()
{

	// TODO: Your code goes here
}

world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}

StatusType world_cup_t::add_team(int teamId)
{
	// TODO: Your code goes here
	if (teamId <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	try
	{
		if (isTeamExist(teamId))
		{
			return StatusType::FAILURE;
		}
		Team newTeam(teamId);
		numberOfActiveTeams++;
		teamsTree.root = teamsTree.Insert(teamsTree.root, newTeam);

		Set<Player> newTeamSet = Set<Player>(teamId, nullptr);

		TeamsHashTable.Insert(newTeamSet, teamId);
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}

	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_team(int teamId)
{
	// remove the team from the teamsTree
	// remove the team from the teamsAbilitiesRankTree
	// remove the team from the TeamsHashTable
	// remove the team from the playersByTeamId
	if (teamId <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	if (isTeamExist(teamId) == false)
	{
		return StatusType::FAILURE;
	}
	try
	{

		int ability = teamsTree.find(teamsTree.root, teamId)->GetValue().getSumPlayersAbility();
		Team teamToBeRemovedFromTree = teamsTree.find(teamsTree.root, teamId)->GetValue();
		teamToBeRemovedFromTree.setReversedTreeRootTeamUnActive();
		teamsTree.root = teamsTree.Remove(teamsTree.root, teamToBeRemovedFromTree);
		TeamAndAbilities teamToBeRemovedRankedTree(teamId, ability);
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Remove(teamsAbilitiesRankTree.root, teamToBeRemovedRankedTree);
		Set<Player> teamToBeRemovedFromHT = TeamsHashTable.Find(teamId);
		if (teamToBeRemovedFromHT.GetRootOfSet() != nullptr)
		{
			teamToBeRemovedFromHT.GetRootOfSet()->GetValue().setIsTeamActive(false);
		}

		TeamsHashTable.Remove(teamId, teamToBeRemovedFromHT);
		numberOfActiveTeams--;
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}
	catch (const std::exception &e)
	{
		return StatusType::ALLOCATION_ERROR;
	}

	return StatusType::FAILURE;
}

StatusType world_cup_t::add_player(int playerId, int teamId,
								   const permutation_t &spirit, int gamesPlayed,
								   int ability, int cards, bool goalKeeper)
{
	// TODO: Your code goes here
	// 1 - check if the input is valid
	// 2 - check if the player is already in the system
	// 3 - check if the team is in the system
	// 4 - add the player to the HashTable of AllPLayers
	// 5 - add the player to the team on the DisjointSet
	// 6 update the team fields regarding the player and the teamAndAbilities tree
	// 7- update the relevant fields in the player -gamesPlayed
	if (playerId <= 0 || teamId <= 0 || spirit.isvalid() == false || gamesPlayed < 0 || cards < 0)
	{
		return StatusType::INVALID_INPUT;
	}

	Player newPlayer(playerId, teamId, spirit, gamesPlayed, ability, cards, goalKeeper);

	if (isPlayerExist(newPlayer, playerId) || isTeamExist(teamId) == false)
	{
		return StatusType::FAILURE;
	}
	try
	{
		AVLNode<Team> *teamOnTree = teamsTree.find(teamsTree.root, teamId); // the team on the tree ordered by teamId

		ListNode<Set<Player>> *teamOnHT = TeamsHashTable.FindPointer(teamId); // the team on the Hashtable representing the DisjointSet of UNION - FIND

		ReversedTreeNode<Player> *newPlayerNode; // the player node on the reversed tree

		if (teamOnTree == nullptr || teamOnHT == nullptr)
		{
			return StatusType::FAILURE;
		}
		// updating the player fields
		if (teamOnTree->GetValue().getNumOfPlayers() == 0) // meaning this is the first player to be added to the team
		{
			newPlayer.setIsRootPlayer(true);
			newPlayer.setIsTeamActive(true);
			newPlayer.setGamesTeamPlayedBefore(0);
			newPlayer.setGamesFromRootPlayer(0);
			newPlayer.setSpiritsBeforeMe(spirit.neutral());
			newPlayer.setlSpiritFromRootPlayer(spirit.neutral());
			newPlayerNode = new ReversedTreeNode<Player>(newPlayer);
			newPlayerNode->SetParent(nullptr);
			// newPlayerNode->SetSetOfTree(teamOnHT->GetValue());
			teamOnHT->GetValue().setRootOfSet(newPlayerNode);
			teamOnTree->GetValue().setTeamReversedTreeRoot(newPlayerNode);
		}
		else
		{
			newPlayer.setIsRootPlayer(false);
			newPlayer.setIsTeamActive(true);
			newPlayer.setGamesTeamPlayedBefore(teamOnTree->GetValue().getGamesPlayed());
			newPlayer.setGamesFromRootPlayer(teamOnHT->GetValue().GetRootOfSet()->GetValue().getGamesFromRootPlayer());
			newPlayer.setSpiritsBeforeMe(teamOnTree->GetValue().getTeamSpirit());
			newPlayer.setlSpiritFromRootPlayer(teamOnHT->GetValue().GetRootOfSet()->GetValue().getSpiritFromRootPlayer());
			newPlayerNode = new ReversedTreeNode<Player>(newPlayer);
			newPlayerNode->SetSetOfTree(nullptr);
			newPlayerNode->SetParent(teamOnHT->GetValue().GetRootOfSet());
		}

		// updating the team fields on the tree

		teamOnHT->GetValue().IncreaseSizeOfSetByOne();
		teamOnTree->GetValue().increaseNumOfPlayers();
		if (goalKeeper)
		{

			teamOnTree->GetValue().increaseNumOfGoalKeepers();
			if (teamOnTree->GetValue().getNumOfGoalKeepers() == 1)
			{
				TeamAndAbilities NEWteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility() + ability);
				teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Insert(teamsAbilitiesRankTree.root, NEWteamAndAbilities);
			}
			else
			{
				TeamAndAbilities OLDteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility());
				teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Remove(teamsAbilitiesRankTree.root, OLDteamAndAbilities);
				TeamAndAbilities NEWteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility() + ability);
				teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Insert(teamsAbilitiesRankTree.root, NEWteamAndAbilities);
			}
		}
		teamOnTree->GetValue().multiplyNewPlayerToTeamSpirit(spirit);
		teamOnTree->GetValue().addPlayerAbility(ability);
		TeamAndAbilities OLDteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility());
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Remove(teamsAbilitiesRankTree.root, OLDteamAndAbilities);
		TeamAndAbilities NEWteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility() + ability);
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Insert(teamsAbilitiesRankTree.root, NEWteamAndAbilities);
		newPlayer.setPlayerReversedTreeNode(newPlayerNode);
		AllplayersTable.Insert(newPlayer, playerId);
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	if (teamId1 <= 0 || teamId2 <= 0 || teamId1 == teamId2)
	{
		return StatusType::INVALID_INPUT;
	}
	if (isTeamExist(teamId1) == false || isTeamExist(teamId2) == false)
	{
		return StatusType::FAILURE;
	}
	AVLNode<Team> *team1Node = teamsTree.find(teamsTree.root, teamId1);
	AVLNode<Team> *team2Node = teamsTree.find(teamsTree.root, teamId2);
	Team team1 = team1Node->GetValue();
	Team team2 = team2Node->GetValue();
	if (team1.getNumOfGoalKeepers() == 0 || team2.getNumOfGoalKeepers() == 0)
	{
		return StatusType::FAILURE;
	}
	team1.getTeamReversedTreeRoot()->GetValue().setGamesFromRootPlayer(team1.getGamesPlayed() + 1);
	team2.getTeamReversedTreeRoot()->GetValue().setGamesFromRootPlayer(team2.getGamesPlayed() + 1);
	int pointsAndAbility1 = team1.getPoints() + team1.getSumPlayersAbility();
	int pointsAndAbility2 = team2.getPoints() + team2.getSumPlayersAbility();
	if (pointsAndAbility1 > pointsAndAbility2)
	{
		team1Node->GetValue().setPoints(team1.getPoints() + 3);
		return FIRST_TEAM_BY_ABILITY;
	}
	else if (pointsAndAbility1 < pointsAndAbility2)
	{
		team2Node->GetValue().setPoints(team2.getPoints() + 3);
		return SECOND_TEAM_BY_ABILITY;
	}
	else
	{
		int team1Spirit = team1.getTeamSpirit().strength();
		int team2Spirit = team2.getTeamSpirit().strength();
		if (team1Spirit > team2Spirit)
		{
			team1Node->GetValue().setPoints(team1.getPoints() + 3);
			return FIRST_TEAM_BY_STRENTH;
		}
		else if (team1Spirit < team2Spirit)
		{
			team2Node->GetValue().setPoints(team2.getPoints() + 3);
			return SECOND_TEAM_BY_STRENTH;
		}
		else
		{
			team1Node->GetValue().setPoints(team1.getPoints() + 1);
			team2Node->GetValue().setPoints(team2.getPoints() + 1);
			return TIE;
		}
	}

	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::num_played_games_for_player(int playerId)
{
	// TODO: Your code goes here
	return 22;
}

StatusType world_cup_t::add_player_cards(int playerId, int cards)
{
	// TODO: Your code goes here
	if (playerId <= 0 || cards <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	try
	{
		Player ToFindPlayer(playerId);
		if (isPlayerExist(ToFindPlayer, playerId) == false)
		{
			return StatusType::FAILURE;
		}
		ReversedTreeNode<Player> *playerNode = AllplayersTable.Find(playerId).getPlayerReversedTreeNode();
		ReversedTreeNode<Player> *rootPlayerNode = findRootReversedTree(playerNode);
		if (rootPlayerNode->GetValue().getIsTeamActive() == false)
		{
			return StatusType::FAILURE;
		}
		playerNode->GetValue().addCards(cards);
		AllplayersTable.Find(playerId).addCards(cards);
		pathCompression(playerNode, rootPlayerNode);
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_player_cards(int playerId)
{
	// TODO: Your code goes here
	if (playerId <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	try
	{
		Player ToFindPlayer(playerId);
		if (isPlayerExist(ToFindPlayer, playerId) == false)
		{
			return StatusType::FAILURE;
		}
		int cards = AllplayersTable.Find(playerId).getPlayerCards();

		return cards;
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}

	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here
	if (teamId <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	try
	{
		if (!isTeamExist(teamId))
		{
			return StatusType::FAILURE;
		}
		return teamsTree.find(teamsTree.root, teamId)->GetValue().getPoints();
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_ith_pointless_ability(int i)
{
	if (i < 0 || i > numberOfActiveTeams)
	{
		return StatusType::FAILURE;
	}
	try
	{
		TeamAndAbilities resultTeam = teamsAbilitiesRankTree.Select(teamsAbilitiesRankTree.root, i + 1);
		return resultTeam.getTeamID();
	}
	catch (std::out_of_range &oor)
	{
		return StatusType::FAILURE;
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}
	return StatusType::SUCCESS;
}

output_t<permutation_t> world_cup_t::get_partial_spirit(int playerId)
{
	// TODO: Your code goes here
	return permutation_t();
}

StatusType world_cup_t::buy_team(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

bool world_cup_t::isTeamExist(int teamId)
{
	return teamsTree.isItInTree(teamsTree.root, teamId);
}
bool world_cup_t::isPlayerExist(const Player &player, int playerId)
{
	return AllplayersTable.isIn(player, playerId);
}
template <class T>
void pathCompression(ReversedTreeNode<T> *node, ReversedTreeNode<T> *root)
{
	if (node->GetParent() != NULL)
	{
		pathCompression(node->GetParent(), root);
		node->SetParent(root);
	}
}
template <class T>
ReversedTreeNode<T> *findRootReversedTree(ReversedTreeNode<T> *node)
{
	if (node->GetParent() == NULL)
	{
		return node;
	}
	else
	{
		return findRootReversedTree(node->GetParent());
	}
}


void world_cup_t::unionSets(int teamId1, int teamId2)
{
	Set<Player>* set1 = TeamsHashTable.Find(teamId1);
	Set<Player>* set2 = TeamsHashTable.Find(teamId2);
	int sizeSet1 = set1->GetSizeOfSet();
	int sizeSet2 = set2->GetSizeOfSet();
	int smaller_size = (sizeSet1 < sizeSet2) ? sizeSet1 : sizeSet2;
	Set<Player>* larger_set = (sizeSet1 >= sizeSet2) ? set1 : set2;
	Set<Player>* smaller_set = (sizeSet1 < sizeSet2) ? set1 : set2;

	larger_set->IncreaseSizeOfSetBy(smaller_size);
	smaller_set->GetRootOfSet()->SetParent(larger_set->GetRootOfSet());
	smaller_set->GetRootOfSet()->SetSetOfTree(NULL);
	TeamsHashTable.FindPointer(smaller_set->GetIdOfSet())->SetValue(NULL);
	delete smaller_set;
}

Set<Player>* world_cup_t::find(int value)
{
	ReversedTreeNode<Player> *current_element = AllplayersTable.Find(value).getPlayerReversedTreeNode();
	ReversedTreeNode<Player> *next_element;
	ReversedTreeNode<Player> *root = AllplayersTable.Find(value).getPlayerReversedTreeNode();
	
	while(root->GetParent() != NULL)
	{
		root = root->GetParent();
	}

	while(current_element->GetValue() != root->GetValue())
	{
		next_element = current_element->GetParent();
		current_element->SetParent(root);
		current_element = next_element;
	}

	return root->GetSetOfTree();
}
