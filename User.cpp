#pragma once
#include<bits/stdc++.h>

using namespace std;

class Ticket;

struct TicketCompare {
    bool operator()(const Ticket* a, const Ticket* b) const {
        return a < b; 
    }
};

class User{
public:

int id;
string name;
string email;
string ph_no;
unordered_set<Ticket*>booked_concerts;

  User(int id, string name, string email, string ph_no)
  {
      this->id = id;
      this->name = name;
      this->email = email;
      this->ph_no = ph_no;
  }

  void get_booked_concerts();

};

#include "Ticket.cpp"

inline void User::get_booked_concerts(){

    if(booked_concerts.size()==0)
    {
       cout<<"\n You haven't booked any concert yet\n";
       return;
    }

   cout<<"\n  : Booked Concerts by you :  \n";

    for(auto it : booked_concerts)
    {
        it->get_details(it);
    }
}