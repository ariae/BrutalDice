#include <iostream>             // standardbibliotek för konsol
#include <cstdlib>
//#include <iomanip>            // för att manipulera tecken inom kvotationstecken
//#include <cctype>             // för att kolla om cin är numeriskt eller ej
#include <ctime>
#include "dice.h"               // inkludera dice.h som sköter uträkning av tärningar.
//#include "bet.h"
//#include "balance.h"
int credits = 0;                //Insättningsmängd
int balance = 0;                //Pengar på konto
int play = 1;                   //Spela eller inte spela?
int pla_round = 0;              //Spelarens vinster
int npc_round = 0;              //NPC vinster
int bet = 0;                    //Insats för runda
int dice1 = rand() % 6 + 1;     //Tärning 1
int dice2 = rand() % 6 + 1;     //Tärning 2
int D1 = 0;                     //Spelarens maxtärning
int D2 = 0;                     //NPC maxtärning
int minbalance = 0;             //Minsta värde konto
int maxbalance = 5000;          //Högsta värde konto

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
