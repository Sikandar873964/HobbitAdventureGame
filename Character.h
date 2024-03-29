#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
/*
 character is parent class. (child classes are as follow)
                Player
               C Monster
                Riddle
                Smeagol
 Level is another class. Character class is strongly linked with this class. It
 contains all the stages. Each stage has different enemy character. Story is our
 primary class. This class contains levels and level class contains characters.

 OOP concepte implemented --> Inheritance --> Polymorphism(all clases has one
 common function) --> composition and anstraction


        Pointers are used in different stages. In case if you want to use
 pointesrs throughout the application then we will replave variable name with
 *variablename.
*/
class Character {
private:
  string name;
  int health;
  string position;

public:
  Character() {}
  Character(string name, int health, string position) {
    this->name = name;
    this->health = health;
    this->position = position;
  }
  void setName(string s) { name = s; }
  string getName() { return name; }
  void setHP(int h) { health = h; }
  int getHP() { return health; }
  void setPosition(string p) { position = p; }
  string getPosition() { return position; }

  virtual int UseSpecialPower() {
    cout << "You have no Special Power." << endl;
    return 0;
  }
  ~Character() {}
};