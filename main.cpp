
#include <iostream>
#include "character.h" 
#include "enemy.h"
using namespace std;


int main() {
    std::cout << "Welcome to the wilderness adventure game!" << std::endl;

    std::cout << "What is your name?" << std::endl;
    std::string playerName;
    std::cin >> playerName;

    Player *player = new Player(playerName);

    std::cout << playerName << ", You find yourself in a dark forest. There is a path to the left and a path to the right. Which way do you want to go? 1.left 2.right" << std::endl;
    std::string choice;
    std::cin >> choice;

    if (choice == "1") {
        std::cout << "You choose the path to the left and come across a bear. What do you want to do? (fight/run)" << std::endl;
        std::cin >> choice;

        if (choice == "2") {
            Enemy *bear = new Enemy("Bear", 20);
            std::cout << "You decide to fight the " << bear->getName() << ". It has an attack power of " << bear->getAttackPower() << "." << std::endl;

            player->setHealth(player->getHealth() - bear->getAttackPower());

            if (player->getHealth() <= 0) {
                std::cout << "You have been defeated by the " << bear->getName() << "." << std::endl;
            } else {
                std::cout << "You have defeated the " << bear->getName() << " and continue on your journey." << std::endl;
            }
            delete bear;
        } else {
            std::cout << "You decide to run away from the bear and continue on your journey." << std::endl;
        }
    } else {
        std::cout << "You choose the path to the right and come across a river. What do you want to do? (swim/turn back)" << std::endl;
        std::cin >> choice;

        if (choice == "swim") {
            std::cout << "You decide to swim across the river and continue on your journey." << std::endl;
        } else {
            std::cout << "You decide to turn back and take the path to the left." << std::endl;
        }
    }

    std::cout << "Your journey ends here. Thank you for playing!" << std::endl;
    delete player;
    return 0;
  }