#include <iostream>             // standard library
#include <cstdlib>
//#include <iomanip>            // I/O manipulation
//#include <cctype>             // checking if input is numeric or not
#include <ctime>
#include "dice.h"               // including "dice.h" that runs the calculations of dices.
//#include "bet.h"
//#include "balance.h"
int credits = 0;                //Bet amount for the current round (x/3)
int balance = 0;                //Account balance
int play = 1;                   //To play or not to play?
int pla_round = 0;              //Player's winning rounds (x/3)
int npc_round = 0;              //NPC winning rounds (x/3)
int bet = 0;                    //Bet amount for the current round (x/3)
int dice1 = rand() % 6 + 1;     //Dice 1
int dice2 = rand() % 6 + 1;     //Dice 2
int D1 = 0;                     //Player's highest dice
int D2 = 0;                     //NPC highest dice
int minbalance = 0;             //Minimum value account balance
int maxbalance = 5000;          //Maxium(lol) value account balance

using namespace std;

int main()
{
//1///////////////////////////////////////////////////////////////////////////////////////////////////
        string startblock;
        srand(time(0));
//////////////////////////////////////////////////////////////////////////////////////////////////////
    while (play){
        cout << "Type play to play, options to edit account balance or exit to quit." << endl;
        cin >> startblock;

            if (startblock == "play"){
//2///////////////////////////////////////////////////////////////////////////////////////////////////
                while (D1 <= 2 && D2 <= 2){
                    cout << "Dice 1: " << dice1 << endl;
                    cout << "Dice 2: " << dice2 << endl;
                    cin >> D1;
                    cout << "Dice 1: " << dice1 << endl;
                    cout << "Dice 2: " << dice2 << endl;
                    cin >> D2;
                }
//////////////////////////////////////////////////////////////////////////////////////////////////////
            if (startblock == "options"){
                cout << "Your current balance is: " << balance << "/5000" << endl;
                cout << "Insert coins to play. (Up to a total of 5000 is accepted.)" << endl;
                cin >> credits;

                balance = balance + credits;
                }

            if (startblock == "options" && credits <= maxbalance  && credits > minbalance){
                cout << "You have deposited " << credits << endl;
                cout << "Your current balance is: " << balance << "/5000" << endl;
                }

            else if (startblock == "options" && credits>maxbalance){
                cout << "Max total deposit is 5000. Your balance has been adjusted to 5000." << endl;
                cout << "You have deposited " << "5000/5000" << endl;

                credits = minbalance;
                balance = maxbalance;
                }

            else if (startblock == "options" && credits<minbalance){
                cout << "Negative value, please try again." << endl;

                credits = minbalance;
                balance = minbalance;
                }

            if (startblock == "exit"){
            play=0;
            }
        }
    }
}
