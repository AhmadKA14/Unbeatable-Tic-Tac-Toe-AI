/*
 * AIs.cpp
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmad Abushawar
 */

#include "AIs.h"


int AI::randomAI(string board[9], Board _board)
{
    int num = (rand() %9)+1;
    if(_board.isValid(&num, board))
    {
        return num;
    }
    else
    {
        randomAI(board, _board);
    }
}

int AI::notLosingAI(const string* player, string board[9], Board _board)
{
    const string X = "X";
    const string O = "O";
    for(int i = 0; i < 10; i++)
    {
        if(_board.isValid(&i, board))
        {
            string* temp_board = new string[9];
            for(int i = 0; i < 9; i++)
            {
                *(temp_board + i) = board[i];
            }
            if(*player=="X")
            {
                _board.makeMove(&i, &O, temp_board);
                if(_board.getWinner(temp_board)=="O")
                {
                    delete[] temp_board;
                    temp_board = nullptr;
                    return i;
                }
            }
            else if(*player=="O")
            {
                _board.makeMove(&i, &X, temp_board);
                if(_board.getWinner(temp_board)=="X")
                {
                    delete[] temp_board;
                    temp_board = nullptr;
                    return i;
                }
            }
            delete[] temp_board;
            temp_board = nullptr;
        }    
    }
    return randomAI(board, _board);    
}

int AI::winningAI(const string* player, string board[9], Board _board)
{
    for(int i = 0; i < 10; i++)
    {
        if(_board.isValid(&i, board))
        {
            string* temp_board = new string[9];
            for(int i = 0; i < 9; i++)
            {
                *(temp_board + i) = board[i];
            }
            _board.makeMove(&i, player, temp_board);
            if(*player=="X")
            {
                if(_board.getWinner(temp_board)=="X")
                {
                    delete[] temp_board;
                    temp_board = nullptr;
                    return i;
                }
            }
            else if(*player=="O")
            {
               if(_board.getWinner(temp_board)=="O")
                {
                    delete[] temp_board;
                    temp_board = nullptr;
                    return i;
                }
            }
            delete[] temp_board;
            temp_board = nullptr;
        }
    }
    return notLosingAI(player, board, _board); 
}

int AI::miniMax(const string* player, string board[9], bool isMax,int depth, Board _board)
{
    string opponent;
    if(*player=="X"){opponent = "O";}
    else{opponent = "X";}
    
    if(_board.getWinner(board)==*player){return 10-depth;}
    else if(_board.getWinner(board)==opponent){return -10-depth;}
    else if(_board.isBoardFull(board)){return 0;}

    if(isMax)
    {
        int best_score = -1000;

        for(int i = 0; i < 10; i++)
        {
            if(_board.isValid(&i, board))
            {
                string* temp_board = new string[9];
                for(int i = 0; i < 9; i++)
                {
                    *(temp_board + i) = board[i];
                }  

                _board.makeMove(&i, player, temp_board);

                best_score = max(best_score, miniMax(player, temp_board, !isMax, depth++, _board));

                delete[] temp_board;
                temp_board = nullptr;
            }
        }
        return best_score;
    }

    else
    {
        int best_score = 1000;

        for(int i = 0; i < 10; i++)
        {
            if(_board.isValid(&i, board))
            {
                string* temp_board = new string[9];
                for(int i = 0; i < 9; i++)
                {
                    *(temp_board + i) = board[i];
                } 
                _board.makeMove(&i, &opponent, temp_board);

                best_score = min(best_score, miniMax(player, temp_board, !isMax, depth++, _board));

                delete[] temp_board;
                temp_board = nullptr;
            }
        }
        return best_score;
    }
}

int AI::bestMove(const string* player, string board[9], Board _board)
{
    int best_score = -1000;
    int best_move = 0;

    for(int i = 0; i < 10; i++)
    {
        if(_board.isValid(&i, board))
        {
            string* temp_board = new string[9];
            for(int i = 0; i < 9; i++)
            {
                *(temp_board + i) = board[i];
            }  

            _board.makeMove(&i, player, temp_board);

            int score = miniMax(player,temp_board, false, 0, _board);

            if(score > best_score)
            {
                best_score = score;
                best_move = i;
            }

            delete[] temp_board;
            temp_board = nullptr;
        }
    }
    return best_move;
}