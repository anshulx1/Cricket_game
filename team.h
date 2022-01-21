#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "player.h"
#include<vector>

class Team
{
public:
    Team();
    std::string name;
    int totalRunsScored;
    int totalWicketsLost;
    int totalBallsBowled;
    int totalwicketsTaken ;
    std :: vector<Player> players;
};


#endif // TEAM_H_INCLUDED
