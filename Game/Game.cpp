#include "Game.h"
#include <iostream>

array<char, 9> Board ={
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'
};

bool Gameover = false;

void changeTurn(Player* &Current, array<Player,2> &P)
{
    if(Current == &P[0])
        Current = &P[1];

    else if(Current == &P[1])
        Current = &P[0];
}

void Endgame(Player* Current)
{
    int choice;
    bool boardfull = true;
    int WinningCombos[8][3] ={{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for(auto i = 0; i<8; i++){
            if(Board[WinningCombos[i][0]] == Board[WinningCombos[i][1]] && Board[WinningCombos[i][0]] == Board[WinningCombos[i][2]]){
                Gameover = true;
                cout << "\n" << Current -> name() << " Wins!" << endl;
                return;
            }

    }

    for(auto i = 0; i<Board.size(); i++){
        if(Board[i] != 'X' && Board[i] != 'O'){
            boardfull = false;
        }
    }

    if(boardfull){
            Gameover = true;
            cout << "\nThis is a Draw. No one wins!" << endl;
        }
}

void resetGame(){
    Gameover = false;

    char Temp[9] =
    {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    for(auto i = 0; i <9; i++){
        Board[i] = Temp[i];
    }
}