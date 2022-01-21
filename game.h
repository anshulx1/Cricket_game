#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "team.h"
#include<iostream>
#include<unistd.h>
#include<limits>
#include<cstdlib>
#include<ctime>

class Game
{
public:
    Game();
    Team teamA,teamB;
    int playersPerTeam;
    int maxBalls;
    int totalPlayers;
    std::string players[20];
    bool isFirstInnings;
    int e[7] = {0,1,2,3,4,6};
    int runsScored = 0;
    Team *battingTeam, *bowlingTeam;
    Player *batsmanFirst, *batsmanSecond, *bowler;

    void welcomeUser();
    void showAllPlayers();
    void selectPlayers();
    int takeIntegerInput();
    bool validateSelectPlayers(int);
    void showTeamPlayers();
    int toss();
    void tossChoice(Team);
    void startFirstInnings();
    void initializePlayers();
    void playInnings();
    void bat();
    void showScoreCard();
    bool validateInningsScore();
    void secondInnings();
    void winner();
    void matchSummary();
    void strkieChange();
    void overStrikeChange();
};



#endif // GAME_H_INCLUDED
