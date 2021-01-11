#include "meal.h"

using namespace std;


//initialization list
meal::meal(int newid, string newname, int newprice)
    :id(newid), name(newname), price(newprice), num(0){}


void meal::Setnum(){
    int newnum;
    cin >> newnum;
    num = newnum;
}

int meal::Getid(){
    return id;
};

string meal::Getname(){
    return name;
}

int meal::Getprice(){
    return price;
}

int meal::Getnum(){
    return num;
}

