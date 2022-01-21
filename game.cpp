#include "game.h"

using namespace std;

Game :: Game()
{
    playersPerTeam = 8;
    maxBalls = 12;
    totalPlayers = 20;

    players[0]="K L Rahul";
    players[1]="S Dhawan";
    players[2]="R Sharma";
    players[3]="V Kohli";
    players[4]="M S Dhoni";
    players[5]="Hardik";
    players[6]="Jadeja";
    players[7]="K Yadav";
    players[8]="B Kumar";
    players[9]="Bumrah";
    players[10]="M Shami";
    players[11]="D Padikal";
    players[12]="S Yadav";
    players[13]="S Tiwari";
    players[14]="S Samson";
    players[15]="N Rana";
    players[16]="S Gill";
    players[17]="M Agarwal";
    players[18]="A B D";
    players[19]="M Ali";

    teamA.name = "Team-A";
    teamB.name = "Team-B";

}

void Game :: welcomeUser()
{
    cout<<" \t - - - - - - - - - - - - - - -"<<endl;
    cout<<"\t| =========CRIC-IN==========  |"<<endl;
    cout<<"\t| Welcome to Virtual-Cricket  |"<<endl;
    cout<<"\t| _ _ _ _ _ _ _ _ _ _ _ _ _ _ |"<<endl;
    cout<<"\t"<<endl;

    cout<<"\n\tPress Enter to Continue...."<<endl;
    getchar();
}

void Game :: showAllPlayers()
{
    cout<<"\t- - - - - - - - - - - - - - -"<<endl;
    cout<<"\t|= = = Pool-of-Players = = = |"<<endl;
    cout<<"\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<"\n"<<endl<<endl;

    usleep(1000000);

    for(int i=0; i<totalPlayers; i++)
    {
        cout<<"\t ["<<i<<"] "<<players[i]<<endl;
        usleep(100000);
    }
}

int Game :: takeIntegerInput()
{
    int n;
    while(!(cin>>n))
    {
         cout<<"\n\tInvalid Input. Try again with valid Input: ";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max() ,'\n');
    }
    return n;
}

void Game :: selectPlayers()
{
    cout<<"\n\tPress Enter to Continue...."<<endl;
    getchar();

    cout<<"\n\t---------------------------------------"<<endl;
    cout<<"\t|======= Create TeamA and TeamB ======|"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;
    usleep(1000000);

    for(int i=0; i<playersPerTeam; i++)
    {
        teamAselection:
        cout<<endl<<"\tSelect Player "<<i+1<<" of Team A - ";
        int playerIndexTeamA = takeIntegerInput();
        if(playerIndexTeamA<0 || playerIndexTeamA>20)
        {
            cout<<"\n\tPlease Enter from given index"<<endl;
            goto teamAselection;
        }else if(!validateSelectPlayers(playerIndexTeamA))
        {
            cout<<"\n\tPlayer has been already selected.Please select other Players."<<endl;
            goto teamAselection;
        }else
        {
            Player teamAplayer;
            teamAplayer.id = playerIndexTeamA;
            teamAplayer.name = players[playerIndexTeamA];
            teamA.players.push_back(teamAplayer);
        }

          teamBselection:
          cout<<endl<<"\tSelect Player "<<i+1<<" of Team B - ";
          int playerIndexTeamB = takeIntegerInput();
          if(playerIndexTeamB<0 || playerIndexTeamB>20)
          {
              cout<<"\n\tPlease Enter from given index"<<endl;
              goto teamBselection;
          }else if(!validateSelectPlayers(playerIndexTeamB))
          {
              cout<<"\n\tPlayer has been already selected.Please select other Players."<<endl;;
              goto teamBselection;
          }else
          {
              Player teamBplayer;
              teamBplayer.id = playerIndexTeamB;
              teamBplayer.name = players[playerIndexTeamB];
              teamB.players.push_back(teamBplayer);
          }
      }
}

bool Game :: validateSelectPlayers(int index)
{
    int n;
    vector<Player>players;
    players = teamA.players;
    n = players.size();

    for(int i=0; i<n; i++)
    {
        if(players[i].id == index)
        {
            return false;
        }
    }

    players = teamB.players;
    n = players.size();

        for(int i=0; i<n; i++)
       {
           if(players[i].id == index)
           {
            return false;
           }
       }
    return true;
}

void Game :: showTeamPlayers()
{
    vector<Player>teamAplayers = teamA.players;
    vector<Player>teamBplayers = teamB.players;

    int n;
    n=teamAplayers.size();
    cout<<endl<<endl;

    cout<<" \t TeamA \t\t\t\t\t\t\t TeamB"<<endl;
    cout<<" \t ----- \t\t\t\t\t\t\t -----"<<endl;
    for(int i=0; i<n; i++)
    {
         cout<<" \t "<<"["<<i<<"]"<<teamAplayers[i].name<<" \t\t\t"<<"||"
        <<"\t\t"
        <<" \t "<<"["<<i<<"]"<<teamBplayers[i].name<<"  \t"<<endl;
        usleep(1000);
    }
}

int Game :: toss()
{
    cout<<"\n\tPress Enter for toss..."<<endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

     cout<<"\n\n\t|----------------------------|"<<endl;
    cout<<"\t|\tLet's Toss\t     |"<<endl;
    cout<<"\t|----------------------------|"<<endl<<endl;

    cout<<"\tTossing the coin......"<<endl<<endl;
    usleep(1000000);

    srand(time(NULL));
    int q = rand()%2;

    switch(q)
    {
    case 0:
        cout<<"\tTeam-A WON THE TOSS...."<<endl;
        tossChoice(teamA);
        break;
    case 1:
        cout<<"\tTeam-B WON THE TOSS...."<<endl;
        tossChoice(teamB);
        break;
    }
}

void Game :: tossChoice(Team tossWinnerTeam)
{
    cout<<"\n\n\tEnter 1 for bat or 2 to bowl first...."<<endl;
    cout<<"\t1.Bat\n\t2.Bowl"<<endl;

    int tossInput = takeIntegerInput();
    cin.ignore(numeric_limits<streamsize>::max() ,'\n');

    switch(tossInput)
    {
    case 1:
    {
        cout<<"\n\t"<<tossWinnerTeam.name<<" won the toss and elected to bat first."<<endl;
        if(tossWinnerTeam.name == teamA.name)
        {
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }else
        {
            bowlingTeam = &teamA;
            battingTeam = &teamB;
        }
        break;
    }
    case 2:
    {
        cout<<"\n\t"<<tossWinnerTeam.name<<" won the toss and elected to bowl first."<<endl;
        if(tossWinnerTeam.name == teamA.name)
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }else
        {
            bowlingTeam = &teamB;
            battingTeam = &teamA;
        }
        break;
    }
    default:
    {
        cout<<"\n\tInvalid Input."<<endl;
        tossChoice(tossWinnerTeam);
        break;
    }

  }
}


void Game :: startFirstInnings()
{
    usleep(1000000);
    bool isFirstInnings = true;
    this->isFirstInnings = isFirstInnings;
    cout<<"\n\t\t||| FIRST INNINGS |||"<<endl;
    initializePlayers();
    playInnings();
}

void Game :: initializePlayers()
{
    batsmanFirst = &battingTeam->players[0];
    batsmanSecond = &battingTeam->players[1];
    bowler = &bowlingTeam->players[0];

    usleep(1000000);

    cout<<"\n\t"<<battingTeam->name<<" - "<<batsmanFirst->name<<" is on strike."<<endl;
    usleep(100000);
    cout<<"\n\t"<<battingTeam->name<<" - "<<batsmanSecond->name<<" is on Non-Strike."<<endl;
    usleep(100000);
    cout<<"\n\t"<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling."<<endl;
    usleep(100000);
}

void Game :: playInnings()
{
    batsmanFirst->runsScored = 0;
    batsmanFirst->ballsPlayed = 0;
    int r=0;

    for(int i=0; i<maxBalls; i++)
    {
        r=r+1;
    cout<<"\n\tPress Enter to ball.."<<r<<" :"<<endl;
    getchar();
    cout<<"\n\tBowling..."<<endl;
    usleep(1000000);
    bat();
    if(!(validateInningsScore()))
    {
        break;
    }
    }
}

void Game :: bat()
{
    srand(time(NULL));
    int runsScored = e[rand() % 7];

     batsmanFirst->ballsPlayed = batsmanFirst->ballsPlayed + 1;

     battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;

     bowler->ballsBowled = bowler->ballsBowled + 1;
     bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
     bowler->runsGiven= bowler->runsGiven + runsScored;


    if(!(runsScored==0))
    {
        cout<<endl<<"\t"<<bowler->name<<" to "<<batsmanFirst->name<<" "<<runsScored<<" runs!"<<endl<<endl;
        usleep(1000000);
        if(runsScored == 1)
        {
            batsmanFirst->runsScored =  batsmanFirst->runsScored + runsScored;
            batsmanFirst->runsScored = batsmanFirst->runsScored;
            batsmanSecond->runsScored = batsmanSecond->runsScored;

            usleep(100000);
            showScoreCard();

            usleep(100000);

            swap(batsmanFirst,batsmanSecond);

            if(bowlingTeam->totalBallsBowled == 6)
                {
                    swap(batsmanFirst,batsmanSecond);
                }

            batsmanFirst->runsScored = batsmanFirst->runsScored;
            batsmanSecond->runsScored = batsmanSecond->runsScored;

        }else if(runsScored == 3)
        {
            batsmanFirst->runsScored =  batsmanFirst->runsScored + runsScored;
            batsmanFirst->runsScored = batsmanFirst->runsScored;
            batsmanSecond->runsScored = batsmanSecond->runsScored;

            usleep(100000);
            showScoreCard();

            usleep(100000);

            swap(batsmanFirst,batsmanSecond);

            if(bowlingTeam->totalBallsBowled == 6)
                {
                    swap(batsmanFirst,batsmanSecond);
                }

            batsmanFirst->runsScored = batsmanFirst->runsScored;
            batsmanSecond->runsScored = batsmanSecond->runsScored;


        }else if(runsScored == 2)
        {
            batsmanFirst->runsScored =  batsmanFirst->runsScored + runsScored;
            batsmanFirst->runsScored = batsmanFirst->runsScored;
            batsmanSecond->runsScored = batsmanSecond->runsScored;
            showScoreCard();
            if(bowlingTeam->totalBallsBowled == 6)
                {
                    swap(batsmanFirst,batsmanSecond);
                }

        }else if(runsScored == 4 )
        {
            batsmanFirst->runsScored =  batsmanFirst->runsScored + runsScored;
            batsmanFirst->runsScored = batsmanFirst->runsScored;
            batsmanSecond->runsScored = batsmanSecond->runsScored;
            showScoreCard();
            if(bowlingTeam->totalBallsBowled == 6)
                {
                    swap(batsmanFirst,batsmanSecond);
                }

        }else if(runsScored == 6)
        {
             batsmanFirst->runsScored =  batsmanFirst->runsScored + runsScored;
             batsmanFirst->runsScored = batsmanFirst->runsScored;
             batsmanSecond->runsScored = batsmanSecond->runsScored;
            showScoreCard();
            if(bowlingTeam->totalBallsBowled == 6)
                {
                    swap(batsmanFirst,batsmanSecond);
                }

        }
    }else
    {
        cout<<endl<<"\t"<<bowler->name<<" to "<<batsmanFirst->name<<" "<<" OUT!"<<endl<<endl;
        usleep(1000000);
        battingTeam->totalWicketsLost = battingTeam->totalWicketsLost +1;
        bowler->wicketsTaken = bowler->wicketsTaken +1;
        batsmanFirst->runsScored =  batsmanFirst->runsScored + runsScored;
        batsmanSecond->runsScored =  batsmanSecond->runsScored + runsScored;

        showScoreCard();

        int newIndex = battingTeam->totalWicketsLost + 1;
        batsmanFirst = &battingTeam->players[newIndex];

        if(bowlingTeam->totalBallsBowled == 6)
        {
            swap(batsmanFirst,batsmanSecond);
        }

        batsmanFirst->ballsPlayed = 0;
        batsmanFirst->runsScored = 0;
    }
}

void Game :: overStrikeChange()
{
      if(bowlingTeam->totalBallsBowled == 6)
      {
            usleep(1000000);
            cout<<"\n\t ||| Over End |||\t"<<endl;
            usleep(1000000);
            cout<<"\n\t Changing Bowler "<<endl;
            usleep(1000000);
            bowler = &bowlingTeam->players[1];

    }

}

void Game :: showScoreCard()
{
    cout<<"\n\t-------------------------"<<endl;
    cout<<"\t"<<battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") |"<<" "<<batsmanFirst->name<<" "<<batsmanFirst->runsScored<<" ("<<batsmanFirst->ballsPlayed<<") \t"<<batsmanSecond->name<<" "<<batsmanSecond->runsScored<<" ("<<batsmanSecond->ballsPlayed<<") \t"<<bowler->name<<" "<<bowler->ballsBowled<<"-"<<bowler->runsGiven<<"-"<<bowler->wicketsTaken<<endl;
    cout<<"\n\t-------------------------"<<endl;

    overStrikeChange();
}

bool Game :: validateInningsScore()
{
    if(isFirstInnings)
    {
        if(battingTeam->totalWicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls )
        {
            usleep(1000000);
            cout<<"\n\n\t\t||| FIRST INNINGS ENDS |||"<<endl;
            usleep(1000000);
            cout<<"\n\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") "<<endl;
            usleep(1000000);
            cout<<"\t"<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored +1 <<" runs to win the match"<<endl<<endl;

            return false;
        }
    }else
    {
       if(battingTeam->totalWicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls || (battingTeam->totalRunsScored) > (bowlingTeam->totalRunsScored))
        {
            usleep(1000000);
            return false;
        }
    }
    return true;

}

void Game :: secondInnings()
{
    isFirstInnings = false;
    usleep(1000000);
    cout<<"\n\n\t\t||| SECOND INNINGS START |||"<<endl;
    swap(battingTeam,bowlingTeam);
    initializePlayers();
    playInnings();
    winner();
    matchSummary();
}

void Game :: winner()
{
    if((battingTeam->totalRunsScored) > (bowlingTeam->totalRunsScored))
    {
        usleep(1000000);
        cout<<"\n\t"<<battingTeam->name<<" WON THE MATCH"<<endl;
        cout<<"\n\n\t\t||| MATCH ENDS |||"<<endl;
        usleep(1000000);
    }
    else
    {
        usleep(1000000);
        cout<<"\n\t"<<bowlingTeam->name<<" WON THE MATCH"<<endl;
        cout<<"\n\n\t\t||| MATCH ENDS |||"<<endl;
        usleep(1000000);
    }
}

void Game::matchSummary()
{
    cout<<"\n\tPress Enter to see Summary..."<<endl;
    getchar();

    if((battingTeam->totalRunsScored) > (bowlingTeam->totalRunsScored))
    {
        cout<<"\n\t\t"<<battingTeam->name<<" - "<<battingTeam->totalRunsScored<<"-"<<battingTeam->totalWicketsLost<<" ("<<battingTeam->totalBallsBowled<<") "<<"\t\t\t\t"

        <<bowlingTeam->name<<" - "<<bowlingTeam->totalRunsScored<<"-"<<bowlingTeam->totalWicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") "<<endl;

        for(int i=0; i<playersPerTeam; i++)
        {
            cout<<"\n\t"<<battingTeam->players[i].name<<"||\t"<<battingTeam->players[i].runsScored<<" ("<<battingTeam->players[i].ballsPlayed<<") \t||\t"<<battingTeam->players[i].ballsBowled<<"-"<<battingTeam->players[i].runsGiven<<"-"<<battingTeam->players[i].wicketsTaken<<"\t\t"

            <<bowlingTeam->players[i].name<<"||\t"<<bowlingTeam->players[i].runsScored<<" ("<<bowlingTeam->players[i].ballsPlayed<<") \t||\t"<<bowlingTeam->players[i].ballsBowled<<"-"<<bowlingTeam->players[i].runsGiven<<"-"<<bowlingTeam->players[i].wicketsTaken<<endl;

        }

    }
    else
    {
        cout<<"\n\t\t"<<bowlingTeam->name<<" - "<<bowlingTeam->totalRunsScored<<"-"<<bowlingTeam->totalWicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") "<<"\t\t\t\t"

        <<battingTeam->name<<" - "<<battingTeam->totalRunsScored<<"-"<<battingTeam->totalWicketsLost<<" ("<<battingTeam->totalBallsBowled<<") "<<endl;

        for(int i=0; i<playersPerTeam; i++)
        {
            cout<<"\n\t"<<bowlingTeam->players[i].name<<"||\t"<<bowlingTeam->players[i].runsScored<<" ("<<bowlingTeam->players[i].ballsPlayed<<") \t||\t"<<bowlingTeam->players[i].ballsBowled<<"-"<<bowlingTeam->players[i].runsGiven<<"-"<<bowlingTeam->players[i].wicketsTaken<<"\t\t"

            <<battingTeam->players[i].name<<"||\t"<<battingTeam->players[i].runsScored<<" ("<<battingTeam->players[i].ballsPlayed<<") \t||\t"<<battingTeam->players[i].ballsBowled<<"-"<<battingTeam->players[i].runsGiven<<"-"<<battingTeam->players[i].wicketsTaken<<endl;

        }
    }
    getchar();
}
