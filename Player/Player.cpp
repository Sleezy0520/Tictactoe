#include "Player.h"
#include <cctype>
#include <iostream>
#include <limits>

void Player::Enterinfo(){
        bool validmark = false;
        if (playername == " "){
            cout << "What is your name? ";
            cin.ignore();
            getline(cin, playername);
        }

        cout << "What mark do you want(X or O)? ";
        cin >> playermark;
        playermark = toupper(playermark);

        while(!validmark){
            if(playermark == 'X' || playermark == 'O'){
            validmark = true;
        }
            else{
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Mark. Try again:";
                cin >> playermark;
                playermark = toupper(playermark);
            }
        }
    }

    string Player::name(){
        return playername;
    }

    char Player::mark(){
        return playermark;
    }

    int Player::wins(){
        return Amountofwins;
    }

    void Player::addwin(){
        Amountofwins++;
        cout << "Added win to player. Total wins: "<< Amountofwins; 
    }
