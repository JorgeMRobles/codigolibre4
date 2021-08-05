/**********************************************************/
/*                   Jorge M. Robles                      */
/*                  Text-Adventure Game                   */
/**********************************************************/


/**********************************************************/
#include <iostream>
#include "dialogue.h"
#include "battle.h"
#include "given.h"

using namespace std;

/**********************************************************/
int main()
{
    do
    {
        //inicial text and set name
        Dialogue dialoguetext;
        dialoguetext.setname();
        dialoguetext.readfile();
        dialoguetext.readModifiable_name();
        dialoguetext.beforeinterpret();

        //battle with basic enemy
        dialoguetext.battlebegins();
        battle firstbattle;
        firstbattle.showtext(); //that text before a battle
        firstbattle.attack(); //each entity attacks on his turn

        dialoguetext.objectgiven();

        //give and consume the object called levelup
        Manageobjects manageobjects_class;
        manageobjects_class.manageobject(); //manages levelup object 

        dialoguetext.objectgiven_after();

        //battle with a werewolf
        battle2 secondbattle;
        secondbattle.changevalues(); //changes to werewolf's values 
        secondbattle.showtext();
        secondbattle.attack();

        //show and ask for commands
        Commands commands_class;
        commands_class.checkcommand();  //reads introduced command
        commands_class.executecommand();   //executes command
    
    } while (om.getcontinue() != 0);
    
    return 0;
}