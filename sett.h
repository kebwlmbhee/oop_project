#ifndef _SETT_H_
#define _SETT_H_
#include "meal.h"




class sett:public meal{
public:
	sett(){};
	sett(int no,string nam,int price):meal(no,nam,price){ //inherience from meal
		drink = 21;
		side_dish = 11;
	}

	int GetDrink();
	int GetSideDish();
	void SetDrink(int ch);
	void SetSideDish(int ch);

private:
	int drink;
	int side_dish;
};


static sett s[10]; //menu(for sett class)
static queue<sett> q_s, q_s2;   //queue for recode sett


#endif
