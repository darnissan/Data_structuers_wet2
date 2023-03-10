#ifndef PLAYER_H_
#define PLAYER_H_
#include "wet2util.h"
#include "ReversedTree.h"

class Player
{
private:
    int playerID;
    int playerTeamID;
    int playerAbility;
    int playerCards;
    int gamesPlayedINIT;
    int gamesTeamPlayedBefore;
    int gamesFromRootPlayer = 0;
    bool isGoalKeeper;
    bool isTeamActive = true;
    bool isRootPlayer = false;
    ReversedTreeNode<Player> *playerReversedTreeNode = nullptr;
    permutation_t playerSpirit;
    permutation_t spiritsBeforeMe=permutation_t().neutral();
    permutation_t SpiritFromRootPlayer=permutation_t().neutral();
    permutation_t WholeTeamSpiritSoFar=permutation_t().neutral();

public:
    Player(int playerID) : playerID(playerID){};
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
    bool operator==(const Player &player) const;
    bool operator!=(const Player &player) const;

    void setPlayerReversedTreeNode(ReversedTreeNode<Player> *playerReversedTreeNode);
    ReversedTreeNode<Player> *getPlayerReversedTreeNode();
    void setSpiritsBeforeMe(permutation_t spiritsBeforeMe);
    permutation_t getSpiritsBeforeMe();
    void setlSpiritFromRootPlayer(permutation_t SpiritFromRootPlayer);
    permutation_t getSpiritFromRootPlayer();
    void setTeamUnActive();

    void setPlayerAbility(int playerAbility);
    void setPlayerCards(int playerCards);
    void setPlayerSpirit(permutation_t playerSpirit);
    void setGamesPlayedINIT(int gamesPlayedINIT);
    void setWholeTeamSpiritSoFar(permutation_t WholeTeamSpiritSoFar);
    permutation_t getWholeTeamSpiritSoFar();
    void deletePlayerReversedTreeNode();
    void multiplayPlayerSpiritToWholeTeamSpiritSoFar(permutation_t playerSpirit);
};
#endif // PLAYER_H_