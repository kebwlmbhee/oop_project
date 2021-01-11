// main function

#include "meal.h"
#include "sett.h"

void welcome();
void start();
void step();
void choose_1_print();
void choose_2_print();
void choose_combo_or_not(meal m[N]);
void order_sth1();
void order_sth2();
void print();

int main() {
    start();
    return 0;
}

void welcome(){
    cout << "\t\t\t\t\tWelcome to xxXXxx Restaurant" << endl;
}

//print main menu
void step(){
    cout << "\
         ===================================================================================================\n\
         ||   Choose the option to start  1. A La Carte                                                   ||\n\
         ||                               2. Combo Meal(Main Dish, Side Dish, Drink)                      ||\n\
         ||                                                                                               ||\n\
         ||                           press -1 to exit order                                              ||\n\
         ||                                                                                               ||\n\
         ===================================================================================================\n\
";
}

//print menu 1
void choose_1_print(){
        cout << "\
                                          A La carte                                                \n\
                                                                                                    \n\
                                          Main Dish                                                 \n\
                                                                                                    \n\
                1. Hamburger      $89   2. Chessburger          $79     3.Double Chessburger   $99  \n\
                4. Banconburger   $79   5. Double Baconburger   $99     6.Big Mac              $109 \n\
                                                                                                    \n\
                                                                                                    \n\
                                          Side Dish                                                 \n\
                                                                                                    \n\
                11. French Fries  $39   12. French Fries(Big)   $59     13. Apple Slices        $39 \n\
                14. Side Salad    $49   15. Ice Cream           $59     16. Crispy Chicken      $49 \n\
                                                                                                    \n\
                                            Drink                                                   \n\
                                                                                                    \n\
                21. Cola          $39   22. Lemon Tea           $39     23. Chocolate Shake     $69 \n\
                24. Orange juice  $49   25. Hot Chocolate       $59     26. Strawberry Shake    $69 \n\
";
}

//print menu 2
void choose_2_print(){
        cout << "\
                            Combo Meal(Main Dish, Side Dish, Drink)                                           \n\
                                                                                                              \n\
                 1. Hamburger Set   $149   2. Chessburger Set       $139     3.Double Chessburger Set  $159   \n\
                                                                                                              \n\
                 4. Banconburger Set $139  5. Double Baconburger Set $159    6.Big Mac Set            $169    \n\
";
}



//stat ordering
void choose_combo_or_not(meal m[N]){
    int order_way = 0;
    sum = 0;
    while(order_way != -1){
        step();
        cin >> order_way;
	if(order_way != -1)	//when order_way not -1, recode on flag queue
            flag.push(order_way);
        if(order_way == 1){
            choose_1_print();
            order_sth1();//choose a la carte

        }
        else if(order_way == 2){
            choose_2_print();
            order_sth2(); //choose combo meal
        }
        else if(order_way == -1){
            if(!q.empty()){
                print();
                cout << "\t========================================================================================\n";
                cout << setw(88) << "Total Consume : " << sum << endl;
                break;
            }
            else{ // no consume
                cout << "bye bye! "<< endl;
            }
        }
        else{
            cout << "Error! Please press again!" << endl;
        }
    }
}


void order_sth1()
{
    int NO = 0;
    cout << "\n\tEnter NO. : ";
    cin >> NO;
    if((NO >= 1 && NO <= 6) || (NO >= 11 && NO <= 16) || (NO >= 21 && NO <= 26)){
        cout << "\n\tEnter the number of meals : ";
        m[NO].Setnum();		//input number of meal
        q.push(m[NO]);//put meal you ordered into queue

        print();
        sum += m[NO].Getprice() * m[NO].Getnum();	//count sum
        cout << "\t========================================================================================\n";
        cout << setw(88) << "Total Consume : " << sum << endl;
    }
    else
        cout << "\n\t\tWithout this option for meal! Please try again!\n\n";
}

void order_sth2()
{
    int NO = 0;
    int d=21; //default drink=cola
    int side=11;//default side-dish=french fries
    cout << "\n\tEnter NO. : ";
    cin >> NO;
    if((NO>=1 && NO <=6)){
        cout << "\n\tEnter the number of meals : ";
        s[NO].Setnum();
        cout << "\n\tChoose the drink : 21.Cola(+$0)            22.Lemon Tea(+$0)      23.Chocolate Shake(+$30)"
             << "\n\t                   24.Orange juice(+10$)   25.Hot Chocolate(+$20)   26.Strawberry Shak(+$30)" <<endl <<"\n\t";
        cout << "\n\tEnter NO. : ";
        cin >> d;
        s[NO].SetDrink(d);

        cout << "\n\tChoose the side dish : 11.French Fries(+$0)    12.French Fries(Big)(+$20)    13.Apple Slices(+$0)"
             << "\n\t                       14.Side Salad(+10$)     15.Ice Cream(+$20)            16.Crispy Chicken(+$10)" <<endl <<"\n\t";
        cout << "\n\tEnter NO. : ";
        cin>>side;
        s[NO].SetSideDish(side);

        q.push(s[NO]); //put meal you ordered into queue
        q_s.push(s[NO]); //put meal you ordered into set queue

        print();
        sum += s[NO].Getprice() * s[NO].Getnum();
        cout << "\t========================================================================================\n";
        cout << setw(88) << "Total Consume : " << sum << endl;
    }
    else
        cout << "\n\t\tWithout this option for meal! Please try again!\n\n";
}

void start(){

    //meal information
    m[1] = meal(1, "Hamburger", 89);
    m[2] = meal(2, "Chessburger", 79);
    m[3] = meal(3, "Double Chessburger", 99);
    m[4] = meal(4, "Baconburger", 79);
    m[5] = meal(5, "Double Baconburger", 99);
    m[6] = meal(6, "Big Mac", 109);

    m[11] = meal(11, "French Fries", 39);
    m[12] = meal(12, "French Fries(Big)", 59);
    m[13] = meal(13, "Apple Slices", 39);
    m[14] = meal(14, "Side Salad", 49);
    m[15] = meal(15, "Ice Cream", 59);
    m[16] = meal(16, "Crispy Chicken", 49);

    m[21] = meal(21, "Cola", 39);
    m[22] = meal(22, "Lemon Tea", 39);
    m[23] = meal(23, "Chocolate Shake", 69);
    m[24] = meal(24, "Orange juice", 49);
    m[25] = meal(25, "Hot Chocolate", 59);
    m[26] = meal(26, "Strawberry Shake", 69);

    s[1] = sett(1,"Hamburger Set",149);
    s[2] = sett(2,"Chessburger Set",139);
    s[3] = sett(3,"Double Chessburger Set",159);
    s[4] = sett(4,"Banconburger Set",139);
    s[5] = sett(5,"Double Baconburger Set",159);
    s[6] = sett(6,"Big Mac Set",169);

    welcome();
    choose_combo_or_not(m);
}


void print(){
    cout << "\t========================================================================================\n";
    cout << setw(11) << "NO." << setw(30) << "meal name" << setw(18) << "price" << setw(15) << "num" << setw(18) << "total\n";

    queue<meal> q2(q);  //copy queue, store original
    queue<sett> q_s2(q_s); //copy queue, store original
    queue<int> flag2(flag); //copy queue, store original

    while(!flag2.empty()){
       	cout << "\n\t" << q2.front().Getid() << "\t\t" << setw(22) << q2.front().Getname()
       	     << "\t\t" << q2.front().Getprice()<< "\t\t" << q2.front().Getnum() << "\t\t"
	     << q2.front().Getprice()*q2.front().Getnum() << endl;

    	if(flag2.front() == 2){
		string s1, s2;
		//connect string
		s1 = " + " + m[q_s2.front().GetDrink()].Getname();
		s2 = " + " + m[q_s2.front().GetSideDish()].Getname();
 		cout << setw(46) << s1 << endl; //print drink name
		cout << setw(46) << s2 << endl; //print side-dish name
		q_s2.pop();
        }
	q2.pop();
	flag2.pop();
    }
}

