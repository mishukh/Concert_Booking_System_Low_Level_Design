#pragma once
#include<bits/stdc++.h>
#include "User.cpp"
#include "Ticket.cpp"

using namespace std;

class Notification_System {
public:
   virtual void notify(User* user,Ticket* ticket)=0;
   virtual ~Notification_System(){};
};

class SMS : public Notification_System {
public:
   void notify(User* user , Ticket* ticket){
          cout<<"\n---- Notify via SMS -----\n";
          cout<<"\n Your Ticket is Booked \n";
          cout<<"\n UserName : "<<user->name<<'\n';
          cout<<"\n Phone_Number : "<<user->ph_no<<'\n';
          ticket->get_details(ticket);
   }
};

class Email : public Notification_System {
public:
   void notify(User* user , Ticket* ticket){
          cout<<"\n---- Notify via Email -----\n";
          cout<<"\n Your Ticket is Booked \n";
          cout<<"\n UserName : "<<user->name<<'\n';
          cout<<"\n Email : "<<user->email<<'\n';
          ticket->get_details(ticket);
   }
};

class Notification_Service {
Notification_System* nst;
public:
    Notification_Service(Notification_System *st){
          this->nst  = st;
    }
    void set_notification_service(Notification_System *st)
    {
      nst = st;
    }
    void notify(User* user , Ticket* ticket)
    {
        nst->notify(user , ticket);
    }
};