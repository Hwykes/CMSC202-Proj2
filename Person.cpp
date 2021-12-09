#include "Person.h"

/* Title: Person.cpp
** Author: Henry Wykes
** Date: 10/7/2021
** Description: 
** Course/Section: CMSC 202 Section 21 (FA21)
*/

// Name: Person
// Desc - Default Constructor for a Person
// Preconditions - Creates a Person with no data associated with it
// Postconditions - a Person is created
Person::Person(){
  SetDetails(" ", " ", 0, 0);
}

// Name: Person
// Desc - Overloaded Constructor for a Person
// Preconditions - Creates a Person with passed data
// Postconditions - a Person is created
Person::Person(string fName, string lName, int age, int id){
  SetDetails(fName, lName, age, id);
}

// Name: AddFriend
// Desc - A person pointer is stored from the roster of people in an organization
// Preconditions - A person pointer is passed
// Postconditions - A person pointer is added to this person's m_friend's array
//                  if not at maximum and not already in the array
void Person::AddFriend(Person* newFriend){
  bool friendFound = false;
  int friendID = newFriend->m_ID;
  friendFound = CheckID(friendID);
  if (friendFound == false){
    m_friends[m_friendCount] = newFriend;
    cout << "You are now friends with " << newFriend->m_fName << "!" << endl;
    m_friendCount++;
  }
  else {
    cout << "This person is already your friend" << endl;
  }
}

// Name: RemoveFriend
// Desc - Removes a person pointer from this person's m_friend array
// Preconditions - Person pointer exists in m_friend
// Postconditions - Person is removed from m_friend and all pointers are moved towards front
void Person::RemoveFriend(){
  int choice = 0;
  if (m_friendCount > 0){
    while (choice > m_friendCount || choice < 1){
      DisplayFriends();
      cout << "Who would you like to remove?" << endl;
      cin >> choice;
    }
    for (int i = choice-1; i < m_friendCount; i++){
      m_friends[i] = m_friends[i+1];
    }
    m_friendCount--;
  }
  else {
    cout << "You don't have friends yet" << endl;
  }
}  

// Name: CheckID
// Desc - Checks to see if a specific person ID exists in m_friends - Note: IDs will always be unique in proj2
// Preconditions - m_friends is populated
// Postconditions - Returns true if id exists in m_friends else false
bool Person::CheckID(int id){
  bool idFound = false;
  for (int i = 0; i < m_friendCount; i++){
    if (id == m_friends[i]->m_ID){
      idFound = true;
      return idFound;
    }
  }
  return idFound;
}

// Name: DisplayFriends
// Desc - Displays information about each friend in the m_friend array
// Preconditions - People are in the m_friend array
// Postconditions - Displays information about person object in array
void Person::DisplayFriends(){
  cout << "Friends list of " << m_fName << endl;
  if (m_friendCount > 0){
    for (int i = 0; i < m_friendCount; i++){
      cout << i+1 << ". ";
      m_friends[i]->DisplayDetails();
    }
  }
  else {
    cout << "You don't have friends yet" << endl;
  }
}

// Name: DisplayDetails
// Desc - Displays information about this person
// Preconditions - Person data is populated
// Postconditions - Displays information about person object
void Person::DisplayDetails(){
  cout << m_fName << " " << m_lName << " " << m_age << " " << m_ID << endl;
}

// Name: SetDetails
// Desc - Used as a setter for first name, last name, age, and id
// Preconditions - Person already created
// Postconditions - Member variables populated
void Person::SetDetails(string fName, string lName, int age, int id){
  m_fName = fName;
  m_lName = lName;
  m_age = age;
  m_ID = id;
}

