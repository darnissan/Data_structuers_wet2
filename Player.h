#ifndef PLAYER_H_
#define PLAYER_H_
#include "wet2util.h"

class Player
{
private:
    int playerID;
    int playerTeamID;
    int playerAbility;
    int playerCards;
    int gamesPlayedINIT;
    int gamesTeamPlayedBefore;
    int gamesFromRootPlayer;
    bool isGoalKeeper;
    bool isTeamActive = true;
    bool isRootPlayer = false;
    permutation_t playerSpirit;
    

public:
    Player(int playerID, int teamId, const permutation_t &spirit, int gamesPlayed, int ability, int cards, bool goalKeeper);
    ~Player();
    int getPlayerID();
    int getPlayerAbility();
    int getPlayerTeamID();
    permutation_t getPlayerSpirit();
    int getPlayerCards();
    void addCards(int newCards);
    void setPlayerTeamID(int newTeamID);
    int getGamesPlayedINIT();
    int getGamesTeamPlayedBefore();
    int getGamesFromRootPlayer();
    bool getIsGoalKeeper();
    bool getIsTeamActive();
    bool getIsRootPlayer();
    void setIsRootPlayer(bool isRootPlayer);
    void setIsTeamActive(bool isTeamActive);
    void setGamesTeamPlayedBefore(int gamesTeamPlayedBefore);
    void setGamesFromRootPlayer(int gamesFromRootPlayer);
};
#endif // PLAYER_H_