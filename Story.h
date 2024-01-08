#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Story {
private:
  Level l;
  Character c;

public:
  Story() {
    cout << "\t\t\t The Hobbit's Journey: Quest for the Counting Stone\n\n"
         << endl;
  }
  void GamePlay() {
    c.setPosition("Shire");
    if (c.getPosition() == "Shire") {
      cout << "In the serene and picturesque land of the Shire, nestled "
              "comfortably between rolling hills and lush green meadows,"
           << "lived a young hobbit named Frodo Baggins. Frodo was known for "
              "his curious nature, a trait not uncommon among hobbits,"
           << "but his destiny was about to take an unexpected turn.";
      char option;
      cout << "\n\nDo you want to read the story? Press y to continue: ";
      cin >> option;
      if ((option == 'y') || (option == 'Y')) {
        cout
            << "Frodo reading a book written by his Uncle Samwise Gamgee:"
            << "As Frodo prepared for his upcoming quest, he decided to spend "
               "a quiet evening in the cozy corner of Bag End, flipping "
               "through the pages of an old, weathered book. The book was a "
               "cherished possession of his Uncle Samwise Gamgee, who had been "
               "an adventurer in his own right."

            << "The leather-bound volume, titled ''Sam's Tales: Adventures "
               "Beyond the Shire,' contained vivid accounts of Sam's journeys "
               "and the wonders he had encountered outside the peaceful "
               "borders of the Shire. The flickering candlelight cast a warm "
               "glow on the pages as Frodo immersed himself in the tales of "
               "his uncle's courage and camaraderie."

            << "Each page turned revealed stories of perilous encounters, "
               "unexpected friendships, and the breathtaking landscapes of "
               "Middle-earth. Sam's writing transported Frodo to distant "
               "lands, sparking his imagination and filling him with a sense "
               "of anticipation for the adventures that awaited him."

            << "Among the tales, Frodo found one particularly intriguing story "
               "about a mysterious artifact known as the Counting Stone. "
               "Samwise had heard whispers of its power during his travels and "
               "had always wondered about the enigma surrounding it."

            << "As Frodo read, he felt a connection between Uncle Sam's tales "
               "and Gandalf's recent visit. It seemed as though the Counting "
               "Stone was not just a mythical artifact but a part of the very "
               "fabric of Middle-earth, entwining the fates of hobbits and the "
               "destiny of the realm."

            << "With the book in hand, Frodo pondered the significance of his "
               "upcoming journey. The tales of Uncle Sam provided a sense of "
               "lineage and a reminder that courage and resilience ran deep in "
               "the Baggins-Gamgee bloodline."

            << "As the night deepened, Frodo closed the book, a glint of "
               "determination in his eyes. He knew that the answers to the "
               "mysteries of the Counting Stone and the challenges that lay "
               "ahead were waiting to be unraveled. The quest for the Counting "
               "Stone was not only a journey into the unknown but a "
               "continuation of the adventurous spirit that ran through the "
               "tales of his family.";

        cout << " Frodo, Get ready to take the journey ";

        cout << "Frodo! Go to Deadlands where you will find your first clue to "
                "the quest."
             << endl;
        c.setPosition("Deadlands");
        if (c.getPosition() == "Deadlands") {
          cout << "Dear Frodo, Be very careful in these lands. To find your "
                  "first clue you have to defeat Monster.\nOnly he knows the "
                  "path to the counting stone.\nGo into the woods and you will "
                  "find him. But remember Frodo Baggins there is no second "
                  "chance."
               << endl;
          bool result = l.stage1();
          if (result == true) {
            cout << "Congratulations Frodo Baggins. It was a very difficult "
                    "battle. But you have won. Now Move to the Misty Mountains "
                    "for the next clue."
                 << endl;
            c.setPosition("Misty Lands");
            if (c.getPosition() == "Misty Lands") {
              cout << "Hello Frodo. So you have reached here. But you will not "
                      "go ahead from these lands.\n\n\n if you want to get the "
                      "final clue to the counting stone you have to answer all "
                      "my riddles correctly. Remember in case of any wrong "
                      "answer this mist will kill you."
                   << endl
                   << endl;
              cout << "Let's begin Frodo Baggins.\n";
              bool result1 = l.stage2();
              if (result1 == true) {
                cout << "Congratulations Frodo You did it. We have found our "
                        "final clue to the counting stone."
                     << endl;
                c.setPosition("Forbidden Caves");
                if (c.getPosition() == "Forbidden Caves") {
                  cout << "Dear Frodo, Be very careful in these lands. To get "
                          "the counting stone you have to defeat Gollum.\nBut "
                          "remember Frodo Baggins there is no second chance."
                       << endl;
                  bool result = l.stage3();
                  if (result == true) {
                    cout << "Congratulations Frodo Baggins. It was a very "
                            "difficult battle. And you proved again. Now the "
                            "stone is yours. Go make a wish Frodo. "
                         << endl;
                    exit(0);
                  } else {
                    cout << "Alas! Someday a warrior will be born who will "
                            "fulfill your dream Frodo Baggins."
                         << endl;
                    exit(0);
                  }
                }
              } else {
                cout << "Alas! No one has ever returned from the Misty Land.\n "
                        "Journey of Hobbit ends here."
                     << endl;
                exit(0);
              }
            }
          } else {
            cout << "Alas! No one has ever survived in the Deadlands.\n "
                    "Journey of Hobbit ends here."
                 << endl;
            exit(0);
          }
        }
      } else {
        cout << "\n\nGood Bye Frodo Bagins. We'll begin the journey some other "
                "day."
             << endl;
      }
    }
  }
};