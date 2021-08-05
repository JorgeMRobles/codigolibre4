//
// Created by Jorge on 07/10/2020.
//

#ifndef UNTITLED_Battle_H
#define UNTITLED_Battle_H

/**********************************************************/
#include "commands.h"
#include "othermethods.h"
#include "statsvalues.h"
#include "entities.h"
using namespace std;

/**********************************************************/
//battle system
class MotherBattle
{
protected:
        int turn = 0;
        bool enemyturn = true;
        string enemyname = basicenemy.setname();
        int enemyatk = basicenemy.setforce();
        int enemyhealth_beginning = basicenemy.sethealth();
        int enemyhealth = basicenemy.sethealth();
        int enemyenergy = basicenemy.setpower();

        int playeratk = player_stats.getattack();
        int healthplayer_beginning = player_stats.gethealth();
        int healthplayer = player_stats.gethealth();
        int playerenergy = player_stats.getenergy();
public:
        void showtext();
        void attack();
        void manejandoturn();
};

void MotherBattle::showtext()
{
    cout << "You have entered on a battle \nGet ready!\n" << endl;
    cin.ignore();
    cout << "You confronted to a " << enemyname << ", a enemy with health " << enemyhealth << ", attack " << enemyatk << " and energy " << enemyenergy << endl;
    cin.ignore();
}

void MotherBattle::attack() {   //automatic, while enemyhealth>0 and player is alive
    while (enemyhealth>0 && healthplayer>0){
        manejandoturn();   //turn of who and what happens in each one
    }
    if (enemyhealth <= 0) { //go out of the battle
        enemyhealth = 0;
        cout << enemyname << " defeated!" << endl;
        cin.ignore();
        cout << "Health of " << enemyname << ": " << enemyhealth << "/" << enemyhealth_beginning << endl;
        cin.ignore();
        cout << "Player's health: " << healthplayer << "/" << healthplayer_beginning << endl;
        cin.ignore();
        cout << "End of the battle" << endl;
        cin.ignore();
        cout << "Now you'll be healed, exhausted magician" <<endl;
        cin.ignore();
        healthplayer = healthplayer_beginning;
        cout << "Player's health: " << healthplayer << "\n" << endl;
        cin.ignore();
    }
    if (healthplayer <= 0) { //game over
        cout << "The " << enemyname << " had done a fatale hit and you have died" << endl;
        cin.ignore();
        cout << "Health of " << enemyname << ": " << enemyhealth << "/" << enemyhealth_beginning << endl;
        cin.ignore();
        om.deadplayer();
    }
}

void MotherBattle::manejandoturn()
{
    turn++;
    cout << "Turn " << turn << endl;
    if (enemyturn == true)
    {
        cout << "Turn of " << enemyname << endl;
        cin.ignore();
        cout << "The " << enemyname << " attacks with all his power" << endl;
        healthplayer = healthplayer - (enemyatk + enemyenergy);
        if (healthplayer <= 0) {healthplayer= 0;}
        cout << "Player's health: " << healthplayer << endl;
        cin.ignore();
        enemyenergy = enemyenergy - 1;
        if (healthplayer > 0 && enemyhealth > 0){enemyturn = false;}
    }
    if (turn>1 && healthplayer>0)
    { //player doesn't attack if dies on first turn
        if (enemyturn == false)
        {
            cout << "Player's turn" << endl;
            cin.ignore();
            cout << "Player attacks with all of his power" << endl;
            cin.ignore();
            enemyhealth = enemyhealth - (playeratk + playerenergy);
            if (enemyhealth <= 0) {enemyhealth = 0;}
            cout << "Actual enemy's health: " << enemyhealth << endl;
            cin.ignore();
            playerenergy = playerenergy - 5;
            if (enemyhealth > 0 && healthplayer > 0){enemyturn = true;}
        }
    }
    if (enemyenergy <= 0 && enemyturn && healthplayer > 0 && enemyhealth>0)
    {
        enemyenergy = 0;
        cout << "Enemy's turn used by " << enemyname << endl;
        cin.ignore();
        cout << "The " << enemyname << " attacks" << endl;
        cin.ignore();
        healthplayer = healthplayer - enemyatk;
        if (healthplayer <= 0) {healthplayer= 0;}
        cout << "Actual player's health: " << healthplayer << endl;
        cin.ignore();
        enemyturn = false;
    }
    if (playerenergy <= 0 && enemyturn == false && healthplayer > 0 && enemyhealth > 0)
    {
        playerenergy = 0;
        cout << "Player's turn" << endl;
        cin.ignore();
        cout << "The player attacks" << endl;
        cin.ignore();
        enemyhealth = enemyhealth - playeratk;
        if (enemyhealth <= 0) {enemyhealth = 0;}
        cout << "Actual health of " << enemyname << ": " << enemyhealth << endl;
        cin.ignore();
        enemyturn = true;
    }
}

//battle with basic enemy
class battle : public MotherBattle
{    
};

//battle with werewolf
class battle2 : public MotherBattle
 {
 public:
     void changevalues();
     int changevalue_turn();
     bool changevalue_enemyturn();
     int changevalue_enemyatk();
     int changevalue_enemyhealth_beginning();
     int changevalue_enemyhealth();
     int changevalue_enemyenergy();
     string changevalue_name();
};

void battle2::changevalues()
{
    turn = changevalue_turn();
    enemyturn = changevalue_enemyturn();
    enemyatk = changevalue_enemyatk();
    enemyhealth_beginning = changevalue_enemyhealth_beginning();
    enemyhealth = changevalue_enemyhealth();
    enemyenergy = changevalue_enemyenergy();
    enemyname = changevalue_name();
}

int battle2::changevalue_turn()
{
    turn = 0;
    return turn;
}
bool battle2::changevalue_enemyturn()
{
    enemyturn = true; 
    return enemyturn;
}
int battle2::changevalue_enemyatk()
{
    enemyatk = werewolf.setforce(); 
    return enemyatk;
}
int battle2::changevalue_enemyhealth_beginning()
{
    enemyhealth_beginning = werewolf.sethealth(); 
    return enemyhealth_beginning;
}
int battle2::changevalue_enemyhealth()
{
    enemyhealth = werewolf.sethealth(); 
    return enemyhealth;
}
int battle2::changevalue_enemyenergy() 
{
    enemyenergy = werewolf.setpower(); 
    return enemyenergy;
}
string battle2::changevalue_name()
{
    enemyname = werewolf.setname(); 
    return enemyname;
}
#endif //UNTITLED_battle_H
