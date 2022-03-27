#include "tictactoe.h"

void TicTacToe::printBoard(){
    cout << board[0] << '|' << board[1] << '|' << board[2]<< endl;
    cout << "-+-+-" << endl;
    cout << board[3] << '|' << board[4] << '|' << board[5]<< endl;
    cout << "-+-+-" << endl;
    cout << board[6] << '|' << board[7] << '|' << board[8]<< endl;
}

void TicTacToe::inicializeGame(){
    cout << "    Rules:\n - Simple game of TicTacToe against AI Bot\n";
    cout << " - Choose position of the board shown\n";
    cout << " - Have Fun!\n";
    cout << "1|2|3" << endl;
    cout << "-+-+-" << endl;
    cout << "4|5|6" << endl;
    cout << "-+-+-" << endl;
    cout << "7|8|9" << endl;
}

bool TicTacToe::emptySpace(int position){
    if(board[position - 1] == ' ')
        return true;
    return false; 
}

bool TicTacToe::verifyDraw(){
    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            return false;
        }
    }

    return true;
}

bool TicTacToe::verifyWin(){

    if (board[0] == board[1] && board[0] == board[2] && board[0] != ' ') return true;
    else if (board[3] == board[4] && board[3] == board[5] && board[3] != ' ') return true;
    else if (board[6] == board[7] && board[6] == board[8] && board[6] != ' ') return true;
    else if (board[0] == board[3] && board[0] == board[6] && board[0] != ' ') return true;
    else if (board[1] == board[4] && board[1] == board[7] && board[1] != ' ') return true;
    else if (board[2] == board[5] && board[2] == board[8] && board[2] != ' ') return true;
    else if (board[0] == board[4] && board[0] == board[8] && board[0] != ' ') return true;
    else if (board[6] == board[4] && board[6] == board[2] && board[6] != ' ') return true;
    else
        return false;
}

bool TicTacToe::playTurn(char player, int position){
    int newPos;

    if(emptySpace(position)){
        board[position - 1] = player;
        printBoard();

        if( verifyDraw()){
            cout << "The game ended, it was a DRAW\n\n" << endl;
            return true;
        }

        if(verifyWin()){
            if(player == 'X'){
                cout << "The game ended, the bot was victorious\n\n" << endl;
            }
            else if(player == 'O'){
                cout << "The game ended, the player was victorious\n\n" << endl;
            }
            return true;
        }
    }
    else{
        cout << "You cannot play in that position" << endl;
        cout << "Enter the position for the '" << player <<"': " ;
        cin >> newPos;
        playTurn(player, newPos);
    }

    return false;
}

bool TicTacToe::playerMove(){
    int newPos;
    cout << "Enter the position for 'O': ";
    cin >> newPos;
    return playTurn(player, newPos);

}

bool TicTacToe::botMove(){
    int newPos;
    cout << "Enter the position for 'X': ";
    cin >> newPos;
    return playTurn(bot, newPos);
}

void TicTacToe::playGame(){

    while(!verifyWin()){
        if(botMove()) break;
        if(playerMove()) break;
    }

}
