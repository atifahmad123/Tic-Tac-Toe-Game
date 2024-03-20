#include <iostream>
#include <string>
using namespace std;

char RowColumn[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'X'; // Start with 'X'

int row; //Global variables.....
int column; //Global variables.....

bool tie; //Global variables.....

struct player_details {
    string PlayerOne;
    string PlayerTwo;
};

player_details player;

void display_board() {
    cout << "\n\n\n\n\n\n";
    cout << "         					   " << "   |" << "     |\n";
    cout << "                       				  " << "  " << RowColumn[0][0] << " |  " << RowColumn[0][1] << "  |  " << RowColumn[0][2] << endl;
    cout << "                       				  " << "____|_____|____\n";
    cout << "                      			     	  " << "    |" << "     |\n";
    cout << "                  				  " << "  " << RowColumn[1][0] << " |  " << RowColumn[1][1] << "  |  " << RowColumn[1][2] << endl;
    cout << "                       				  " << "    |" << "     |\n";
    cout << "                       				  " << "____|_____|____\n";
    cout << "                       				  " << "    |" << "     |\n";
    cout << "                       				  " << "  " << RowColumn[2][0] << " |  " << RowColumn[2][1] << "  |  " << RowColumn[2][2] << endl;
    cout << "                       				  " << "    |" << "     |\n";
}


void marker_selection() {
    int digit;
    cout << "\n"
         << "* " << player.PlayerOne << " marker is: 'X'."
         << "\n"
         << "* " << player.PlayerTwo << " marker is: '0'." << endl;
    display_board();
    cout << "\n\n"
         << "* " << (token == 'X' ? player.PlayerOne : player.PlayerTwo) << " kindly enter your turn." << endl;

    bool validMove = false; // It is a flag to track if a valid move is made

    try {
        while (!validMove) {
            cin >> digit;

            if (digit == 0) {
                
                throw string("You entered a non-integer value!!!\n Choose between 1 and 9.");
            }

            // Checking that... if the entered digit is within the valid range
            if (digit < 1 || digit > 9) {
                cout << "Invalid value! Choose between 1 and 9." << endl;
            } else {
                // Convert the digit to row and column indices
                int row = (digit - 1) / 3;
                int column = (digit - 1) % 3;

                // Check if the selected cell is already occupied
                if (RowColumn[row][column] == 'X' || RowColumn[row][column] == '0') {
                    cout << "Cell already occupied! Choose another position." << endl;
                } else {
                    // Update the board and switch player
                    RowColumn[row][column] = token;
                    token = (token == 'X' ? '0' : 'X');
                    validMove = true; // Set the flag to true to exit the loop
                }
            }
        }
    } catch (string exception) {
        cout << exception;
    }
}



bool winning() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (RowColumn[i][0] == RowColumn[i][1] && RowColumn[i][0] == RowColumn[i][2] ||
            RowColumn[0][i] == RowColumn[1][i] && RowColumn[0][i] == RowColumn[2][i]) {
            return true;
        }
    }

    // Check diagonals
    if (RowColumn[0][0] == RowColumn[1][1] && RowColumn[1][1] == RowColumn[2][2] ||
        RowColumn[0][2] == RowColumn[1][1] && RowColumn[1][1] == RowColumn[2][0]) {
        return true;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (RowColumn[i][j] != 'X' && RowColumn[i][j] != '0') {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

struct user_data {
    string first_name, second_name, entry_security_answer, signin_security_answer;
    int entry_pin, signin_pin;
};

int main() {
    user_data name1;
    user_data name2;
    user_data password1;
    user_data password2;
    user_data question_answer1;
    user_data question_answer2;

    cout << "\n"
         << endl;
    cout << "_______________________________________________ ---< TIC TAC TOE >--- _________________________________________________" << endl;

    cout << "\n\n\n\t* It is a game of two players. " << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "\n\n	* Kindly enter player1 name." << endl;
    getline(cin, player.PlayerOne);
    cout << "	* Kindly enter player2 name." << endl;
    getline(cin, player.PlayerTwo);
    system("cls");

    while (!winning()) {
        marker_selection();
        system("cls");
    }

    if (token == 'X' && tie == false) {
       	cout<<"****\n***\n***\n**\n**\n *"<<endl;
	   
	   
	    cout << " ________________________________________" << endl;
        cout << "| Winner : " << player.PlayerTwo << "                          " << endl;
        cout << "| Looser : " << player.PlayerOne << "                          " << endl;
        cout << "|________________________________________" << endl;
        cout << player.PlayerTwo << ": Congrats!!! Keep it up." << endl;
        cout << player.PlayerOne << ": Don't be hopeless. Give your best effort for improvement next time." << endl;
        return 0;
    } else if (token == '0' && tie == false) {
        cout << " ________________________________________" << endl;
        cout << "| Winner : " << player.PlayerOne << "                          " << endl;
        cout << "| Looser : " << player.PlayerTwo << "                          " << endl;
        cout << "|________________________________________" << endl;
        cout << player.PlayerOne << ": Congrats!!! Keep it up." << endl;
        cout << player.PlayerTwo << ": Don't be hopeless. Give your best effort for improvement next time." << endl;
        return 0;
    } else {
        cout << "!! DRAW !!" << endl;
        return 0;
    }

    return 0;
}