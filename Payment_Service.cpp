#pragma once
#include<bits/stdc++.h>

using namespace std;

class Payment_Service{
public:

  virtual void pay(int amount)=0;
  virtual ~Payment_Service(){};

};

class PhonePe {
public:

    void pay_Phonepe(int amount)
    {
        cout<<"\nPayment via PhonePe of amount : "<<amount<<" is done\n";
    }

};

class PhonePeAdapter : public Payment_Service{
PhonePe* pt;

public:

    PhonePeAdapter(PhonePe* pt){
      this->pt = pt;
    }

    void pay(int amount) override {
        pt->pay_Phonepe(amount);
    }

};


class GPay {
public:


    void pay_GPay(int amount)
    {
        cout<<"\nPayment via GPay of amount : "<<amount<<" is done\n";
    }


};


class GPayAdapter : public Payment_Service{
GPay* pt;

public:

    GPayAdapter(GPay* pt){
      this->pt = pt;
    }

    void pay(int amount) override {
        pt->pay_GPay(amount);
    }

};
