#pragma once

#include <string>

using namespace std;
 
class Player{
    public:
    void Enterinfo();
    string name();
    char mark();
    int wins();
    void addwin();

    private:
    int Amountofwins = 0;
    string playername = " ";
    char playermark = ' ';
};