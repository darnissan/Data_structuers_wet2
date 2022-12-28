#ifndef TEAM_AND_ABILITIES_H_
#define TEAM_AND_ABILITIES_H_

#include "wet2util.h"
#include "AvlTree.h"

class TeamAndAbilities
{
    private:
    int teamID;
    int sumPlayersAbility;
    RankTree<TeamAndAbilities> teamsAbilitiesRankTree;


    public:
    TeamAndAbilities(int teamID, int sumPlayersAbility);
    ~TeamAndAbilities();
    int getTeamID();
    int getSumPlayersAbility();
    bool operator ==(const TeamAndAbilities& team);
    bool operator >(const TeamAndAbilities& team);
    bool operator <(const TeamAndAbilities& team);
};
#endif // TEAM_AND_ABILITIES_H_
