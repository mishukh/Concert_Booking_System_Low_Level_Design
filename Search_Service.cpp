#pragma once
#include<bits/stdc++.h>
#include "Concert.cpp"
#include "Concert_DB.cpp"
using namespace std;





class Search_Service{
public:




  void Search_Concerts(string type, Concert_DB* cdb){
   
    int count = cdb->registry[type].size();


    if(count>0)
    {
       cout<<"\n Available concerts for "<<type<<" : \n";
       


       for(auto it : cdb->registry[type])
       {
            
            cout<<"ConcertID : "<<it->id<<'\n';
            cout<<"Artist : "<<it->artist<<'\n';
            cout<<"Venue : "<<it->venue<<'\n';
            cout<<"Date : "<<it->date<<'\n';
            cout<<"Time : "<<it->time<<'\n';
            cout<<"SeatPrice : "<<it->seatfee<<'\n';

            cout<<"\n";
       }
    }
    else
    {
        cout<<"\n no available concerts there\n";
    }



  }


  void View_Available_Concerts(Concert_DB* cdb){
       

       if((cdb->st).size()==0)
       {
          cout<<"\n no available concerts there\n";
          return;
       }


       for(auto it : cdb->st)
       {
          bool available = it->available;

          
          if(available)
          {
             cout<<"\n ConcertID : "<<it->id<<'\n';
             cout<<"\n Per Seat Price is  : "<<it->seatfee<<'\n';

             for(int i=0;i<(it->seat.size());i++)
             {
               for(int j=0;j<((it->seat)[0].size());j++)
               {
                   cout<<it->seat[i][j]<<"|";
               }
               cout<<'\n';
             }
          }
       }
  }


};