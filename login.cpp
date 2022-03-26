#include <fstream>
#include <cstring>
#include <iostream>
#include <string.h>

#include "login.h"

using namespace std;

/*
    [ ] verify if it's possible to
    change searchName for checkName in
    register

*/

int searchName(string name){
    string line;
  
    ifstream myFile;
    myFile.open("backend.txt");

    while ( getline(myFile, line) ) {

        for(int i = 0; i < (int) line.size() ; i++){
            if(line[i] == '|'){
                line = line.substr(0, i);
                break;
            }
        }

        if(line == name){
            return 1;
        }
    }

    return 0;
}

int checkPassword(string name, string pass){
    int i ;
    string line;
    string tempLine;
  
    ifstream myFile;
    myFile.open("backend.txt");

    while ( getline(myFile, line) ) {
        tempLine = line;

        for( i = 0; i < (int) tempLine.size() ; i++){
            if(tempLine[i] == '|'){
                tempLine = tempLine.substr(0, i);
                break;
            }
        }

        if(tempLine == name){
        
            line = line.substr(i + 1, line.size() + 1);
            if(line == pass){
                return 1;
            }
            
        }
    }

    return 0;
}

int loginUser(){

    int checkName = 0;
    int checkPass = 0;
    string userName;
    string pass;

 
    while(!checkName){
        cout << "Insert your name: ";
        getline(cin >> ws, userName);
        checkName = searchName(userName);
        if (!checkName) cout << "Name not found" << endl;
    }

    while(!checkPass){
        cout << "Insert your password: ";
        getline(cin >> ws, pass);
        checkPass = checkPassword(userName,pass);
        if (!checkPass) cout << "The password and usarname do not match " << endl;
    }
 


    return 1;
}