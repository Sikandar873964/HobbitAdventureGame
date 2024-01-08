#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Monster : public Character {
private:
  int roarDmg;
  int strength;

public:
  Monster() {
    roarDmg = 0;
    strength = 10;
  };
  void setRoarDmg(int r) { roarDmg = r; }
  int getRoar() { return roarDmg; }
  void setStrength(int s) { strength = s; }
  int getStrength() { return strength; }
  int UsespecialPower() {
    if (strength >= 15) {
      roarDmg = 100;
    }
    return roarDmg;
  }
  ~Monster() {}
};