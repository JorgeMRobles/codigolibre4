//
// Created by Jorge on 19/10/2020.
//

#ifndef TEXTOJUEGO_dialogue_H
#define TEXTOJUEGO_dialogue_H

/**********************************************************/
#include "iostream"
#include "stdlib.h"
#include <fstream>
#include "string"
#include "othermethods.h"
using namespace std;

/**********************************************************/
OtherMethods om;
class Dialogue
        {
        public:
            fstream dialogue, dialoguename;
            ofstream savename;
            fstream filename_reading;
            string namestr, linename, chosenbefore;

            void setname();
            void readfile();
            string readModifiable_name();
            void beforeinterpret();
            void interpretpath();
            void interpretpath2();
            void interpretpath3();
            void battlebegins();
            void objectgiven();
            void objectgiven_after();
            void continuegame();
        };

void Dialogue::setname()
{
    //delete the possible previous content
    savename.open("registered.txt", ios::out | ios::trunc);
    savename.close();

    char name[40];
    savename.open("registered.txt", ios::app);
    if (savename.is_open())
    {
        //requests name and gets its as char[] 
        cout << "What is your name, adventurer that came of other world?" << endl;
        cin >> name;

        //converts to string and capitalises
        namestr = name;
        namestr = om.Capitalise_firstword(namestr);
        cout << "Name: " << namestr << endl;

        savename << namestr;
        savename.close();
    }
    else
    {
        cout << "Sorry. Nothing found" << endl;
    }
}

void Dialogue::readfile()
{
    dialogue.open("dialogue.txt", ios::in);
    if (dialogue.is_open())
    {
        string line;
        while (getline(dialogue, line))
        {
            cout << line << endl;
            cin.ignore();
        }
        dialogue.close();
    }
    else
        {
        cout << "Sorry. Nothing found" << endl;
        }
}

string Dialogue::readModifiable_name() 
{
    string line;
    filename_reading.open("registered.txt", ios::in);
    if (filename_reading.is_open())
    {
    while (getline (filename_reading,line))
    {
        linename = line;
        cin.ignore();
    }
    filename_reading.close();
    }
    else
    {
        cout << "Sorry. Nothing found" << endl;
    }
    return linename;
}

void Dialogue::beforeinterpret()
{
    cout << "Soldier: Where do you go " << linename << "?";
    cin.ignore(); 
    interpretpath(); 
}

void Dialogue::interpretpath() //between waterfall and forest option
{
    fstream file_in("seconddialogue.txt");
    string line;
    int chosenpath, startingposition, actualposition;

    cout << "Choose the path:" << endl;
    cin >> chosenpath;
    switch (chosenpath)
    {
        case 1:
            startingposition = 0;
            actualposition = startingposition;
            while (getline(file_in, line))
            {
                if (actualposition < 1)
                {
                    line.clear();
                    actualposition++;
                }
                if (actualposition >= 1 && actualposition < 5)
                {
                    cout << line << endl;
                    cin.ignore();
                    actualposition++;
                }
            }
            interpretpath2();
            //option 1
        case 2:
            startingposition = 0;
            actualposition = startingposition;
                while (getline(file_in, line))
                {
                    if (actualposition < 4)
                    {
                        line.clear();
                        actualposition++;
                    }
                    if (actualposition >= 4 && actualposition < 15)
                    {
                        cout << line << endl;
                        cin.ignore();
                        actualposition++;
                    }
                }
                interpretpath2();
                //option 2
    }
    file_in.close();
}

void Dialogue::interpretpath2() //between staying or cave option
{
    fstream file_in("seconddialogue.txt");
    string line;
    int chosenpath, startingposition, actualposition;

    cout << "Choose the path:" << endl;
    cin >> chosenpath;
    switch (chosenpath)
    {
    case 1:
        startingposition = 0;
        actualposition = startingposition;
        while (getline(file_in, line))
        {
            if (actualposition < 42)
            {
                line.clear();
                actualposition++;
            }
            if (actualposition >= 42 && actualposition < 46)
            {
                cout << line << endl;
                cin.ignore();
                actualposition++;
            }
        }
        om.deadplayer();
        //option 1
    case 2:
        startingposition = 0;
        actualposition = startingposition;
        while (getline(file_in, line))
        {
            if (actualposition < 15)
            {
                line.clear();
                actualposition++;
            }
            if (actualposition >=  15 && actualposition < 24)
            {
                cout << line << endl;
                cin.ignore();
                actualposition++;
            }
        }
        interpretpath3(); 
        //option 2
    }
    file_in.close();
}

void Dialogue::interpretpath3() //between attack and don't attack option
{
    fstream file_in("seconddialogue.txt");
    string line;
    int chosenpath, startingposition, actualposition;

    cout << "Choose the path:" << endl;
    cin >> chosenpath;
    switch (chosenpath)
    {
    case 1:
        startingposition = 0;
        actualposition = startingposition;
        while (getline(file_in, line))
        {
            if (actualposition < 25)
            {
                line.clear();
                actualposition++;
            }
            if (actualposition >= 25 && actualposition < 27)
            {
                cout << line << endl;
                cin.ignore();
                actualposition++;
            }
        }
        om.deadplayer();
        //option 1
    case 2:
        startingposition = 0;
        actualposition = startingposition;
        while (getline(file_in, line))
        {
            if (actualposition < 28)
            {
                line.clear();
                actualposition++;
            }
            if (actualposition >= 28 && actualposition < 35)
            {
                cout << line << endl;
                cin.ignore();
                actualposition++;
            }
        }
        //option 2
    }
    file_in.close();
}

void Dialogue::battlebegins()
{ //when first battle begins
    cout << "Something gets close to you..." << endl;
    cin.ignore();
}

void Dialogue::objectgiven()
{
    fstream file_in("seconddialogue.txt");
    string line;
    int startingposition, actualposition;
    startingposition = 0;
    actualposition = startingposition;
    while (getline(file_in, line))
    {
        if (actualposition < 35)
        {
            line.clear();
            actualposition++;
        }
        if (actualposition >= 35 && actualposition < 39)
        {
            cout << line << endl;
            cin.ignore();
            actualposition++;
        }
    }
    file_in.close();
}

void Dialogue::objectgiven_after()
{
    fstream file_in("seconddialogue.txt");
    string line;
    int startingposition, actualposition;
    startingposition = 0;
    actualposition = startingposition;
    while (getline(file_in, line))
    {
        if (actualposition < 39)
        {
            line.clear();
            actualposition++;
        }
        if (actualposition >= 40 && actualposition < 42)
        {
            cout << line << endl;
            cin.ignore();
            actualposition++;
        }
    }
    file_in.close();
}

#endif //TEXTOJUEGO_dialogue_H
