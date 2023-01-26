#pragma once
using namespace std;

class Enemy {
private:
    std::string name;
    int attackPower;

public:
    Enemy(std::string n, int a) : name(n), attackPower(a) {}

    std::string getName() { return name; }
    int getAttackPower() { return attackPower; }
};