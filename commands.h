//
// Created by Jorge on 07/10/2020.
//

#ifndef UNTITLED_Commands_H
#define UNTITLED_Commands_H

/**********************************************************/
#include "statsvalues.h"
#include "entities.h"
using namespace std;

/**********************************************************/

string commandarray[] = {"help", "health", "energy", "attack", "stats", ""};
int command_int_saved = 99;

class Commands
        {
        public:
            void checkcommand();    //recognises introduced command
            void executecommand(); //uses one of all  
            void executehelp();
            void executehealth();
            void executeenergy();
            void executeattack();
            void executestats();
            void executenull();
        };

void Commands::checkcommand()
{
    for (int i = 0; i < 6; i++)
    {
        cout << commandarray[i] << endl;
    }
    char command [40];
    cin >> command;
    string Commandstr;
    Commandstr = command;
    for (int i = 0; i < 6; i++)
    {
        if(Commandstr == commandarray[i]){command_int_saved = i;}
    }
}

void Commands::executehelp()
{
    cout << "Commands: " << endl;
    cout << "See health: health" << endl;
    cout << "See energy: energy" << endl;
    cout << "See attack: attack" << endl;
    cout << "See stats: stats" << endl;
}
void Commands::executehealth()
{
    cout << "Health: " << player_stats.gethealth() <<"/" << player_stats.gethealth() << "\nMood: " << player_stats.getmood() << " (" << player_stats.getmood() << ")"<< endl;
}
void Commands::executeenergy()
{
    cout << "Hmm... \nYou have " << player_stats.getenergy() << " of magic energy" << endl;
}
void Commands::executeattack()
{
    cout << "Attack: "<< player_stats.getattack() << "/" << player_stats.getattack() << endl;
}
void Commands::executestats()
{
    cout << "---------Stats---------" << endl;
    executehealth();
    executeenergy();
    executeattack();
}
void Commands::executenull()
{
    cout << "This command does nothing" << endl;
}

void Commands::executecommand()
{
    switch (command_int_saved)
    {   //compares command introduced with its int and executes it
        case 0:
            cout<<"You have chosen command_help"<<endl;
            executehelp();
            break;
        case 1:
            cout<<"You have chosen command_health"<<endl;
            executehealth();
            break;
        case 2:
            cout<<"You have chosen command_energy"<<endl;
            executeenergy();
            break;
        case 3:
            cout<<"You have chosen command_attack"<<endl;
            executeattack();
            break;
        case 4:
            cout<<"You have chosen command_stats"<<endl;
            executestats();
            break;
        case 5:
            cout<<"You have chosen command_null"<<endl;
            executenull();
            break;
        default:
            cout<<"Wrong command"<<endl;
    }
}
//
#endif //UNTITLED_Commands_H
