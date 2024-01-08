#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Level {
private:
  Player p;
  Monster m;
  Smeagol s;
  Riddler r;

public:
  bool stage1() {
    char *uChoice = new char;
    char *comChoice = new char;
    int mwin = 0;
    int uwin = 0;
    int rounds = 3;

    for (int round = 1; round <= rounds; ++round) {
      cout << "\n\nRound " << round << endl;
      // Get user's choice
      cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
      cin >> *uChoice;
      *uChoice = toupper(*uChoice);

      // Get computer's choice
      char choices[] = {'R', 'P', 'S'};
      *comChoice = choices[rand() % 3];

      cout << "You Pick: " << *uChoice << endl;
      cout << "Monster Pick: " << *comChoice << endl;

      if (*uChoice == *comChoice) {
        cout << "It's a tie! Let do it again." << endl;
      } else if ((*uChoice == 'R' && *comChoice == 'S') ||
                 (*uChoice == 'P' && *comChoice == 'R') ||
                 (*uChoice == 'S' && *comChoice == 'P')) {
        cout << "You win! \n You Orcrist is more powerful now. You have gain "
                "Bonus Damage "
             << endl;
        p.setswordDmg(10);
        p.setXp(10);
        uwin++;
      } else {
        cout << "Monster wins!" << endl;
        m.setRoarDmg(10);
        m.setStrength(10);

        mwin++;
      }

      cout << endl;
    }
    delete uChoice;
    delete comChoice;
    if (uwin > mwin) {
      int dmg = p.UseSpecialPower();
      if (dmg > 100) {
        m.setHP(0);
        cout << "Monster Died!" << endl;
        return true;
      }
      return false;
    } else {
      p.setHP(0);
      cout << "Player Died!" << endl;
      return false;
    }
  }

  bool stage2() {
    const int ridCount = 3;
    string riddles[ridCount] = {
        "What has roots as nobody sees,\n Is taller than trees,\n Up, up it "
        "goes,\n And yet never grows?",
        "Voiceless it cries,\n Wingless flutters,\n Toothless bites,\n "
        "Mouthless mutters.",
        "It cannot be seen, cannot be felt,\n Cannot be heard, cannot be "
        "smelt.\n It lies behind stars and under hills,\n And empty holes it "
        "fills.\n It comes out first and follows after,\n Ends life, kills "
        "laughter.?"};

    string ridAnswer[ridCount] = {"mountain", "wind", "dark"};
    string *userAns = new string[ridCount];

    cout << "Welcome to the Riddle Game!" << endl;

    for (int i = 0; i < ridCount; ++i) {
      cin.ignore();
      cout << "\nRiddle " << (i + 1) << ": " << endl;
      cout << "\"" << riddles[i] << "\"" << endl;
      cout << "\nYour turn. Enter your answer: ";
      getline(cin, userAns[i]);
      if (userAns[i] != ridAnswer[i]) {
        p.setHP(0);
        cout << "Oops! That's not the correct answer. Die!" << endl;
        return false;
      }
    }
    cout << "\nCongratulations frodo! You win!" << endl;

    return true;
  }

  bool stage3() {
    int hobbitScore = 0;
    int gollumScore = 0;

    while (true) {
      // Hobbit's turn
      int hobbitNumber;
      cout << "Bilbo, enter a number between 1 and 5: ";
      cin >> hobbitNumber;

      if (hobbitNumber < 1 || hobbitNumber > 5) {
        cout << "Invalid input. Please enter a number again." << endl;
        continue;
      }

      // Gollum's turn
      int gollumNumber = rand() % 5 + 1;
      cout << "Gollum turn: " << gollumNumber << endl;

      // Check if hobbit is out
      if (hobbitNumber == gollumNumber) {
        cout << "Oops! Bilbo is out. Gollum scores a point." << endl;
        gollumScore++;
        break;
      }

      // Update scores using pointers
      int *hobbitScorePtr = &hobbitScore;
      *hobbitScorePtr += hobbitNumber;

      // Display current scores
      cout << "Current scores - Bilbo: " << *hobbitScorePtr
           << ", Gollum: " << gollumScore << endl;

      // Gollum's turn
      gollumNumber = rand() % 5 + 1;
      cout << "Gollum played: " << gollumNumber << endl;

      // Check if gollum is out
      if (*hobbitScorePtr == gollumNumber) {
        cout << "Oops! Gollum is out. Bilbo scores a point." << endl;
        hobbitScore++;
        break;
      }

      // Update scores using pointers
      int *gollumScorePtr = &gollumScore;
      *gollumScorePtr += gollumNumber;

      // Display current scores
      cout << "Current scores - Bilbo: " << *hobbitScorePtr
           << ", Gollum: " << *gollumScorePtr << endl;
    }

    // Determine the winner
    if (hobbitScore > gollumScore) {
      return true;
    } else {
      return false;
    }
  }
};