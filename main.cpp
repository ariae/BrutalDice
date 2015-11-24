#include <iostream> // standardbibliotek för konsol
#include <iomanip>  // för att manipulera tecken inom kvotationstecken
#include <cctype>   // för att kolla om cin är numeriskt eller ej
#include "dice.h"   // inkludera dice.h som sköter uträkning av tärningar.
//#include "bet.h"
//#include "balance.h"
int credits=0;
int balance=0;
int play=1;
int pla_round=0;
int npc_round=0;
int bet=0;
int D1;
int D2;


using namespace std;

int main()
{
    string startblock;
    while (play){
        cout << "Type play to play, options to edit account balance or exit to quit." << endl;
        cin >> startblock;
    if (startblock == "play")
    {
        cout << "Oh, soy feast massage system! Bolat! Durka durk!" << endl;
        startblock = "play";
    }
    if (startblock == "options")
    {
        cout << "Your current balance is: " << balance << "/5000" << endl;
        cout << "Insert coins to play. (Up to a total of 5000 is accepted.)" << endl;
        cin >> credits;
        balance = balance + credits;
        startblock = "play";
    }
    if (startblock == "options" && credits<5000)
    {
        cout << "You have deposited " << credits << endl;
        cout << "Your current balance is: " << balance << "/5000" << endl;
        startblock = "play";
    }

// else if fungerar inte, hoppar över hela satsen
    else if (startblock == "options" && credits>=5000)
    {
        cout << "You have deposited " << "5000/5000" << endl;
        cout << "Max total deposit is 5000. Your balance has been adjusted to 5000." << endl;
        startblock = "play";
    }

    if (startblock == "exit")
        {
            play=0;
        }
    }
}
