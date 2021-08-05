//
// Created by Jorge on 07/10/2020.
//

#ifndef UNTITLED_OtherMethods_H
#define UNTITLED_OtherMethods_H

/**********************************************************/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

/**********************************************************/
class OtherMethods
{
protected:
    int _continuegame = 0;
    bool _youdead = false;
public:
    string Capitalise_firstword(string name_received);
    void deadplayer();
    void deadplayer_infinite();
    int getcontinue();
    void areyoudead();
};

string OtherMethods::Capitalise_firstword(string name_received) 
{
    for (int x = 0; x < name_received.length(); x++)
    {
        if (x == 0)
        {
            name_received[x] = toupper(name_received[x]);
        }
        else if (name_received[x - 1] == ' ')
        {
            name_received[x] = toupper(name_received[x]);
        }
    }
    return name_received;
}

void OtherMethods::deadplayer() 
{
    cout << "------------GAME OVER------------" << endl;
    cin.ignore();
    _youdead = true;
    areyoudead();    //if you die
}
void OtherMethods::deadplayer_infinite() 
{
    for (int i=0; i<=30; i++)
    {
        cout << "------------GAME OVER------------" << endl;
        cin.ignore();
        _youdead = true;
        areyoudead();
    }
}

int OtherMethods::getcontinue()
{
    return _continuegame;
}

void OtherMethods::areyoudead()
{
    if (_youdead == true)
    {
        cout << "Really? Do you want to continue with this game? You should go..." << endl;
        cout << "Enter 1 for yes or 0 for no: " << endl;
        cin >> _continuegame;
    }
}
#endif //UNTITLED_OtherMethods_H
