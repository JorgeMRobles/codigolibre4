//
// Created by Jorge on 07/10/2020.
//

#ifndef UNTITLED_ENTITIES_H
#define UNTITLED_ENTITIES_H

/**********************************************************/
#include "statsvalues.h"
#include "string"
using namespace std;

/**********************************************************/
//------------Characters-----------------------
class Characters
{
public:
    Characters(); //call to constructor
    Characters(string name, int health, int force, int power);

    string setname();
    int sethealth();
    int setforce();
    int setpower();
protected:
    string _name;
    int _health;
    int _force;
    int _power;

};
Characters::Characters (string name, int health, int force, int power)
{
    _name = name;
    _health = health;
    _force = force;
    _power = power;
}

string Characters::setname() 
{
    return _name;
}
int Characters::sethealth() 
{
    return _health;
}
int Characters::setforce() 
{
    return _force;
}
int Characters::setpower() 
{
    return _power;
}

Characters basicenemy ("Assailant", 100, 10, 10);
Characters werewolf ("Werewolf", 200, 20, 0);
Characters vampire ("Vampire", 1000, 30, 33);
Characters finalboss ("Final Shadow", 40000, 100, 100);

//------------Objects-----------------------
class Objects
{
public:
    Objects();
    Objects(string name, string description);
    string nameobject();
    string describeobject();
    void changequantity(int quantity);
    int getquantity();

protected:
    string _name, _description;
    int _quantity;
};

Objects::Objects(string name, string description)
{
    _name = name;
    _description = description;
}

string Objects::nameobject()
{
    return _name;
}
string Objects::describeobject()
{
    return _description;
}
void Objects::changequantity(int quantity) 
{
    _quantity = quantity;
}
int Objects::getquantity()
{
    return _quantity;
}
#endif //UNTITLED_ENTITIES_H
