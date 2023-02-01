
#include <iostream>
#include "character.h" 


using namespace std;

//String containing an Array of locations in the game "world"
std::string world[4] = {"Forest", "Cave", "River", "Mountain"};
std::string *location = world; // pointer used to access the location and move along the array

//new variables made to contain the private health level of the Enemy Class 
//so it can be changed during the players fight
int newBearHealth();
int newPlayerHealth();

// Class for the Weapons in the game that contains a name and power variable 
class Weapon{
public:
    Weapon(const string &name, int power):
    name(name), power(power){}

    string name;
    int power;
  };

void goForward() {location++;} //used to move the location position forward
void goBack() {location--;}  //used to move the world array backwards

int main() {

// Array of weapons for the Weapons class containing a name and power
  Weapon weapons[] = {
    {"Sword", 60},
    {"Axe", 40},
    {"Dagger", 20}};
  
  // this creates and int for the count of the weapons 
  int *weaponsCount = new int(sizeof(weapons) / sizeof(Weapon));

  //Game Begins
    cout << "Welcome to the wilderness adventure game!" << endl;

    cout << "What is your name?" << endl;
    string playerName; // creates a string for the player name
    cin >> playerName; // gets user input

  // Stores player name input to a player pointer
    Player *player = new Player(playerName);

    cout << "\nThere are 4 possible locations: " << endl;
    for (int i = 0; i < 4; i++) {
      cout << i + 1 << "." << world[i] << endl;
    }
  
    // 1. Path : first user choice 
    cout << "\n"<< playerName << " You're in the " << *location << ". There is a path to the Cave and a path to the River." << endl;
    cout << "\nWhich way do you want to go? \n1.Cave \n2.River" << endl;
    string choice;
    cin >> choice;

    // 1.2 Bear Level
    if (choice == "1") {
        goForward();
        cout << "You choose the path to the " << *location << " and come across a bear."<< endl;
        cout <<"\nWhat do you want to do? \n1.run \n2.fight" << endl;
        cin >> choice;

        if (choice == "2") {
            Enemy *bear = new Enemy("Bear", 100, 20); // uses  pointer
            cout << "You decide to fight the " << bear->getName() << ". It has an attack power of " << bear->getAttackPower()<< ", and health of "<< bear->getHealth() << "." << endl;

        cout << "Choose a weapon:" << endl; 
        for (int i = 0; i < *weaponsCount; i++) {
          cout << i + 1 << ". " << weapons[i].name << " (Power: " << weapons[i].power << ")" << endl;}
          
          int choice;
          cout << "Enter your choice 1 to " << *weaponsCount<< ":"<< endl;
          cin >> choice;
            Weapon *selectedWeapon = &weapons[choice - 1];
          
          cout << "\nYou selected " << selectedWeapon->name << " with power " << selectedWeapon->power << endl;

          // Fight with Enemy
          cout << "Your health is " << player->getHealth() << ", Enemy health is " << bear->getHealth() << endl;
          cout<< "The fight begins \n" << endl;

          int newEnemyHealth = bear->getHealth();
          int newPlayerHealth = player->getHealth();

        while (newPlayerHealth > 0 && newEnemyHealth > 0) {
          newEnemyHealth -= selectedWeapon->power;
        if (newEnemyHealth <= 0) {
          cout << bear->getName() << " has been defeated.\n" << endl;
          break;}

        cout << bear->getName() << " attacked you and your health is now " << (newPlayerHealth -= bear->getAttackPower()) << endl;
        cout << "You attacked the " << bear->getName() << " its health is now " << (newEnemyHealth) << endl;
        if (newPlayerHealth <= 0) {
          cout << "You have been defeated.\n" << endl;
        break;}
          
        cout << "Choose another weapon:" << endl;
        cin >> choice;
        selectedWeapon = &weapons[choice - 1];
      }

        if (player->getHealth() <= 0) {
            cout << "You have been defeated by the " << bear->getName() << "." << endl;
        } else {
            cout << "You have defeated the " << bear->getName() << " and continue on your journey." << endl;
        }
     delete bear; } 
       
        else {
            goForward();
            goForward();
            cout << "You decide to run away from the bear and continue on your journey to the " << *location << endl;
        }
      } 
    else {
        goForward();
        goForward();
        cout << "You choose the path to the " << *location << ".\n What do you want to do? \n1.swim \n2.turn back" << endl;
        cin >> choice;

        if (choice == "1") {
          goForward();
            cout << "You decide to swim across the river and continue on your journey to the "<< *location<< "."<< endl;
        } else {
          goBack();
            cout << "You decide to turn back and take the path to the" << *location << ", you get hit by a landslide and die." << endl;
        }
      }

    cout << "Your journey ends here. \nThank you for playing!" << endl;
    delete player;
    return 0;
  }
 
