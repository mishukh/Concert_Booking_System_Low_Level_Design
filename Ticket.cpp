#pragma once
#include<bits/stdc++.h>
#include "Concert.cpp"
using namespace std;

class User;

class Ticket{

public:

  string user_id;
  string user_name;
  string user_email;
  string user_phno;
  string concert_id;
  string concert_name;
  string concert_venue;
  string concert_artist;
  string concert_date;
  string concert_time;
  vector<pair<int,int>>positions;
  int amount;


  Ticket(User* user,Concert* concert,int amount,vector<pair<int,int>>p);

  void get_details(Ticket* it){

        cout<<"\n----------------------\n";

        cout<<"User ID : "<<it->user_id<<'\n';
        cout<<"User Name : "<<it->user_name<<'\n';
        cout<<"User Email : "<<it->user_email<<'\n';
        cout<<"User Phone_Number : "<<it->user_phno<<'\n';
        cout<<"Concert ID : "<<it->concert_id<<'\n';
        cout<<"Concert Name : "<<it->concert_name<<'\n';
        cout<<"Concert Venue : "<<it->concert_venue<<'\n';
        cout<<"Concert Date : "<<it->concert_date<<'\n';
        cout<<"Concert Time : "<<it->concert_time<<'\n';
        cout<<"Concert Artist : "<<it->concert_artist<<'\n';
        cout<<"Concert Ticket Charge : "<<it->amount<<'\n';
        cout<<"Concert Seat positions : \n";
        for(auto pt : positions)
        {
           cout<<"Row|Col : "<<pt.first<<"|"<<pt.second<<'\n';
        }
        cout<<"\n----------------------\n";

  }

};

#include "User.cpp"

inline Ticket::Ticket(User* user,Concert* concert,int amount,vector<pair<int,int>>p){
    this->user_id = to_string(user->id);
    this->user_name = user->name;
    this->user_email = user->email;
    this->user_phno = user->ph_no;
    this->concert_id = to_string(concert->id);
    this->concert_name = concert->artist;
    this->concert_venue = concert->venue;
    this->concert_artist = concert->artist;
    this->concert_date = concert->date;
    this->concert_time = concert->time;
    this->positions = p;
    this->amount = amount;
}