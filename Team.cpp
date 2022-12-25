#include "Team.h"
Team::Team(int otherTeamID)
{
    this->teamID=otherTeamID;
}

Team::~Team()=default;

int Team::getTeamID()
{
    return this->teamID;
}
int Team::getNumOfPlayers()
{
    return this->numOfPlayers;
}
int Team::getNumOfGoalKeepers()
{
    return this->numOfGoalKeepers;
}
int Team::getFirstPlayerID()
{
    return this->FirstPlayerID;
}
int Team::getPoints()
{
    return this->points;
}
int Team::getSumPlayersAbility()
{
    return this->sumPlayersAbility;
}
int Team::getGamesPlayed()
{
    return this->gamesPlayed;
}
void Team::setPoints(int points)
{
    this->points=points;
}
void Team::addPlayerAbility(int playerAbility)
{
    this->sumPlayersAbility+=playerAbility;
}
void Team::setGamesPlayed(int gamesPlayed)
{
    this->gamesPlayed=gamesPlayed;
}
void Team::increaseNumOfPlayers()
{
    this->numOfPlayers++;
}
void Team::increaseNumOfGoalKeepers()
{
    this->numOfGoalKeepers++;
}
void Team::setFirstPlayerID(int FirstPlayerID)
{
    this->FirstPlayerID=FirstPlayerID;
}
void Team::multiplyNewPlayerToTeamSpirit(permutation_t newPlayerSpirit)
{
    if (this->numOfPlayers==0)
    {
        this->teamSpirit=newPlayerSpirit;
    }
    else
    {
        this->teamSpirit=this->teamSpirit*newPlayerSpirit;
    }
    this->teamStrength=this->teamSpirit.strength();
}
permutation_t Team::getTeamSpirit()
{
    return this->teamSpirit;
}
int Team::getTeamStrength()
{
    return this->teamStrength;
}
