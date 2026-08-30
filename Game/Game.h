#pragma once

#include <array>
#include "../Player/Player.h"

extern array<char,9> Board;
extern bool Gameover;

void changeTurn(Player* &Current, array<Player, 2> &P);
void Endgame(Player* Current);
void resetGame();