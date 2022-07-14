/*
 * Board.h
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmad Abushawar
 */

#ifndef BOARD_H_
#define BOARD_H_


#include <iostream>
#include <string> 
#include <time.h>
using namespace std;


class Board
{
public:
    string board[9];

    void initializeBoard(string board[9]);
    void render(string board[9]);
    bool isValid(int* option, string board[9]);
    bool isBoardFull(string board[9]);
    int getMove(string board[9]);
    void makeMove(int* option, const string* player, string board[9]);
    string getWinner(string board[9]);
};


#endif /* BOARD_H_ */