#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Riddler : public Character {
private:
  int MagicDmg;

public:
  Riddler() { MagicDmg = 10; }
  void setMagicDmg(int m) { MagicDmg = m; }
  int getMagicDmg() { return MagicDmg; }
  int UsespecialPower() {
    MagicDmg = 100;
    return MagicDmg;
  }
  ~Riddler() {}
};