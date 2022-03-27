#include "menus.h"
#include "login.h"
#include "register.h"   
#include "tictactoe.h"

//https://www.softwaretestinghelp.com/cpp-makefile-tutorial/

//https://www.youtube.com/watch?v=rJ-C8q7KOew

int main(){
    int exit = 0;
    int logged = 0;

    TicTacToe newTicTacToe("RUI");

    while(!exit){
        switch(principalMenu()){
            case 1:
                registerUser();
                break;
            case 2:
                logged = loginUser();
                break;
            case 3:
                exit = 1;
                break;
            default:
                cout << "That is not an option\n" << endl;
        }
        while(logged){
            newTicTacToe.inicializeGame();
            newTicTacToe.playGame();
            logged = 0;
        }
    }
    


    return 0;
}