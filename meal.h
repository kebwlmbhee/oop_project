// meal.h

#ifndef _MEAL_H_
#define _MEAL_H_

#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#define N 40


using namespace std;
//class

class meal {
private:
    int id;
    string name;
    int num;

protected:		//for inheritance
    int price;
public:
    meal(int, string, int);     //ctor
    meal(){}                   //default ctor
    void Setnum();
    int Getid();
    string Getname();
    int Getprice();
    int Getnum();
};

static queue<meal> q, q2;	//queue for recoed meal
static meal m[N];		//meal information
static int sum;
static queue<int> flag, flag2;	//flag queue to determine choose combo or not




#endif


