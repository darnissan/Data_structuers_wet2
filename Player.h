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
    int gamesFromRootPlayer;
    bool isGoalKeeper;
    bool isTeamActive = true;
    bool isRootPlayer = false;
    permutation_t playerSpirit;
    ReversedTreeNode<Player> *playerReversedTreeNode=nullptr;
    permutation_t spiritsBeforeMe;
    permutation_t SpiritFromRootPlayer;
public:
    Player(int playerID):playerID(playerID){};
    Player(int playerID, int teamId, const permutation_t &spirit, int gamesPlayed, int ability, int cards, bool goalKeeper);
    ~Player();
    int getPlayerID();
    int getPlayerAbility();
    int getPlayerTeamID();
    permutation_t getPlayerSpirit();
    int getPlayerCards() const; 
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
    bool operator ==(const Player& player) const;
    bool operator !=(const Player& player) const;
    
    void setPlayerReversedTreeNode(ReversedTreeNode<Player> *playerReversedTreeNode);
    ReversedTreeNode<Player> *getPlayerReversedTreeNode();
    void setSpiritsBeforeMe(permutation_t spiritsBeforeMe);
    permutation_t getSpiritsBeforeMe();
    void setlSpiritFromRootPlayer(permutation_t SpiritFromRootPlayer);
    permutation_t getSpiritFromRootPlayer();
    
};
#endif // PLAYER_H_