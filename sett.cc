#include <iostream>
#include <string>
#include "sett.h"
using namespace std;


int
sett::GetDrink(){
	return drink;
}

int
sett::GetSideDish(){
	return side_dish;
}

void
sett::SetDrink(int ch){
	int chh = ch;
	while((chh<21) || (chh>26)){ //If choose other NO, ask him for correct NO
		cout << "\n\tPlease choose NO.21-26."<<endl;
		cout << "\n\tEnter NO. : ";
		cin >> chh;
	}
	//pay the difference.
	drink = chh;
	if(chh==23 || chh==26){
		price +=30;
	}
	else if(chh==24) price+=10;
	else if(chh==25) price+=20;
}


void
sett::SetSideDish(int ch){
	int chh = ch;
	while((chh<11) || (chh>16)){//choose other NO, ask him for correct NO
		cout << "\n\tPlease choose NO.11-16."<<endl;
		cout << "\n\tEnter NO. : ";
		cin >> chh;
	}
	side_dish= chh;
	//pay the difference.
	if(chh==12 || chh==15){
		price +=20;
	}
	else if(chh==14) price+=10;
	else if(chh==16) price+=10;
}

