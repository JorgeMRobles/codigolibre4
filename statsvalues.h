//
// Created by Jorge on 07/10/2020.
//

#ifndef UNTITLED_STATSVALUES_H
#define UNTITLED_STATSVALUES_H

class Stats{
public:
    Stats();
    Stats(int health, int mood, int energy, int attack);

    int gethealth();
    int getmood();
    int getenergy();
    int getattack();

    int health = gethealth();
    int mood = getmood();
    int energy = getenergy();
    int attack = getattack();

    void changehealth(int health);
    void changemood(int mood);
    void changeenergy(int energy);
    void changeattack(int attack);

protected:
    int _health;
    int _mood;
    int _energy;
    int _attack;

};

Stats::Stats (int health, int mood, int energy, int attack){
    _health = health;
    _mood = mood;
    _energy = energy;
    _attack = attack;
}

int Stats::gethealth() 
{
    return _health;
}
int Stats::getmood() 
{
    return _mood;
}
int Stats::getenergy() 
{
    return _energy;
}
int Stats::getattack() 
{
    return _attack;
}

Stats player_stats (100, 5, 10, 35);

void Stats::changehealth(int health)
{
    _health = health;
}
void Stats::changemood(int mood)
{
    _mood = mood;
}
void Stats::changeenergy(int mood)
{
    _mood = mood;
}
void Stats::changeattack(int attack)
{
    _attack = attack;
}
#endif //UNTITLED_STATSVALUES_H
