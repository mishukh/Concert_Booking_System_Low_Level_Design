#pragma once
#include<bits/stdc++.h>
#include "Concert.cpp"
using namespace std;





class Concert_DB{

public:

  unordered_map<string,multiset<Concert*>>registry;
  unordered_set<Concert*>st;


  void insert_Concert(Concert *c){
      string id = to_string(c->id);
      string artist = c->artist;
      string date = c->date;
      string venue = c->venue;
      string time = c->time;


      registry[artist].insert(c);
      registry[date].insert(c);
      registry[venue].insert(c);
      registry[time].insert(c);
      registry[id].insert(c);

      st.insert(c);

  }


    void remove_Concert(Concert *c){
      string id = to_string(c->id);
      string artist = c->artist;
      string date = c->date;
      string venue = c->venue;
      string time = c->time;

      vector<string>temp = {id,artist,date,venue,time};


      for(auto i : temp)
      {
          auto it = registry[i].find(c);

          if(it!=registry[i].end())
          registry[i].erase(it);
      }


      auto it  = st.find(c);

      if(it!=st.end())
      st.erase(it);

  }



};
