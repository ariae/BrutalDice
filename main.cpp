#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <iomanip>            // för att manipulera tecken inom kvotationstecken
//#include <cctype>             // för att kolla om cin är numeriskt eller ej

using namespace std;

int main()
{
    bool play = true;                   // Does the user WANT to play?
    string command;                     // Control block, what function is to be called

    srand(time(0));                     // Randomizer based on PC time (Not really random)

    // Cash variables
    int bet_credits;                    // Value to insert into account (acc_balance)
//    int bet_round;                      // Value to bet per match
    int acc_balance;                    // Digital account balance

    // Round values
    int round_number;                   // What round is being played
    int pla_win_round;                  // Player wins (out of 3)
    int npc_win_round;                  // Computer wins (out of 3)

    // Player dices
    int pla_dice_1;                     // Dice 1, player
    int pla_dice_2;                     // Dice 2, player
    int pla_dice_m;                     // Highest dice, player

    // Computer dices
    int npc_dice_1;                     // Dice 1, computer
    int npc_dice_2;                     // Dice 2, computer
    int npc_dice_m;                     // Highest dice, player

    // Account balance max/min value (acc_balance)
    int minbalance = 0;                 // Minsta värde konto
    int maxbalance = 5000;              // Högsta värde konto

    while (play)
    {
        cout << "Type play to play, options to edit account balance or exit to quit." << endl;
        cout << "> ";
        cin >> command;

        if (command == "play" && acc_balance >= 100){

                round_number++;

                pla_dice_1 = rand() % 6 + 1;
                pla_dice_2 = rand() % 6 + 1;
                pla_dice_m = max(pla_dice_1, pla_dice_2);  // Compares pla_dice_1 to pla_dice_2, and picks the highest and assigns it to pla_dice_m

                cout << endl;
                cout << "Round " << round_number << endl << endl;

                // Player roll
                cout << "Dice 1: " << pla_dice_1 << endl;
                cout << "Dice 2: " << pla_dice_2 << endl;
                cout << "Max   : " << pla_dice_m << endl;


                // NPC roll
                cout << endl << "NPC rolling..." << endl << endl;

                npc_dice_1 = rand() & (6 + 1);
                npc_dice_2 = rand() & (6 + 1);
                npc_dice_m = max(npc_dice_1, npc_dice_2); //Compares npc_dice_1 to npc_dice_2, and picks the highest and assigns it to npc_dice_m

                cout << "Dice 1: " << npc_dice_1 << endl;
                cout << "Dice 2: " << npc_dice_2 << endl;
                cout << "Max   : " << npc_dice_m << endl;

                cout << endl;
                cout << "Player max: " << pla_dice_m << ", NPC max: " << npc_dice_m << endl;

                if (pla_dice_m > npc_dice_m) {
                pla_win_round++;
                cout << "Player wins this round!" << endl;}

                else if(pla_dice_m < npc_dice_m) {
                npc_win_round++;
                cout << "NPC wins this round!" << endl;}

                else {
                cout << "Round is a tie! No winner..." << endl;}

// Checks the sum of won rounds
                cout << endl;
                cout << "Player has won " << pla_win_round << " round(s) so far." << endl;
                cout << "NPC has won " << npc_win_round << " round(s) so far." << endl;
                cout << endl;

// Check win state (Player or NPC)
                if (pla_win_round == 2 || npc_win_round == 2){
                    cout << "GAME OVER" << endl << endl;

                    if (pla_win_round > npc_win_round){
                        cout << "\a************" << endl;
                        cout << "PLAYER WINS!" << endl;
                        cout << "************" << endl << endl;
                        acc_balance = acc_balance + bet_credits * 2;
                        bet_credits = 0;}

                    else {
                        cout << "\a*********" << endl;
                        cout << "NPC WINS!" << endl;
                        cout << "*********" << endl << endl;

                        bet_credits = 0;}
                        play=false;}
        }

// Checking to see if you have the required minimum funds for gambling, and directing user to options function
        else if (acc_balance<100){
            cout << "You must insert credits into your virtual account!" << endl;

            command = "options";}

// The option block, where you can check account balance and insert funds
        else if (command == "options"){
            cout << "Your current balance is: " << acc_balance << "/5000" << endl;
            cout << "Insert coins to play. (Up to a total of 5000 is accepted.)" << endl;
            cin >> bet_credits;

            acc_balance = acc_balance + bet_credits;

                if (command == "options" && bet_credits <= maxbalance  && bet_credits > minbalance){
                    cout << "You have deposited " << bet_credits << endl;
                    cout << "Your current balance is: " << acc_balance << "/5000" << endl;}

                else if (command == "options" && bet_credits > maxbalance){
                    cout << "Max total deposit is 5000. Your balance has been adjusted to 5000." << endl;
                    cout << "You have deposited " << "5000/5000" << endl;

                    bet_credits = minbalance;
                    acc_balance = maxbalance;}

                else if (command == "options" && bet_credits < minbalance){
                    cout << "Negative value, please try again." << endl;

                    bet_credits = minbalance;
                    acc_balance = minbalance;}

        }

// Exits the game
        if (command == "exit"){
            play = false;}

        else {
            cout << "I don't know that command... :(" << endl;}
    }
}
