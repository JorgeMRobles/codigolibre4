//
// Created by Jorge on 07/10/2020.
//

#ifndef UNTITLED_STATSVALUES_H
#define UNTITLED_STATSVALUES_H

class Stats{
public:
    Stats();
    Stats(int s, int an, int en, int at);

    int gethealth();
    int getmood();
    int getenergy();
    int getattack();

    int health = gethealth();
    int mood = getmood();
    int energy = getenergy();
    int attack = getattack();

    void changehealth(int s);
    void changemood(int an);
    void changeenergy(int en);
    void changeattack(int at);

protected:
    int _health;
    int _mood;
    int _energy;
    int _attack;

};

Stats::Stats (int s, int an, int en, int at){
    _health = s;
    _mood = an;
    _energy = en;
    _attack = at;
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

void Stats::changehealth(int s) 
{
    _health = s;
}
void Stats::changemood(int an) 
{
    _mood = an;
}
void Stats::changeenergy(int en) 
{
    _energy = en;
}
void Stats::changeattack(int at) 
{
    _attack = at;
}
#endif //UNTITLED_STATSVALUES_H
