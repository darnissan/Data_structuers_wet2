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