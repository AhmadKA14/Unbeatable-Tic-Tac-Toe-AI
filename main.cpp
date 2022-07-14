/*
 * main.cpp
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmad Abushawar
 */


#include "AIs.h"


int main()
{
    Board board;
    AI ai;
    string human, _ai;
    int option, player, difficulity;
    bool end_of_game = false;

    cout << "1-Easy  2-Medium  3-Unbeatable!!!\n"<< "Choose difficlity: ";
    cin >> difficulity;

    cout << "\n1-(X)  2-(O)\nSelect Player: ";
    cin >> player;
    cout << endl;
    
    if(player==1)
    {
        human = "X";
        _ai = "O";
    }
    else
    {
        human = "O";
        _ai = "X";
    }

    srand(time(0));
    board.initializeBoard(board.board);
    board.render(board.board);

    for(int i = 0; i < 10; i++)
    {
        if(board.getWinner(board.board)=="None"&& i < 9)
        {
            if(i%2==0)
            {
                cout << "\nCurrent Player is (" << human << ")\n" << endl;
                option = board.getMove(board.board);
                board.makeMove(&option, &human,board.board);
                board.render(board.board); 
            }
            else
            {
                cout << "\nCurrent Player is (" << _ai << ")\n" << endl;
                if(difficulity==1){option = ai.randomAI(board.board, board);}
                else if(difficulity==2){option = ai.winningAI(&_ai, board.board, board);}
                else{option = ai.bestMove(&_ai, board.board, board);}
                board.makeMove(&option, &_ai, board.board);
                board.render(board.board); 
            }
        }
        else if(board.getWinner(board.board)=="X")
        {
            cout << "\nEnd of Game!\nThe Winner is Player (X)!" << endl;
            end_of_game = true;
            break;
        }
        else if(board.getWinner(board.board)=="O")
        {
            cout << "\nEnd of Game!\nThe Winner is Player (O)!" << endl;
            end_of_game = true;
            break;
        }
    }
    if(!end_of_game){cout << "\nEnd of Game!\nIt's a Draw!";}
}