/*
WE are going to make a karle board with karel inside and we going to move the move the Robot when we give a command from the user. lets make it , lets do it.
*/
#include <iostream>
using namespace std;
const int ROW = 15;
const int COLOMUN = 15;
char board[ROW][COLOMUN];
char face;
/*
* leta make a board that hold karel .
*/
void karelboard(char board[][COLOMUN]) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COLOMUN; col++) {
            cout << board[row][col];

        }
        cout << endl;
    }
}
/*
* lets start working with karel.
* lets make move function to move our karel.
*here is it move funtion below.
*/

void move(int& row, int& col) {
    if (board[row][col] == '@') {

        board[row][col] = 'x';
    }
    else {
        board[row][col] = '-';
    }

    if (face == 'e')
        col++;
    if (face == 'n')
        row--;
    if (face == 'w')
        col--;
    if (face == 's')
        row++;

    if (row > ROW || row < 0) {
        cout << "karle move out the boundry crashed the robot" << endl;
        exit(0);
    }
    else if (col > COLOMUN - 1 || col < 0) {
        cout << "karle move out the boundry, Robot crashed." << endl;
        exit(0);
    }

    board[row][col] = '0';
}
/*
* lets make the direction of karel.
* lets make turnleft below.
* Here is it below.
*/

void turnleft() {
    if (face == 'e') {
        face = 'n';
    }
    else if (face == 'n') {
        face = 'w';
    }
    else if (face == 'w') {
        face = 's';
    }
}
/*
* let make a beeper to the board right know.
*  let look in the function below.
* its right here below
*/

void putBeeper(int& row, int& col) {

    if (board[row][col] == '0') {
        board[row][col] = '@';
    } if (board[row][col] == 'x')
        board[row][col] = '@';
}
/*
* lets taked out the beepers we make
* lets make function that taked out
beepers.
* here is below.
*/
void pickBeeper(int& row, int& col) {

    if (board[row][col] == '@') {
        board[row][col] = 'x';
    }
    if (board[row][col] == '0') {
        cout << "the robot has crashed" << endl;
        exit(0);

    }
    /*
    * let make function that quit for karel.
    * here is below.
   */
}
void quit() {
    exit(0);
}

int main() {
    int row = 14;
    int col = 0;
    string command;
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COLOMUN; col++) {
            board[row][col] = '-';
        }
    }
    board[row][col] = '0';
    face = 'e';
    karelboard(board);
    while (true) {
        cout << "please enter command" << endl;
        cin >> command;
        while (!(command == "move();" || command == "turnleft();" || command == "putBeeper();" || command == "pickBeeper();" || command == "quit();")) {
            cout << "Syntax error" << " - please enter command " << endl;
            cin >> command;
        }
        if (command == "move();") {
            move(row, col);
            karelboard(board);

        }
        else if (command == "turnleft();") {
            turnleft();
            karelboard(board);

        }
        else if (command == "putBeeper();") {
            putBeeper(row, col);
            karelboard(board);


        }
        else if (command == "pickBeeper();") {
            pickBeeper(row, col);
            karelboard(board);
        }
        else if (command == "quit();") {
            quit();

        }
    }
}

