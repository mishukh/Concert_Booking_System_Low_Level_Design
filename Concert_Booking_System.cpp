#ifndef CONCERT_SYSTEM_MAIN
#define CONCERT_SYSTEM_MAIN

#include<bits/stdc++.h>
#include "Concert.cpp"
#include "User.cpp"
#include "Ticket.cpp"
#include "Payment_Service.cpp"
#include "Ticket_Booking_Service.cpp"
#include "Notification_Service.cpp"
#include "Concert_DB.cpp"
#include "Search_Service.cpp"

int ConcertID=0;
int UserID = 0 ;

class Concert_Booking_System{
public:
   Notification_Service*  notification_service;
   Ticket_Booking_Service* ticket_booking_service;
   Search_Service* search_service;
   Concert_DB* concert_DB;

   Concert_Booking_System() {
       ticket_booking_service = new Ticket_Booking_Service();
       search_service = new Search_Service();
       concert_DB = new Concert_DB();
   }
};

int main()
{
      Concert_Booking_System* cbs = new Concert_Booking_System();

      Concert* c1 = new Concert(++ConcertID,"Arijit Singh","Kolkata","01/05/2026","04:00pm",5,5,400);
      Concert* c2 = new Concert(++ConcertID,"Sonu Nigam","Mumbai","16/04/2026","06:00pm",6,8,500);
      Concert* c3 = new Concert(++ConcertID,"Udit Narayan","Kolkata","21/04/2026","04:30pm",5,5,350);
      
      cbs->concert_DB->insert_Concert(c1);
      cbs->concert_DB->insert_Concert(c2);
      cbs->concert_DB->insert_Concert(c3);

      User* u1 = new User(++UserID,"Mishukh","ms@gmail.com","1234567890");
      User* u2 = new User(++UserID,"Ram","ram@gmail.com","1244567890");
      User* u3 = new User(++UserID,"Sham","sham@gmail.com","1237567898");
      User* u4 = new User(++UserID,"Joe","joe@gmail.com","1234567899");
      
      //Search Concerts by various paramters
      cbs->search_service->Search_Concerts("Kolkata",cbs->concert_DB);

      //Search Available Concerts
      cbs->search_service->View_Available_Concerts(cbs->concert_DB);

      //Ticket Booking Phase
      vector<pair<int,int>>pu1;
      pu1.push_back({1,2});
      pu1.push_back({1,3});
      
      int amount = cbs->ticket_booking_service->book_ticket(u1,cbs->concert_DB,pu1,to_string(c1->id),c1->seatfee);
      
      Payment_Service* ps = new PhonePeAdapter(new PhonePe());
      ps->pay(amount);

      cbs->notification_service = new Notification_Service(new SMS());
      cbs->notification_service->notify(u1,cbs->ticket_booking_service->get_ticket(u1,cbs->concert_DB,to_string(c1->id),amount,pu1));

      vector<pair<int,int>>pu2;
      pu2.push_back({2,0});
      pu2.push_back({3,1});
      
      amount = cbs->ticket_booking_service->book_ticket(u2,cbs->concert_DB,pu2,to_string(c2->id),c2->seatfee);
      
      Payment_Service* ps2 = new GPayAdapter(new GPay());
      ps2->pay(amount);

      cbs->notification_service->set_notification_service(new Email());
      cbs->notification_service->notify(u2,cbs->ticket_booking_service->get_ticket(u2,cbs->concert_DB,to_string(c2->id),amount,pu2));



      cbs->search_service->View_Available_Concerts(cbs->concert_DB);

}

#endif