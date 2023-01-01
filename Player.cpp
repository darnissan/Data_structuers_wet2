#include "Player.h"

Player::Player(int playerID, int teamId, const permutation_t &spirit, int gamesPlayed, int ability, int cards, bool goalKeeper)
{
    this->playerID = playerID;
    this->playerTeamID = teamId;
    this->playerSpirit = spirit;
    this->gamesPlayedINIT = gamesPlayed;
    this->playerAbility = ability;
    this->playerCards = cards;
    this->isGoalKeeper = goalKeeper;
    this->isTeamActive = true;
    this->isRootPlayer = false;
    this->gamesTeamPlayedBefore = 0;
    this->gamesFromRootPlayer = 0;
}
Player::~Player()
{
    if (playerReversedTreeNode != nullptr)
    {
        delete playerReversedTreeNode;
        playerReversedTreeNode = nullptr;
    }
}
int Player::getPlayerID()
{
    return this->playerID;
}
int Player::getPlayerAbility()
{
    return this->playerAbility;
}
int Player::getPlayerTeamID()
{
    return this->playerTeamID;
}
permutation_t Player::getPlayerSpirit()
{
    return this->playerSpirit;
}
int Player::getPlayerCards()
{
    return this->playerCards;
}
void Player::addCards(int newCards)
{
    this->playerCards += newCards;
}
void Player::setPlayerTeamID(int newTeamID)
{
    this->playerTeamID = newTeamID;
}
int Player::getGamesPlayedINIT()
{
    return this->gamesPlayedINIT;
}
int Player::getGamesTeamPlayedBefore()
{
    return this->gamesTeamPlayedBefore;
}
int Player::getGamesFromRootPlayer()
{
    return this->gamesFromRootPlayer;
}
bool Player::getIsGoalKeeper()
{
    return this->isGoalKeeper;
}
bool Player::getIsTeamActive()
{
    return this->isTeamActive;
}
bool Player::getIsRootPlayer()
{
    return this->isRootPlayer;
}
void Player::setIsRootPlayer(bool isRootPlayer)
{
    this->isRootPlayer = isRootPlayer;
}
void Player::setIsTeamActive(bool isTeamActive)
{
    this->isTeamActive = isTeamActive;
}
void Player::setGamesTeamPlayedBefore(int gamesTeamPlayedBefore)
{
    this->gamesTeamPlayedBefore = gamesTeamPlayedBefore;
}
void Player::setGamesFromRootPlayer(int gamesFromRootPlayer)
{
    this->gamesFromRootPlayer = gamesFromRootPlayer;
}
bool Player::operator==(const Player &player) const
{
    return this->playerID == player.playerID;
}
bool Player::operator!=(const Player &player) const
{
    return this->playerID != player.playerID;
}
void Player::setPlayerReversedTreeNode(ReversedTreeNode<Player> *playerReversedTreeNode)
{
    this->playerReversedTreeNode = playerReversedTreeNode;
}
ReversedTreeNode<Player> *Player::getPlayerReversedTreeNode()
{
    return this->playerReversedTreeNode;
}
void Player::setSpiritsBeforeMe(permutation_t spiritsBeforeMe)
{
    this->spiritsBeforeMe = spiritsBeforeMe;
}
permutation_t Player::getSpiritsBeforeMe()
{
    return this->spiritsBeforeMe;
}
void Player::setlSpiritFromRootPlayer(permutation_t SpiritFromRootPlayer)
{
    this->SpiritFromRootPlayer = SpiritFromRootPlayer;
}
permutation_t Player::getSpiritFromRootPlayer()
{
    return this->SpiritFromRootPlayer;
}
void Player::setTeamUnActive()
{
    this->isTeamActive = false;
}
void Player::setGamesPlayedINIT(int gamesPlayedINIT)
{
    this->gamesPlayedINIT = gamesPlayedINIT;
}
void Player::setPlayerAbility(int playerAbility)
{
    this->playerAbility = playerAbility;
}
void Player::setPlayerCards(int playerCards)
{
    this->playerCards = playerCards;
}
void Player::setPlayerSpirit(permutation_t playerSpirit)
{
    this->playerSpirit = playerSpirit;
}

