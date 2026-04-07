#pragma once
#include<bits/stdc++.h>
#include "User.cpp"
#include "Concert_DB.cpp"
#include "Payment_Service.cpp"
#include "Ticket.cpp"

using namespace std;

class Ticket_Booking_Service{
public:

    int book_ticket(User* user,Concert_DB* cdb, vector<pair<int,int>>positions, string concert_id, int amount){
       
        auto mt = cdb->registry[concert_id];
        if(mt.empty()) return 0;
        
        auto concert = *mt.begin();
        

        concert->fillSeat(positions); 

        
        return positions.size()*amount;

    }

    Ticket* get_ticket(User* user, Concert_DB* cdb, string concert_id,int amount,vector<pair<int,int>>positions)
    {
        auto mt = cdb->registry[concert_id];
        if(mt.empty()) return nullptr;
        auto concert = *mt.begin();

        Ticket* tkt = new Ticket(user,concert,amount,positions);
        user->booked_concerts.insert(tkt);

        return tkt;
    }

};
