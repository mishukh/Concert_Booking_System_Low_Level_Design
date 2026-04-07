#pragma once
#include<bits/stdc++.h>
using namespace std;





class Concert{
public:

  int id;
  string artist;
  string venue;
  string date;
  string time;
  bool available;
  int count;
  int seatfee;

  vector<vector<int>>seat;




    Concert(int id, string artist, string venue, string date, string time,int row, int col,int seatfee){
      this->id = id;
      this->artist = artist;
      this->venue = venue;
      this->date = date;
      this->time = time;
      this->available=true;
      this->count=0;
      this->seatfee = seatfee;

      seat.resize(row,vector<int>(col,0));
    }


   void fillSeat(vector<pair<int,int>>positions){

         for(auto it : positions){
              int r = it.first;
              int c = it.second;

              seat[r][c]=1;
              count++;

         }


         if(count==(seat.size()*(seat[0].size())))
         {
            available = false;
         }


   }


};