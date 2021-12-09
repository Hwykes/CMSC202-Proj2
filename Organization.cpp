#include "Organization.h"

/* Title: Organization.cpp
** Author: Henry Wykes
** Date: 10/11/2021
** Description:
** Course/Section: CMSC 202 Section 21 (FA21)
*/

// Name: Organization
// Desc - Default constructor for Organization
// Preconditions - None
// Postconditions - Organization is created (empty) with 0 people in the roster
Organization::Organization(){
  m_name = " ";
  m_fileName = " ";
  m_numRoster = 0;
}

// Name: SetName
// Desc - Sets m_name by asking user for name
// Preconditions - m_name exists
// Postconditions - Asks user for the organization name and populates m_name
void Organization::SetName(){
  string name;
  cout << "What is the name of your organization?" << endl;
  cin >> name;
  m_name = name;
}

// Name: LoadRoster
// Desc - Sets m_fileName by asking user. Then populates all of the people loaded from file
// Preconditions - m_fileName exists. m_roster empty
// Postconditions - Asks user for m_fileName. Loads data from file and populates m_roster
void Organization::LoadRoster(){
  string fName, lName, age, id;
  const char DELIMITER = ',';
  m_fileName = FILE_NAME;
  ifstream myFile(m_fileName);
  if(myFile.is_open()){
    for (int i = 0; i < MAX_PEOPLE; i++){
      Person newPerson;
      getline(myFile, fName, DELIMITER);
      getline(myFile, lName, DELIMITER);
      getline(myFile, age, DELIMITER);
      getline(myFile, id);
      int ageNum = stoi(age, nullptr);
      int idNum = stoi(id, nullptr);
      newPerson.SetDetails(fName, lName, ageNum, idNum);
      m_roster[i] = newPerson;
      m_numRoster++;
    }
    cout << m_numRoster << " people loaded into the roster" << endl;
  }
  else{
    cout << "Unable to open file" << endl;
  }
  myFile.close();
}

// Name: DisplayRoster
// Desc - Displays a numbered list of everyone in the roster (starts at 1)
// Preconditions - m_roster is populated
// Postconditions - Displays a numbered list of people
void Organization::DisplayRoster(){
    for (int i = 0; i < m_numRoster; i++){
      cout << i+1 << ". ";
      m_roster[i].DisplayDetails();
    }
}

// Name: GetPerson
// Desc - Displays a list of people in m_roster and user enters number of desired person.
//        Returns pointer of that person in m_roster
// Preconditions - m_roster is populated
// Postconditions - Returns pointer for the person chosen from list
Person* Organization::GetPerson(){
  int choice;
  DisplayRoster();
  cout << "Who would you like to friend?" << endl;
  cin >> choice;
  Person* newFriend = &m_roster[choice-1];
  return newFriend;
}
