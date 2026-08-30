#include "../Player/Player.h"
#include "../Game/Game.h"
#include <iostream>
#include <cstdlib>
#include <array>
#include <limits>

using namespace std;

template<typename T>
void failedinput(T &p);
void clear();
void printBoard();
void TictacToe();
void menu();

int main()
{
    menu();


    return 0;
}

void menu()
{
    int choice;
    cout << "Welcome to Tic Tac Toe!" << endl;

    cout << "1.Start Game"<< endl
    << "2.Exit" << endl
    << "Enter your choice: ";
    cin >> choice;
    failedinput(choice);

    switch(choice)
    {
        case 1:
            clear();
            TictacToe();
            break;
        case 2:
            clear();
            cout << "GoodBye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            menu();
            break;
    };
}

void TictacToe()
{
    array<Player,2> Players;
    Player* Current;

    for(auto i = 0; i < Players.size(); i++){
        cout << "Player "<< i+1 << " enter your info. " << endl;
        Players[i].Enterinfo();
    }

    while(Players[0].mark() == Players[1].mark()){
        cout << "Player marks cannot be identical. " << endl;
        Players[1].Enterinfo();
    }

    int choice;
    printBoard();
    cout<<endl<< Players[0].name() <<": "<< Players[0].mark() << " " << Players[1].name() << ": " << Players[1].mark() << endl;
    cout << Players[0].name() << " enter a number to place your mark: ";

    Current = &Players[0];

    do{
        cin >> choice;
        failedinput(choice);

        if (choice <= 0 || choice >= 10 || Board[choice-1] == Players[0].mark() || Board[choice-1] == Players[1].mark()){
            cout << endl << "Invalid choice. Try again: ";
            continue;
        }
        else
        {
            Board[choice-1] = Current->mark();

            clear();
            printBoard();
            Endgame(Current);
            changeTurn(Current, Players);
            
            if(!Gameover)
            cout << endl << Current->name() << "("<< Current->mark()<< ")"<<", Enter your move: ";

            continue;
        }
    }        
    while (!Gameover);

    resetGame();
    cout << "1. New game" << endl << "2. Exit" << endl << "Choice: ";
    cin >> choice;
    failedinput(choice);

    switch(choice){
        case 1: 
        clear();
        TictacToe(); 
        break;

        case 2: 
        cout << "goodbye!" << endl;
        break;

        default: 
        cout << "Invalid choice. try again."; 
        break;
    }
}

void clear()
{
    system("cls");
}


void printBoard()
{
    cout << "TIC TAC TOE: "<< endl;
    for(int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
        {
            cout << endl;
        }
        cout << Board[i] << " | ";
    }
}

template<typename T>
void failedinput(T &p){
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Try again: ";
        cin >> p;
    }
}