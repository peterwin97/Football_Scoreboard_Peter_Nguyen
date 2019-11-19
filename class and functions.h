#ifndef CLASS_AND_FUNCTIONS_H
#define CLASS_AND_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Input_Validation_Extended.h"

using namespace std;
  string colorR = "\x1b[31;1m";
  string orange = "\x1b[33;1m";
  string blue = "\x1b[36;1m";
  string underline = "\x1b[4;1m";
  string navy = "\x1b[94;1m";
  string reset = "\x1b[0m";

class Team 
{
  private:
  string name;
  string coachName;
  string homeCity;
  bool homeStatus;
  int score;
  int teamFouls;
  int timeoutCount;

  public:
  Team(){
    score = 000;
    teamFouls = 000;
    timeoutCount = 000;
    homeStatus = true;
  }
  void setName(string n) { name = n;}
  void setCoachName(string n) { coachName = n; }
  void setHomeCity(string city) { homeCity = city; }
  void setHomeStatus(bool status) { homeStatus = status; }
  void setScore(int i) { score = i; }
  void foulCount(int f) { teamFouls = f; }
  void setTimeoutCount(int t) { timeoutCount = t; }

  string getName() const { return name; }
  string getCoachName() const { return coachName; }
  string getHomeCity() const { return homeCity; }
  bool getHomeStatus() const { return homeStatus; }
  int getScore() const { return score; }
  int getFouls() const { return teamFouls; }
  int getTimeout() const {return timeoutCount; }
};

class Scoreboard
{
  private:
  Team team;

  public:
  void setTeamName(string n) { team.setName(n); } 
  void setCoachName(string n) { team.setCoachName(n); }
  void setHomeCity(string n) { team.setHomeCity(n); }
  void setHomeStatus(bool b) { team.setHomeStatus(b); }
  void setScore(int s) { team.setScore(s); }
  void setFouls(int f) { team.foulCount(f); }
  void setTimeoutCount(int t) { team.setTimeoutCount(t); }
 
  string getTeamName() const { return team.getName(); }
  string getCoachName() const { return team.getCoachName(); }
  string getHomeCity() const { return team.getHomeCity(); }
  bool getHomeStatus() const { return team.getHomeStatus(); }
  int getScore() const { return team.getScore(); }
  int getFouls() const { return team.getFouls(); }
  int getTimeoutCount() const { return team.getTimeout(); }

  void scoreboardGUI(Team t1, string team1CityAndName, Team t2, string team2CityAndName){
      

      team1CityAndName.resize(15);


      cout << "\t\t\t" << orange << "HOME" << "\t\t\t\t\t" << blue << "VISITOR" <<"\t\t\t\t\t" << reset << endl;
      cout << "\t\t\t" << team1CityAndName << "\t\t\t" << team2CityAndName << endl;
    
      cout << "\t\t\t" << setw(3) << setfill ('0') << t1.getScore() << "\t\t\t\t\t\t" << setw(3) << setfill ('0') << t2.getScore() << endl;
      cout << endl;
      cout << "\t\t\t" << "Fouls" << "\t\t\t\t\t" << "Fouls" << endl;
      cout << "\t\t\t" << setw(3) << setfill ('0') << t1.getFouls() << " " << "\t\t\t\t\t" << setw(3) << setfill ('0') << t2.getFouls() << endl;
      cout << endl;
      cout << "\t\t\t" << "Timeouts" << "\t\t\t\t" << "Timouts" << endl;
      cout << "\t\t\t" << setw(3) << setfill ('0') << t1.getTimeout() << " " << "\t\t\t\t\t" << setw(3) << setfill ('0') << t2.getTimeout() << endl;

      string team1Coach = t1.getCoachName();
      string team2Coach = t2.getCoachName();
      team1Coach.resize(15);
      team2Coach.resize(15);
      cout << "\n\n\nCoach:\t\t" << team1Coach << "\t\t\t\t" << team2Coach << endl;
    
  }  

  void showScoreboard(Team &t1, Team &t2)
  {
    char choice;
    int homeScore = t1.getScore();
    int visitorScore = t2.getScore();


    string team1CityAndName = t1.getHomeCity() + " " + t1.getName();  //combines city and team names  
    string team2CityAndName = t2.getHomeCity() + " " + t2.getName();

    if (t1.getHomeStatus() == true && t2.getHomeStatus() == true){                         //Checks if both team home status are different

      cout << colorR << "\nERROR: Both teams cannot be the home team." << reset <<  endl;
      cout << "A. " << team1CityAndName << endl;
      cout << "B. " << team2CityAndName << endl;
      cout << "Please select one to change to the visitors team: ";
      choice = validateChar(choice);

      if (choice == 'A' || choice == 'a'){
        t1.setHomeStatus(false);
      } else { 
        t2.setHomeStatus(false);
      }
    } else if (t1.getHomeStatus() == false && t2.getHomeStatus() == false){

      cout <<colorR <<  "\nERROR: Both teams cannot be the visiting team." << reset << endl;
      cout << "A. " << team1CityAndName << endl;
      cout << "B. " << team2CityAndName << endl;
      cout << "Please select one to change to the home team: ";
      choice = validateChar(choice);

      if (choice == 'A' || choice == 'a'){
        t1.setHomeStatus(true);
      } else { 
        t2.setHomeStatus(true);
      }
    }
    
    if (t1.getHomeStatus() == true){
      scoreboardGUI(t1, team1CityAndName, t2, team2CityAndName);
    } else {
      scoreboardGUI(t2, team2CityAndName, t1, team1CityAndName);
    }
  
    
    
  }
};
void setTeamInfo(Team &t, int teamNum){
  string userInput = "", userInput2 = "";
  cout << "\nEnter the name of team " << teamNum << ": ";
  userInput = validateString(userInput);
  t.setName(userInput);

  cout << "Who is the " << t.getName() << " head coach (first and last name): ";
  cin >> userInput >> userInput2;
  userInput = userInput + " " + userInput2;
  t.setCoachName(userInput);

  cout << "What city are they from: ";
  userInput = validateString(userInput);
  t.setHomeCity(userInput);
  
  do{
    cout << "Are the " << t.getHomeCity() << " " << t.getName() << " the home team (y/n): ";
    cin >> userInput;
    if (userInput == "y" || userInput == "Y")
        {
          t.setHomeStatus(true);
        } 
        else if (userInput == "n" || userInput == "N")
        {
          t.setHomeStatus(false);
        } 
        else if (userInput != "y" && userInput != "Y" && userInput != "n" && userInput != "N" ){
        cout << "ERROR: \"" << userInput << "\" is not valid." << endl;
        }
      } while (userInput != "y" && userInput != "Y" && userInput != "n" && userInput != "N");
}
void showMenu()
{
  cout << underline << navy << "\n\nMENU" << reset << endl
  << "\nA: Update the score" << endl
  << "B: Update foul count" << endl
  << "C. Update Team Cities" << endl
  << "D. Update Team Names" << endl
  << "E. Update Team Timeout Counts" << endl
  << "F. Update Coaches names" << endl
  << colorR << "\nQ: Quit program" << endl
  << "R. Reset scoreboard" << reset << endl;


  cout << "\nPlease make a choice: ";
  
}

void handleOption(char i, Team &t1, Team &t2){
  char choice;
  string s = "";
  int n;
  if (i == 'A' || i == 'a'){
    cout << "\nWhich team would you like to update the score for" << endl;
    cout << "A. " << t1.getName() << endl;
    cout << "B. " << t2.getName() << endl;
    cout << "Please make a choice: ";
    choice = validateChar(choice);
     { if (choice == 'A' || choice == 'a'){
        cout << "New score: ";
        cin >> n;
        t1.setScore(n);
      }
      else if (choice == 'B' || choice == 'b'){
        cout << "New score: ";
        cin >> n;
        t2.setScore(n);
      } else {
        cout << "ERROR: \"" << choice << "\"is not a valid choice." << endl;
        }
     }
  
  }
  else if (i == 'B' || i == 'b'){
    cout << "\nWhich team would you like to update the fouls for" << endl
    << "A. " << t1.getName() << endl
    << "B. " << t2.getName() << endl
    << "Please make a choice: "; 
    choice = validateChar(choice);
     { if (choice == 'A' || choice == 'a'){
        cout << "New fouls: ";
        cin >> n;
        t1.foulCount(n);
      }
      else if (choice == 'B' || choice == 'b'){
        cout << "New fouls: ";
        cin >> n;
        t2.foulCount(n);
      } else {
        cout << "ERROR: \"" << choice << "\"is not a valid choice." << endl;
        }
     } 
  }
  else if (i == 'C' || i == 'c'){
    cout << "\nWHich team would you like to update their city?" << endl
    << "A. " << t1.getName() << endl
    << "B. " << t2.getName() << endl
    << "Please make a choice: ";
    choice = validateChar(choice);

     { if (choice == 'A'|| choice == 'a'){
        cout << "New city for " << t1.getName() << " is ";
        cin >> s;
        t1.setHomeCity(s);
      }
      else if (choice == 'B' || choice == 'b'){
        cout << "New city for " << t2.getName() << " is ";
        cin >> s;
        t2.setHomeCity(s);
      } else {
        cout << "ERROR: \"" << choice << "\"is not a valid choice." << endl;
        }
     }
  }
  else if (i == 'D' || i == 'd') {
    cout << "Which team would you like to update their name:" << endl
      << "A. " << t1.getName() << endl
      << "B. " << t2.getName() << endl
      << "Please make a choice: ";
      choice = validateChar(choice);
      { if (choice == 'A' || choice == 'a'){
          cout << "New name: ";
          cin >> s;
          t1.setName(s);
        }
        else if (choice == 'B' || choice == 'b'){
          cout << "New name: ";
          cin >> s;
          t2.setName(s);
        } else {
        cout << "ERROR: \"" << choice << "\"is not a valid choice." << endl;
        }

  }
}
else if (i == 'E' || i == 'e') {
    cout << "Which team would you like to update the timeout count:" << endl
      << "A. " << t1.getName() << endl
      << "B. " << t2.getName() << endl
      << "Please make a choice: ";
      choice = validateChar(choice);
      { if (choice == 'A' || choice == 'a'){
          cout << "New timeout count: ";
          cin >> n;
          t1.setTimeoutCount(n);
        }
        else if (choice == 'B' || choice == 'b'){
          cout << "New timeout count: ";
          cin >> n;
          t2.setTimeoutCount(n);
        } else {
        cout << "ERROR: \"" << choice << "\"is not a valid choice." << endl;
        }

  }
}
else if (i == 'F' || i == 'f'){
    cout << "\nWhich team's coaches name would you like to update?" << endl
    << "A. " << t1.getName() << endl
    << "B. " << t2.getName() << endl
    << "Please make a choice: ";
    choice = validateChar(choice);

     { if (choice == 'A' || choice == 'a'){
        cout << t1.getName() << " New coach is ";
        cin >> s;
        t1.setCoachName(s);
      }
      else if (choice == 'B' || choice == 'b'){
        cout << t2.getName() << " New coach is ";
        cin >> s;
        t2.setCoachName(s);
      } else {
        cout << "ERROR: \"" << choice << "\"is not a valid choice." << endl;
        }
     }
  } else if (i == 'Q' || i == 'q'){
    cout << "Goodbye...";
  } else if (i == 'R' || i == 'r'){
    cout << "\033[2J\033[1;1H";
    cout << "\nFootball Game" << endl;
    setTeamInfo(t1, 1);
    setTeamInfo(t2, 2);
  }
}


#endif