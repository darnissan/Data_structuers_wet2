#include "Player.h"

Player::Player(int playerID, int teamId, const permutation_t &spirit, int gamesPlayed,int ability,int cards,bool goalKeeper)
{
    this->playerID=playerID;
    this->playerTeamID=teamId;
    this->playerSpirit=spirit;
    this->gamesPlayedINIT=gamesPlayed;
    this->playerAbility=ability;
    this->playerCards=cards;
    this->isGoalKeeper=goalKeeper;
    this->isTeamActive=true;
    this->isRootPlayer=false;
    this->gamesTeamPlayedBefore=0;
    this->gamesFromRootPlayer=0;
}
Player::~Player()=default;
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
    this->playerCards+=newCards;
}
void Player::setPlayerTeamID(int newTeamID)
{
    this->playerTeamID=newTeamID;
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
    this->isRootPlayer=isRootPlayer;
}
void Player::setIsTeamActive(bool isTeamActive)
{
    this->isTeamActive=isTeamActive;
}
void Player::setGamesTeamPlayedBefore(int gamesTeamPlayedBefore)
{
    this->gamesTeamPlayedBefore=gamesTeamPlayedBefore;
}
void Player::setGamesFromRootPlayer(int gamesFromRootPlayer)
{
    this->gamesFromRootPlayer=gamesFromRootPlayer;
}
