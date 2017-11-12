// Copyright 2017 Napassorn napalerd@bu.edu
// reads tic-tac-toe scenario from a file (tictactoeboards.txt)
// and determines the status of each game by outputing another
// text file (tttstatus.txt)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//  function checks the winner
bool checkwinner(std::string onegame, std::string win) {
  std::string three; // char array
  char pos[]= {onegame[0], onegame[1], onegame[2], onegame[3],
               onegame[4], onegame[5], onegame[6], onegame[7],
               onegame[8], onegame[0], onegame[3], onegame[6],
               onegame[1], onegame[4], onegame[7], onegame[2],
               onegame[5], onegame[8], onegame[0], onegame[4],
               onegame[8], onegame[2], onegame[4], onegame[6]
              };
  for (int k=0; k < 22; k=k+3, three.clear()) {
    three += pos[k];  //  creating a string for position
    three += pos[k+1];
    three += pos[k+2];
    if (three == win)
      return true;
  }
  return false;
}

int main() {  //  Reads in game file
  std::ifstream tic;
  std::vector<std::string> contents;
  std::string agame;
  tic.open("tictactoeboards.txt");
  while (getline(tic, agame))
    contents.push_back(agame);  //  info stored in contents
  tic.close();

  std::vector<std::string> tttstatus;
  std::vector<std::string>::size_type sz = contents.size();
  for (int i=0; i <sz; ++i) {  //  index each line in vector
    std::string onegame;
    onegame = contents[i];
    int countx{0}, counto{0}, none{0};
    // int count{0};
    for (int k=0; k < onegame.size(); ++k) {  //  index into each string
      if (onegame[k] == 'x') ++countx;
      else if (onegame[k] == 'o') ++counto;
      else if (onegame[k] == '#') ++none;
    }
    tttstatus.push_back(onegame);

    if (countx-counto > 1 or countx-counto < -1 or counto > countx) {
      //  checks if skipped rounds
      tttstatus.push_back(" i\n");
      //  x has to start first
    } else {
      if (none == 0) {  //  no spaces left
        if  (not checkwinner(onegame, "ooo")
             and not checkwinner(onegame, "xxx")) {
          tttstatus.push_back(" t\n");
          //  tie when no more spaces and no winner
        } else if (checkwinner(onegame, "ooo")
                   and not checkwinner(onegame, "xxx")) {
          tttstatus.push_back(" i\n");
        } else if (checkwinner(onegame, "xxx")
                   and not checkwinner(onegame, "ooo")) {
          if (countx > counto)
            tttstatus.push_back(" x\n");
          else
            tttstatus.push_back(" i\n");
        } else {
          tttstatus.push_back(" i\n");
        }
      } else {  //  spaces left
        if (checkwinner(onegame, "ooo")
            and not checkwinner(onegame, "xxx")) {
          if (counto == countx)
            tttstatus.push_back(" o\n");
          else
            tttstatus.push_back(" i\n");
        } else if (checkwinner(onegame, "xxx")
                   and not checkwinner(onegame, "ooo")) {
          if (countx == 4 and counto == 3)
            tttstatus.push_back(" x\n");
          else if (countx == 3 and counto ==2)
            tttstatus.push_back(" x\n");
          else
            tttstatus.push_back(" i\n");
        } else if (checkwinner(onegame, "xxx")
                   and checkwinner(onegame, "ooo")) {
          tttstatus.push_back(" i\n");
        } else if (not checkwinner(onegame, "xxx")
                   and not checkwinner(onegame, "ooo")) {
          tttstatus.push_back(" c\n");
        }
      }
    }
  }
  std::ofstream stats;
  stats.open("tttstatus.txt");
  for (const auto &e : tttstatus) stats<< e;
  stats.close();
  return 0;
}
