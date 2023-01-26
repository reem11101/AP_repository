#pragma once
using namespace std;
 
class Player {
private:
    std::string name;
    int health;
    
public:
    Player(std::string n) : name(n), health(100) {}

    std::string getName() { return name; }
    int getHealth() { return health; }

    void setHealth(int h) { health = h; }
};


// class Enemy {
// private:
//     std::string name;
//     int attackPower;

// public:
//     Enemy(std::string n, int a) : name(n), attackPower(a) {}

//     std::string getName() { return name; }
//     int getAttackPower() { return attackPower; }
// };