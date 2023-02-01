// Character Class file 

using namespace std;

// Player class containing the name and health level of the player 
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

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Enemy(std::string n, int h, int a) : 
    name(n), health(100), attackPower(40) {}

    std::string getName() { return name; }
    int getHealth() {return health; }
    int getAttackPower() { return attackPower; }
};
