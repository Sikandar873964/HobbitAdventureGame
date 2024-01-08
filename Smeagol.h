#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Smeagol : public Character {
private:
  int stingDmg;
  int inteligence;

public:
  Smeagol() {
    stingDmg = 0;
    inteligence = 10;
  }
  void setStingDmg(int f) { stingDmg = f; }
  int getStingDmg() { return stingDmg; }
  void setIntel(int a) { inteligence = a; }
  int getIntel() { return inteligence; }
  int UsespecialPower() {
    if (inteligence > 15) {
      stingDmg = 100;
    }
    return stingDmg;
  }
  ~Smeagol() {}
};
