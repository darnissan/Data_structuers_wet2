#ifndef TEAM_AND_ABILITIES_H_
#define TEAM_AND_ABILITIES_H_

#include "wet2util.h"
#include "RankTree.h"

class TeamAndAbilities
{
    private:
    int teamID;
    int sumPlayersAbility=0;
    


    public:
    TeamAndAbilities(int teamID, int sumPlayersAbility);
    ~TeamAndAbilities();
    int getTeamID();
    int getSumPlayersAbility();
    bool operator ==(const TeamAndAbilities& team)const;
    bool operator >(const TeamAndAbilities& team)const;
    bool operator <(const TeamAndAbilities& team)const;
    friend std::ostream &operator<<(std::ostream &os, const TeamAndAbilities &team)
    {
        os << team.teamID << "," << team.sumPlayersAbility;
        return os;
    }
};

#endif // TEAM_AND_ABILITIES_H_
