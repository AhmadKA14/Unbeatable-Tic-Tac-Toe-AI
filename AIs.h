/*
 * AIs.h
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmad Abushawar
 */

#ifndef AIS_H_
#define AIS_H_


#include "Board.h"


class AI
{
public:
    int randomAI(string board[9], Board _board);
    int winningAI(const string* player, string board[9], Board _board);
    int notLosingAI(const string* player, string board[9], Board _board);
    int miniMax(const string* player, string board[9], bool isMax, int depth, Board _board);
    int bestMove(const string* player, string board[9], Board _board);
};


#endif /* AIS_H_ */