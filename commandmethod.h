//
// Created by Jorge on 13/10/2020.
//

#ifndef TEXTOJUEGO_COMMANDMETHOD_H
#define TEXTOJUEGO_COMMANDMETHOD_H

/**********************************************************/
#include <iostream>
#include "commands.h"
using namespace std;

/**********************************************************/
class CommandMethod
{
public:
    void introducecommand();
};
void CommandMethod::introducecommand()
{
    Commands commandintroduced;
    commandintroduced.checkcommand();
    commandintroduced.executecommand();
}
#endif //TEXTOJUEGO_COMMANDMETHOD_H
