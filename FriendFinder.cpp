#include "FriendFinder.h"

/* Title: FriendFinder.cpp
** Author: Henry Wykes
** Date: 10/9/2021
** Description:
** Course/Section: CMSC 202 Section 21 (FA21)
*/

// Name: FriendFinder
// Desc - Default constructor for application for finding friends
// Preconditions - Creates a Person and an organization
// Postconditions - Welcomes user and calls Start()
FriendFinder::FriendFinder(){
  Person m_me;
  Organization m_organization;
  cout << "*****************************" << endl;
  cout << "Welcome to UMBC Friend Finder" << endl;
  cout << "*****************************" << endl;
  Start();
}

// Name: GetDetails
// Desc - Asks user for their first name, last name, age, and ID to populate m_me
// Preconditions - None
// Postconditions - Populates information related to m_me
void FriendFinder::GetDetails(){
  string fName;
  string lName;
  int age;
  int id;
  int maxID = 9999999;
  int mixID = 1000000;
  cout << "What is your first name?" << endl;
  getline(cin, fName);
  cout << "What is your last name?" << endl;
  getline(cin, lName);
  cout << "What is your age?" << endl;
  cin >> age;
  cout << "What is your ID?" << endl;
  cin >> id;
  while (id > maxID || id < mixID){
    cout << "Please enter a valid ID number between 1000000 and 9999999" << endl;
    cin >> id;
  } 
  m_me.SetDetails(fName, lName, age, id);
}
 
// Name: DisplayMenu
// Desc - Displays main menu for application
// Preconditions - None
// Postconditions - Called from Start updates integer passed
void FriendFinder::DisplayMenu(int &choice){
  int maxChoice = 5;
  int minChoice = 1;
  cout << "What would you like to do?" << endl;
  cout << "1. Display Entire Organization" << endl;
  cout << "2. Display Friend List" << endl;
  cout << "3. Search for a Friend" << endl;
  cout << "4. Remove Friend" << endl;
  cout << "5. Exit" << endl;
  cin >> choice;
  while (choice > maxChoice || choice < minChoice){
    cout << "Please enter a valid choice (1-5):" << endl;
    cin >> choice;
  }
}

// Name: Start
// Desc - Main function running FriendFinder
//        Calls GetDetails
//        Populates data for organization
//        Continually calls DisplayMenu until someone enters 4 (exit)
// Preconditions - m_me and m_organization are created but not populated
// Postconditions - Runs until user enters 4. Thanks user for usage. Ends application
void FriendFinder::Start(){
  int choice = 0;
  int exit = 5;
  GetDetails();
  m_organization.SetName();
  m_organization.LoadRoster();
  while (choice != exit){
    DisplayMenu(choice);
    if (choice == 1){
      m_organization.DisplayRoster();
    }
    else if (choice == 2){
      m_me.DisplayFriends();
    }
    else if (choice == 3){
      Person* newFriend = m_organization.GetPerson();
      m_me.AddFriend(newFriend);
    }
    else if (choice == 4){
      m_me.RemoveFriend();
    }
  }
  cout << "Thanks for using the UMBC Friend Finder!" << endl;
}
