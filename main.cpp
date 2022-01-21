#include "game.h"

using namespace std;

int main()
{
    Game game;

    game.welcomeUser();
    game.showAllPlayers();
    game.selectPlayers();
    game.showTeamPlayers();
    game.toss();
    game.startFirstInnings();
    game.secondInnings();
}
