#include "TeamAndAbilities.h" 

TeamAndAbilities:: TeamAndAbilities(int teamID, int sumPlayersAbility)
{
    this->teamID=teamID;
    this->sumPlayersAbility=sumPlayersAbility;
}
TeamAndAbilities::~TeamAndAbilities()=default;
int TeamAndAbilities::getTeamID()
{
    return this->teamID;
}
int TeamAndAbilities::getSumPlayersAbility()
{
    return this->sumPlayersAbility;
}
bool TeamAndAbilities::operator ==(const TeamAndAbilities& team) const
{
    return this->teamID==team.teamID;
}
bool TeamAndAbilities::operator >(const TeamAndAbilities& team) const
{
    if (this->sumPlayersAbility==team.sumPlayersAbility)
    {
        return this->teamID>team.teamID;
    }
    return this->sumPlayersAbility>team.sumPlayersAbility;
}
bool TeamAndAbilities::operator <(const TeamAndAbilities& team) const
{
    if (this->sumPlayersAbility==team.sumPlayersAbility)
    {
        return this->teamID<team.teamID;
    }
    return this->sumPlayersAbility<team.sumPlayersAbility;
}

