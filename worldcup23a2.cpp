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
	int size = AllplayersTable.getSize();
	// TODO: Your code goes here
	LinkedList<Player> **playersList = AllplayersTable.GetArray();
	ListNode<Player> *temp = nullptr;
	for (int i = 0; i < size; i++)
	{
		temp = playersList[i]->GetHead();
		while (temp != nullptr)
		{
			temp->GetValue().deletePlayerReversedTreeNode();
			temp = temp->GetNext();
		}
	}
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
		TeamAndAbilities newTeamRankedTree(teamId, 0);
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Insert(teamsAbilitiesRankTree.root, newTeamRankedTree);
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

	return StatusType::SUCCESS;
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

	if (isPlayerExist(playerId) || isTeamExist(teamId) == false)
	{
		return StatusType::FAILURE;
	}
	try
	{
		AVLNode<Team> *teamOnTree = teamsTree.find(teamsTree.root, teamId); // the team on the tree ordered by teamId

		ListNode<Set<Player>> *teamOnHT = TeamsHashTable.FindPointer(teamId); // the team on the Hashtable representing the DisjointSet of UNION - FIND
																			  // the team on the reversed tree
		ReversedTreeNode<Player> *newPlayerNode;							  // the player node on the reversed tree
		Player newplayer = Player(playerId);
		AllplayersTable.Insert(newplayer, playerId);
		ListNode<Player> *playerOnHT = AllplayersTable.FindPointer(playerId);
		playerOnHT->GetValue().setPlayerTeamID(teamId);
		playerOnHT->GetValue().setPlayerAbility(ability);
		playerOnHT->GetValue().setPlayerCards(cards);
		playerOnHT->GetValue().setPlayerSpirit(spirit);
		playerOnHT->GetValue().setGamesPlayedINIT(gamesPlayed);

		if (teamOnTree == nullptr || teamOnHT == nullptr)
		{
			return StatusType::FAILURE;
		}
		// updating the player fields
		if (teamOnTree->GetValue().getNumOfPlayers() == 0) // meaning this is the first player to be added to the team
		{
			playerOnHT->GetValue().setIsRootPlayer(true);
			playerOnHT->GetValue().setIsTeamActive(true);
			playerOnHT->GetValue().setGamesTeamPlayedBefore(0);
			playerOnHT->GetValue().setGamesFromRootPlayer(0);
			playerOnHT->GetValue().setSpiritsBeforeMe(spirit.neutral());
			playerOnHT->GetValue().setlSpiritFromRootPlayer(spirit.neutral());
			playerOnHT->GetValue().setWholeTeamSpiritSoFar(spirit);
			newPlayerNode = new ReversedTreeNode<Player>(playerOnHT->GetValue());
			newPlayerNode->SetParent(nullptr);
			// newPlayerNode->SetSetOfTree(teamOnHT->GetValue());
			teamOnHT->GetValue().setRootOfSet(newPlayerNode);
			teamOnTree->GetValue().setTeamReversedTreeRoot(newPlayerNode);
		}
		else
		{
			ReversedTreeNode<Player> *teamOnReversedTree = teamOnHT->GetValue().GetRootOfSet();
			playerOnHT->GetValue().setIsRootPlayer(false);
			playerOnHT->GetValue().setIsTeamActive(true);
			playerOnHT->GetValue().setGamesTeamPlayedBefore(teamOnReversedTree->GetValue().getGamesFromRootPlayer());
			playerOnHT->GetValue().setGamesFromRootPlayer(0);
			playerOnHT->GetValue().setSpiritsBeforeMe(teamOnReversedTree->GetValue().getWholeTeamSpiritSoFar());
			playerOnHT->GetValue().setlSpiritFromRootPlayer(teamOnReversedTree->GetValue().getSpiritFromRootPlayer().inv());
			playerOnHT->GetValue().setWholeTeamSpiritSoFar(spirit.neutral());
			newPlayerNode = new ReversedTreeNode<Player>(playerOnHT->GetValue());
			newPlayerNode->SetSetOfTree(nullptr);
			newPlayerNode->SetParent(teamOnHT->GetValue().GetRootOfSet());
			teamOnReversedTree->GetValue().multiplayPlayerSpiritToWholeTeamSpiritSoFar(spirit);
		}

		// updating the team fields on the tree
		// teamOnTree->GetValue().multiplyNewPlayerToTeamSpirit(spirit);

		// teamOnTree->GetValue().getTeamReversedTreeRoot()->GetValue().setWholeTeamSpiritSoFar(teamOnTree->GetValue().getTeamSpirit());
		teamOnHT->GetValue().IncreaseSizeOfSetByOne();
		teamOnTree->GetValue().increaseNumOfPlayers();
		if (goalKeeper)
		{

			teamOnTree->GetValue().increaseNumOfGoalKeepers();
		}
		TeamAndAbilities OLDteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility());
		TeamAndAbilities NEWteamAndAbilities(teamId, teamOnTree->GetValue().getSumPlayersAbility() + ability);
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Remove(teamsAbilitiesRankTree.root, OLDteamAndAbilities);

		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Insert(teamsAbilitiesRankTree.root, NEWteamAndAbilities);
		teamOnTree->GetValue().addPlayerAbility(ability);

		playerOnHT->GetValue().setPlayerReversedTreeNode(newPlayerNode);
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
	ListNode<Set<Player>> *team1OnHT = TeamsHashTable.FindPointer(teamId1);
	ListNode<Set<Player>> *team2OnHT = TeamsHashTable.FindPointer(teamId2);
	ReversedTreeNode<Player> *team1OnReversedTree = team1OnHT->GetValue().GetRootOfSet();
	ReversedTreeNode<Player> *team2OnReversedTree = team2OnHT->GetValue().GetRootOfSet();
	int gamesPlayed1 = team1OnHT->GetValue().GetRootOfSet()->GetValue().getGamesFromRootPlayer();
	int gamesPlayed2 = team2OnHT->GetValue().GetRootOfSet()->GetValue().getGamesFromRootPlayer();
	team1Node->GetValue().setGamesPlayed(gamesPlayed1 + 1);
	team2Node->GetValue().setGamesPlayed(gamesPlayed2 + 1);
	team1OnHT->GetValue().GetRootOfSet()->GetValue().setGamesFromRootPlayer(gamesPlayed1 + 1);
	team2OnHT->GetValue().GetRootOfSet()->GetValue().setGamesFromRootPlayer(gamesPlayed2 + 1);
	// team1.getTeamReversedTreeRoot()->GetValue().setGamesFromRootPlayer(team1.getGamesPlayed() + 1);
	// team2.getTeamReversedTreeRoot()->GetValue().setGamesFromRootPlayer(team2.getGamesPlayed() + 1);
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
		permutation_t wholeTeam1Spirit = team1OnReversedTree->GetValue().getWholeTeamSpiritSoFar();
		int team1Strength = wholeTeam1Spirit.strength();
		permutation_t wholeTeam2Spirit = team2OnReversedTree->GetValue().getWholeTeamSpiritSoFar();
		int team2Strength = wholeTeam2Spirit.strength();
		if (team1Strength > team2Strength)
		{
			team1Node->GetValue().setPoints(team1.getPoints() + 3);
			return FIRST_TEAM_BY_STRENTH;
		}
		else if (team1Strength < team2Strength)
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

	if (playerId <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	if (isPlayerExist(playerId) == false)
	{
		return StatusType::FAILURE;
	}
	try
	{
		ReversedTreeNode<Player> *playerNode = AllplayersTable.Find(playerId).getPlayerReversedTreeNode();
		// ReversedTreeNode<Player> *rootPlayerNode = findRootReversedTree(playerNode);

		findSet(playerId);
		int GamesfromMaster = 0;
		int gamesBeforeMe = playerNode->GetValue().getGamesTeamPlayedBefore();
		int gamesFromRoot = playerNode->GetValue().getGamesFromRootPlayer();
		if (playerNode->GetParent() != NULL)
		{
			GamesfromMaster = getGamesPlayedFromMasterRoot(playerId);
		}

		int result = gamesFromRoot - gamesBeforeMe + GamesfromMaster;
		result = result + playerNode->GetValue().getGamesPlayedINIT();
		return result;
	}
	catch (const std::exception &e)
	{
		return StatusType::ALLOCATION_ERROR;
	}

	// TODO: Your code goes here
	return 22;
}

StatusType world_cup_t::add_player_cards(int playerId, int cards)
{
	// TODO: Your code goes here
	if (playerId <= 0 || cards < 0)
	{
		return StatusType::INVALID_INPUT;
	}
	try
	{
		Player ToFindPlayer(playerId);
		if (isPlayerExist(playerId) == false)
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
		// pathCompression(playerNode,rootPlayerNode);
		findSet(playerId);
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
		if (isPlayerExist(playerId) == false)
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
		// teamsAbilitiesRankTree.PrintInOrder(teamsAbilitiesRankTree.root);
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
	if (playerId <= 0)
	{
		return StatusType::INVALID_INPUT;
	}
	if (!isPlayerExist(playerId))
	{
		return StatusType::FAILURE;
	}
	try
	{
		// std::cout << "playerId: " << playerId << std::endl;
		ReversedTreeNode<Player> *playerNode = AllplayersTable.Find(playerId).getPlayerReversedTreeNode();
		ReversedTreeNode<Player> *rootPlayerNode = findRootReversedTree(playerNode);
		if (rootPlayerNode->GetValue().getIsTeamActive() == false)
		{
			return StatusType::FAILURE;
		}
		findSet(playerId); // taking care of the path compression
		permutation_t spiritsFromMaster = getSpiritFromMasterRoot(playerId);
		permutation_t spiritsBeforeMe = playerNode->GetValue().getSpiritsBeforeMe();
		permutation_t spiritsFromRoot = playerNode->GetValue().getSpiritFromRootPlayer();
		//permutation_t MASTERmultiplyFR = spiritsFromMaster.operator*(spiritsFromRoot);
		permutation_t playerspirit = playerNode->GetValue().getPlayerSpirit();
		permutation_t result = spiritsFromRoot.operator*(spiritsBeforeMe);
		if (playerNode->GetParent() != nullptr)
		{
			result = spiritsFromMaster.operator*(result);
		}
		result = result.operator*(playerspirit);
		return result;
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}
	return StatusType::SUCCESS;
}

StatusType world_cup_t::buy_team(int buyerId, int boughtId)
{
	if (buyerId <= 0 || boughtId <= 0 || buyerId == boughtId)
	{
		return StatusType::INVALID_INPUT;
	}
	if (!isTeamExist(buyerId) || !isTeamExist(boughtId))
	{
		return StatusType::FAILURE;
	}
	try
	{
		AVLNode<Team> *team1onTree = teamsTree.find(teamsTree.root, buyerId);
		AVLNode<Team> *team2onTree = teamsTree.find(teamsTree.root, boughtId);
		int buyerSize = team1onTree->GetValue().getNumOfPlayers();
		int boughtSize = team2onTree->GetValue().getNumOfPlayers();
		if (buyerSize == 0 && boughtSize == 0)
		{
			unionEmptySet(buyerId, boughtId);
		}
		else
		{
			if (buyerSize >= boughtSize)
				unionSets(buyerId, boughtId);
			else
				unionSetsBoughtBigger(buyerId, boughtId);
		}
		AVLNode<Team> *buyerOnTree = teamsTree.find(teamsTree.root, buyerId);
		AVLNode<Team> *boughtOnTree = teamsTree.find(teamsTree.root, boughtId);
		// ListNode<Set<Player>> *BoughtteamOnHT = TeamsHashTable.FindPointer(boughtId);
		// ListNode<Set<Player>> *BuyerTeamOnHT = TeamsHashTable.FindPointer(buyerId);
		int boughtTeamAbility = boughtOnTree->GetValue().getSumPlayersAbility();
		buyerOnTree->GetValue().addPoints(boughtOnTree->GetValue().getPoints());
		buyerOnTree->GetValue().addnumOfPlayers(boughtOnTree->GetValue().getNumOfPlayers());
		buyerOnTree->GetValue().addnumOfGoalKeepers(boughtOnTree->GetValue().getNumOfGoalKeepers());
		//-------------------------------------------
		// TAKE CARE IN UNION SET!!!!
		//------------------------------------------
		// buyerOnTree->GetValue().multiplyNewPlayerToTeamSpirit(boughtOnTree->GetValue().getTeamSpirit());
		//
		// takning care of the the games played

		TeamAndAbilities OldbuyerTeamAndAbilities(buyerOnTree->GetValue().getTeamID(), buyerOnTree->GetValue().getSumPlayersAbility());
		TeamAndAbilities boughtTeamAndAbilities(boughtOnTree->GetValue().getTeamID(), boughtOnTree->GetValue().getSumPlayersAbility());
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Remove(teamsAbilitiesRankTree.root, boughtTeamAndAbilities);
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Remove(teamsAbilitiesRankTree.root, OldbuyerTeamAndAbilities);
		TeamAndAbilities NewbuyerTeamAndAbilities(buyerOnTree->GetValue().getTeamID(), buyerOnTree->GetValue().getSumPlayersAbility() + boughtTeamAbility);
		teamsAbilitiesRankTree.root = teamsAbilitiesRankTree.Insert(teamsAbilitiesRankTree.root, NewbuyerTeamAndAbilities);

		buyerOnTree->GetValue().addSumPlayersAbility(boughtTeamAbility);
		teamsTree.root = teamsTree.Remove(teamsTree.root, boughtOnTree->GetValue());

		numberOfActiveTeams--;
	}
	catch (std::bad_alloc &ba)
	{
		return StatusType::ALLOCATION_ERROR;
	}

	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

bool world_cup_t::isTeamExist(int teamId)
{
	return teamsTree.isItInTree(teamsTree.root, teamId);
}
bool world_cup_t::isPlayerExist(int playerId)
{
	return AllplayersTable.isIn(playerId);
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
void world_cup_t::unionEmptySet(int buyerId, int boughtId)
{
	ListNode<Set<Player>> *boughtSet = TeamsHashTable.FindPointer(boughtId);
	TeamsHashTable.Remove(boughtId, boughtSet->GetValue());
}

void world_cup_t::unionSets(int buyerId, int boughtId)
{
	// need to take care of the case that team2 is empty
	ListNode<Set<Player>> *buyerSet = TeamsHashTable.FindPointer(buyerId);
	ListNode<Set<Player>> *boughtSet = TeamsHashTable.FindPointer(boughtId);

	// int buyerSize = buyerSet->GetValue().GetSizeOfSet();
	int boughtSize = boughtSet->GetValue().GetSizeOfSet();
	if (boughtSize == 0)
	{
		TeamsHashTable.Remove(boughtSet->GetValue().GetIdOfSet(), boughtSet->GetValue());
		return;
	}
	ReversedTreeNode<Player> *boughtRootPlayerNode = boughtSet->GetValue().GetRootOfSet();
	ReversedTreeNode<Player> *buyerRootPlayerNode = buyerSet->GetValue().GetRootOfSet();

	permutation_t buyer_wholeTeamSpirit = buyerRootPlayerNode->GetValue().getWholeTeamSpiritSoFar();
	permutation_t bought_wholeTeamSpirit = boughtRootPlayerNode->GetValue().getWholeTeamSpiritSoFar();
	permutation_t bought_spiritFromRoot = boughtRootPlayerNode->GetValue().getSpiritFromRootPlayer();
	permutation_t buyer_spiritFromRoot = buyerRootPlayerNode->GetValue().getSpiritFromRootPlayer();
	permutation_t neutralP = buyer_wholeTeamSpirit.neutral();
	// permutation_t buyerFRmultiplyWT = buyer_spiritFromRoot.operator*(buyer_wholeTeamSpirit);
	permutation_t testSpirit = buyer_spiritFromRoot.inv().operator*(buyer_wholeTeamSpirit);
	buyerRootPlayerNode->GetValue().setWholeTeamSpiritSoFar(buyer_wholeTeamSpirit.operator*(bought_wholeTeamSpirit));
	//--------------------------OPTIONAL------------------------------------------
	boughtRootPlayerNode->GetValue().setWholeTeamSpiritSoFar(neutralP);
	//--------------------------OPTIONAL------------------------------------------
	boughtRootPlayerNode->GetValue().setlSpiritFromRootPlayer(testSpirit.operator*(bought_spiritFromRoot));

	//-----------------GAMES RELATED-----------------------
	int boughtGames = boughtRootPlayerNode->GetValue().getGamesFromRootPlayer();
	int buyerGames = buyerRootPlayerNode->GetValue().getGamesFromRootPlayer();
	boughtRootPlayerNode->GetValue().setGamesFromRootPlayer(boughtGames - buyerGames);
	//-----------------GAMES RELATED-----------------------

	buyerSet->GetValue().IncreaseSizeOfSetBy(boughtSize);
	boughtSet->GetValue().GetRootOfSet()->SetParent(buyerSet->GetValue().GetRootOfSet());
	boughtSet->GetValue().GetRootOfSet()->SetSetOfTree(NULL);
	TeamsHashTable.Remove(boughtSet->GetValue().GetIdOfSet(), boughtSet->GetValue());
}

void world_cup_t::unionSetsBoughtBigger(int buyerId, int boughtId)
{
	ListNode<Set<Player>> *buyerSet = TeamsHashTable.FindPointer(buyerId);
	ListNode<Set<Player>> *boughtSet = TeamsHashTable.FindPointer(boughtId);
	int bought_size = boughtSet->GetValue().GetSizeOfSet();
	int buyer_size = buyerSet->GetValue().GetSizeOfSet();
	// need to take care of the case that buyerTeam is empty
	if (buyer_size == 0)
	{
		AVLNode<Team> *buyerOnTree = teamsTree.find(teamsTree.root, buyerId);
		buyerOnTree->GetValue().setTeamReversedTreeRoot(boughtSet->GetValue().GetRootOfSet());
		buyerSet->GetValue().IncreaseSizeOfSetBy(bought_size);
		buyerSet->GetValue().setRootOfSet(boughtSet->GetValue().GetRootOfSet());

		boughtSet->GetValue().GetRootOfSet()->SetSetOfTree(NULL);
		TeamsHashTable.Remove(boughtSet->GetValue().GetIdOfSet(), boughtSet->GetValue());
		return;
	}
	ReversedTreeNode<Player> *boughtRootPlayerNode = boughtSet->GetValue().GetRootOfSet();
	ReversedTreeNode<Player> *buyerRootPlayerNode = buyerSet->GetValue().GetRootOfSet();
	//-----------------GAMES RELATED-----------------------
	int boughtGames = boughtRootPlayerNode->GetValue().getGamesFromRootPlayer();
	int buyerGames = buyerRootPlayerNode->GetValue().getGamesFromRootPlayer();
	// boughtRootPlayerNode->GetValue().setGamesFromRootPlayer(boughtGames - buyerGames);
	buyerRootPlayerNode->GetValue().setGamesFromRootPlayer(buyerGames - boughtGames);
	//-----------------GAMES RELATED-----------------------

	permutation_t buyer_wholeTeamSpirit = buyerRootPlayerNode->GetValue().getWholeTeamSpiritSoFar();
	permutation_t bought_wholeTeamSpirit = boughtRootPlayerNode->GetValue().getWholeTeamSpiritSoFar();
	permutation_t bought_spiritFromRoot = boughtRootPlayerNode->GetValue().getSpiritFromRootPlayer();
	permutation_t buyer_spiritFromRoot = buyerRootPlayerNode->GetValue().getSpiritFromRootPlayer();
	permutation_t neutralP = buyer_wholeTeamSpirit.neutral();

	buyerRootPlayerNode->GetValue().setWholeTeamSpiritSoFar(neutralP);
	boughtRootPlayerNode->GetValue().setWholeTeamSpiritSoFar(buyer_wholeTeamSpirit.operator*(bought_wholeTeamSpirit));
	//permutation_t buyerFRbuyerWT = buyer_spiritFromRoot.operator*(buyer_wholeTeamSpirit);

	// boughtRootPlayerNode->GetValue().setlSpiritFromRootPlayer(buyerFRbuyerWT.operator*(bought_spiritFromRoot));
	boughtRootPlayerNode->GetValue().setlSpiritFromRootPlayer(buyer_wholeTeamSpirit.operator*(bought_spiritFromRoot));
	permutation_t newBoughtFR = boughtRootPlayerNode->GetValue().getSpiritFromRootPlayer();
	//	permutation_t buyerWTboughtFR = buyer_wholeTeamSpirit.operator*(bought_spiritFromRoot);
		buyerRootPlayerNode->GetValue().setlSpiritFromRootPlayer((newBoughtFR).inv().operator*(buyer_spiritFromRoot));

		buyerSet->GetValue().IncreaseSizeOfSetBy(buyer_size);
		buyerSet->GetValue().GetRootOfSet()->SetParent(boughtSet->GetValue().GetRootOfSet());
		buyerSet->GetValue().setRootOfSet(boughtSet->GetValue().GetRootOfSet());
		boughtSet->GetValue().GetRootOfSet()->SetSetOfTree(NULL);

		TeamsHashTable.Remove(boughtSet->GetValue().GetIdOfSet(), boughtSet->GetValue());
}

Set<Player> *world_cup_t::findSet(int playerId)
{
	ReversedTreeNode<Player> *current_element = AllplayersTable.Find(playerId).getPlayerReversedTreeNode();
	ReversedTreeNode<Player> *next_element;
	ReversedTreeNode<Player> *root = AllplayersTable.Find(playerId).getPlayerReversedTreeNode();
	permutation_t spiritsUpTheTree = permutation_t().neutral(); // = root->GetValue().getSpiritFromRootPlayer();

	int GamesPlayedTotalFromRoots = 0;

	while (root->GetParent() != NULL)
	{

		GamesPlayedTotalFromRoots += root->GetValue().getGamesFromRootPlayer();
		spiritsUpTheTree = (root->GetValue().getSpiritFromRootPlayer().operator*(spiritsUpTheTree));
		root = root->GetParent();
	}

	// gamesPlayedCounter += AllplayersTable.Find(playerId).getGamesFromRootPlayer();

	while (current_element->GetValue() != root->GetValue())
	{

		int currentGamesFR = current_element->GetValue().getGamesFromRootPlayer();
		current_element->GetValue().setGamesFromRootPlayer(GamesPlayedTotalFromRoots);
		GamesPlayedTotalFromRoots -= currentGamesFR;
		permutation_t currentSpiritFromRoot = current_element->GetValue().getSpiritFromRootPlayer();
		permutation_t currentSpiritFromRootInv = currentSpiritFromRoot.inv();
		current_element->GetValue().setlSpiritFromRootPlayer(spiritsUpTheTree);
		spiritsUpTheTree = spiritsUpTheTree.operator*(currentSpiritFromRootInv);
		next_element = current_element->GetParent();
		current_element->SetParent(root);
		current_element = next_element;
	}

	return root->GetSetOfTree();
}
int world_cup_t::getGamesPlayedFromMasterRoot(int playrId)
{
	ReversedTreeNode<Player> *current_element = AllplayersTable.Find(playrId).getPlayerReversedTreeNode();
	while (current_element->GetParent() != NULL)
	{
		current_element = current_element->GetParent();
	}
	return current_element->GetValue().getGamesFromRootPlayer();
}
permutation_t world_cup_t::getSpiritFromMasterRoot(int playrId)
{
	ReversedTreeNode<Player> *current_element = AllplayersTable.Find(playrId).getPlayerReversedTreeNode();
	while (current_element->GetParent() != NULL)
	{
		current_element = current_element->GetParent();
	}
	return current_element->GetValue().getSpiritFromRootPlayer();
}