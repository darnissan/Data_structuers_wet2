#ifndef TEAM_H_
#define TEAM_H_
#include "wet2util.h"
#include "ReversedTree.h"
#include "Player.h"
class Team
{
private:
    int teamID;
    int numOfPlayers=0;
    int numOfGoalKeepers=0;
    int FirstPlayerID;
    int points=0;
    int sumPlayersAbility=0;
    int gamesPlayed=0;
    //permutation_t teamSpirit=permutation_t().neutral();
    int teamStrength;
    ReversedTreeNode<Player> *teamReversedTreeRoot=nullptr;
public:
    Team(int teamID);
    ~Team();
    int getTeamID();
    int getNumOfPlayers();
    int getNumOfGoalKeepers();
    int getFirstPlayerID();
    int getPoints();
    int getSumPlayersAbility();
    int getGamesPlayed();
    void setPoints(int points);
    void addPlayerAbility(int playerAbility);
    void setGamesPlayed(int gamesPlayed);
    void increaseNumOfPlayers();
    void increaseNumOfGoalKeepers();
    void setFirstPlayerID(int FirstPlayerID);
    //void multiplyNewPlayerToTeamSpirit(permutation_t newPlayerSpirit);
    //permutation_t getTeamSpirit();
    int getTeamStrength();
    bool operator ==(const Team& team);
    bool operator >(const Team& team);
    bool operator <(const Team& team);
    void setTeamReversedTreeRoot(ReversedTreeNode<Player> *teamReversedTreeRoot);
    ReversedTreeNode<Player> *getTeamReversedTreeRoot();
    void setReversedTreeRootTeamUnActive();
    void addPoints(int points);
    void addnumOfPlayers(int numOfPlayers);
    void addnumOfGoalKeepers(int numOfGoalKeepers);
    void addSumPlayersAbility(int sumPlayersAbility);

};


#endif // TEAM_H_
