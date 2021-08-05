//
// Created by Jorge on 08/10/2020.
//

#ifndef UNTITLED_GIVEN_H
#define UNTITLED_GIVEN_H

/**********************************************************/
#include <iostream>
#include "entities.h"
#include "othermethods.h"
using namespace std;

/**********************************************************/
Objects object1("levelup", "Up all stats");
class Manageobjects
{
public:
    void manageobject(); //principal method
    void islevelup();
    void consumelevelup();
    char consumicion;
    int quantity;
    };
void Manageobjects::manageobject() 
{
    object1.changequantity(0);
    quantity = object1.getquantity();
    islevelup();
    object1.changequantity(1);
    quantity = object1.getquantity();
    cout << object1.nameobject() << " delivered!" << endl;
    cout << object1.describeobject() << endl;
    islevelup();
    cout << "Do you want to consume?" << endl;
    cin >> consumicion;
    consumelevelup();
}

void Manageobjects::islevelup() 
{
    if (quantity <= 0 && object1.nameobject() == "levelup") 
    {
        cout << "\nYou don't have any object levelup" << endl;
        cin.ignore();
    } 
    else if (quantity >= 1 && object1.nameobject() == "levelup")
    {
        cout << "\nYou have" << quantity << " object levelup" << endl;
        cin.ignore();
    } 
    else 
    {
        cout << "\nYou don't have any objects" << endl;
        cin.ignore();
    }
}

void Manageobjects::consumelevelup()
{
    if (quantity <= 0)
    { 
        quantity = 0;
    }
    if (consumicion == 'y' && quantity > 0) 
    {
        cout << "There are " << quantity << " quantities before consuming" << endl;
        cin.ignore();
        quantity--;
        cout << "Consuming... "<<endl;
        cin.ignore();
        //stats upping 
        player_stats.changehealth(400);
        player_stats.changeenergy(30);
        player_stats.changeattack(50);
        cout << "New stats (atk, en, hp): " << player_stats.getattack() << ", " << player_stats.getenergy() << ", " << player_stats.gethealth() << endl;
        cout << "Consumed" << endl;
        cin.ignore();
        cout << "There are " << quantity << " quantities after consuming" << endl;
        cin.ignore();
    }
    else if (consumicion == 'n' || quantity <= 0)
    { 
        cout << "Don't consume it" << endl; cin.ignore();
    }
    else
    {
        cout << "It must be y o n, yes or no" << endl;
    }
    if (quantity <= 0) 
    { 
        quantity = 0;
    }
}
#endif //UNTITLED_GIVEN_H
