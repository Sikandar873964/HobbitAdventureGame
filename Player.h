#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Player : public Character {
private:
  int swordDmg;
  int xp; // xp is experience. more experience you gain more powerful you
          // become.
public:
  Player() : Character() {
    swordDmg = 0;
    xp = 0;
  }
  Player(int swordDmg, int xp) : Character() {
    this->swordDmg = swordDmg;
    this->xp = xp;
  }
  void setswordDmg(int dmg) { swordDmg = dmg; }
  int getswordDmg() { return swordDmg; }
  void setXp(int e) { xp = e; }
  int getXp() { return xp; }
  int UseSpecialPower() {
    int count = 0;
    while (count < 3) {
      if (xp > 5) {
        swordDmg = swordDmg + xp;
        xp += 2;
      } else {
        swordDmg = 5;
      }
      count++;
    }
    return swordDmg;
  }
  ~Player() {}
};