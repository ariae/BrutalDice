#include <iostream>
#include <cstdlib>
#include <ctime>                // Needed for srand(time(0)) random numbers

using namespace std;            // Using "cin <<, cout >>" instead of std::cin std::cout

int main()
{
    bool play = true;           // Does the user WANT to play?
    string command;             // Control block, what function is to be called

    srand(time(0));             // Randomizer based on PC time (Not really random)

    // Cash variables
    int bet_credits=0;          // Value to insert into account (acc_balance)
    int bet_round=0;            // Value to bet per match
    int acc_balance=0;          // Digital account balance

    // Round values
    int round_number=0;         // What round is being played
    int pla_win_round=0;        // Player wins (out of 3)
    int npc_win_round=0;        // Computer wins (out of 3)
    int round_playing=0;        // Has the player put down a bet?

    // Player dices
    int pla_dice_1=0;           // Dice 1, player
    int pla_dice_2=0;           // Dice 2, player
    int pla_dice_m=0;           // Highest dice, player

    // Computer dices
    int npc_dice_1 = 0;           // Dice 1, computer
    int npc_dice_2 = 0;           // Dice 2, computer
    int npc_dice_m = 0;           // Highest dice, player

    // Account balance max/min value (acc_balance)
    int minbalance = 0;         // Minsta värde konto
    int maxbalance = 5000;      // Högsta värde konto

    while (play)
    {
        cout << "Type play to play, options to edit account balance or exit to quit." << endl;
        cout << "Your current account balance is " << acc_balance  << endl;
        cout << "> ";
        cin >> command;

        if (command == "play" && acc_balance >= 100)
            {
                if (round_playing = 0)
                    {
                        cout << endl << endl;
                        cout << "Betting amounts are: 100, 300, 500. " << endl;
                        cout << "Insert amount to bet: " << endl;
                        cout << "> ";
                        cin >> bet_round;
                        cout << " " << endl << endl;
                        round_playing = 1;
                        round_number++;

                        if(bet_round==0)
                            {
                                cout << endl << endl;
                                cout << "0 is true" << endl;
                                acc_balance = acc_balance-bet_round;
                                cout << "Your current bet is " << bet_round  << endl;
                            }
                        else if(bet_round==100)
                            {
                                cout << endl << endl;
                                acc_balance = acc_balance-bet_round;
                                cout << "Your current bet is " << bet_round  << endl;
                            }
                        else if(bet_round==300)
                            {
                                cout << endl << endl;
                                acc_balance = acc_balance-bet_round;
                                cout << "Your current bet is " << bet_round  << endl;
                            }
                        else if(bet_round==500)
                            {
                                cout << endl << endl;
                                acc_balance = acc_balance-bet_round;
                                cout << "Your current bet is " << bet_round  << endl;
                            }
                        else
                            {
                                cout << endl << endl;
                                cout << "Illicit amount, try again. " << endl << endl;

                                break;   /////////////////////////////Hitta bättre lösning
                            }
                    }
                ///////////////////////////
                if ((round_playing = 1))
                {
                    cout << endl;
                    cout << "Round " << round_number  << endl;
                    cin.get();

                    // Player roll
                    pla_dice_1 = rand() & (6 + 1);
                    pla_dice_2 = rand() & (6 + 1);
                    pla_dice_m = max(pla_dice_1, pla_dice_2); //Compares pla_dice_1 to pla_dice_2, and picks the highest and assigns it to pla_dice_m

                    cout << "Rolling..."  << endl;
                    cin.get();
                    cout << "Dice 1: " << pla_dice_1 << endl;
                    cin.get();
                    cout << "Dice 2: " << pla_dice_2 << endl;
                    cin.get();
                    cout << "Max   : " << pla_dice_m  << endl;
                    cin.get();

                    // NPC roll
                    npc_dice_1 = rand() & (6 + 1);
                    npc_dice_2 = rand() & (6 + 1);
                    npc_dice_m = max(npc_dice_1, npc_dice_2); //Compares npc_dice_1 to npc_dice_2, and picks the highest and assigns it to npc_dice_m

                    cout << "NPC rolling..." << endl;
                    cin.get();
                    cout << "Dice 1: " << npc_dice_1 << endl;
                    cin.get();
                    cout << "Dice 2: " << npc_dice_2 << endl;
                    cin.get();
                    cout << "Max   : " << npc_dice_m << endl;
                    cin.get();
                    cout << endl << endl;
                    cout << "Player's highest dice: " << pla_dice_m << ", NPC highest dice: " << npc_dice_m << endl;

                    if (pla_dice_m > npc_dice_m)
                        {
                            cout << "Player wins this round!" << endl;
                            cin.get();

                            pla_win_round++;
                        }

                    else if(pla_dice_m < npc_dice_m)
                        {
                            cout << "NPC wins this round!" << endl;
                            cin.get();

                            npc_win_round++;
                        }

                    else
                        {
                            cout << "Round is a tie! No winner..." << endl;
                            cin.get();
                        }

// Checks the sum of won rounds
                    cout << endl;
                    cout << "Player has won " << pla_win_round << " round(s) out of 3 so far." << endl;
                    cout << "NPC has won " << npc_win_round << " round(s) out of 3 so far." << endl;
                    cin.get();
                    cout << endl;


// Check win state (Player or NPC)
                    if (pla_win_round == 2 || npc_win_round == 2)
                        {
                            cout << "GAME OVER" << endl << endl;
                            cin.get();
// acc_balance ändras inte?!
                            if (pla_win_round > npc_win_round)
                                {

                                    acc_balance = acc_balance + (bet_round * 2);

                                    cout << "**************" << endl;
                                    cout << " PLAYER WINS! " << endl;
                                    cout << "**************" << endl << endl;
                                    cin.get();

                                    npc_win_round = 0;
                                    pla_win_round = 0;
                                    bet_round = 0;
                                    round_playing = 0;
                                }

                            else
                                {

                                    acc_balance = acc_balance - bet_round;

                                    cout << "***********" << endl;
                                    cout << " NPC WINS! " << endl;
                                    cout << "***********" << endl << endl;
                                    cin.get();

                                    npc_win_round = 0;
                                    pla_win_round = 0;
                                    bet_round = 0;
                                    round_playing = 0;
                                }
                        }
                }
            }
                else if (command == "play" && acc_balance<100)
                    {
                        cout << "You must insert credits into your virtual account!" << endl;
                    }

// The option block, where you can check account balance and insert funds
                else if (command == "options")

                    {
                        cout << endl;
                        cout << "Insert coins to play. (Up to a total of 5000 is accepted.)" << endl;
                        cout << "> ";
                        cin >> bet_credits;

                        acc_balance = acc_balance + bet_credits;

                        if (command == "options" && bet_credits <= maxbalance  && bet_credits > minbalance  && play)
                            {
                                cout << endl;
                                cout << "You have deposited " << bet_credits << "/5000" << endl;
                            }
                        else if (command == "options" && bet_credits > maxbalance  && play)
                            {
                                cout << endl;
                                cout << "Max total deposit is 5000. Your balance has been adjusted to 5000." << endl;
                                cout << "You have deposited " << maxbalance << "/" << maxbalance << endl;

                                bet_credits = minbalance;
                                acc_balance = maxbalance;
                            }
                        else if (command == "options" && bet_credits < minbalance  && play)
                            {
                                cout << endl;
                                cout << "Negative value, please try again." << endl;

                                bet_credits = minbalance;
                                acc_balance = minbalance;
                            }
                        else
                            {
                                play = false;
                                break;
                            }
                    }

// Exits the game
    else if (command == "exit")
        {
            play = false;
            break;
        }

    else
        {
            cout << endl;
            cout << "I don't know that command... :(" << endl;
        }
    }
}
