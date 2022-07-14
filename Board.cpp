/*
 * Board.cpp
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmad Abushawar
 */


#include "Board.h"


void Board::initializeBoard(string board[9])
{
    int counter = 1;
    for(int i = 0; i < 9; i++)
    {
        board[i] = to_string(counter);
        counter++;
    }   
}

void Board::render(string board[9])
{
    int side = 0;
    int bottom = 0;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 3; j++)
        {   
            cout << board[i];
            if(side<2)
            {
                cout << " | "; 
                side++;
                i++;
            }
        }
        side = 0;
        cout << endl;
        if(bottom<2)
        {
            cout << "---------" << endl;
        }
        bottom++;
    }
}

bool Board::isValid(int* option, string board[9])
{
    switch(*option)
    {
        case 1:
            if(board[0]=="1"){return true;}
            else{return false;}
        case 2:
            if(board[1]=="2"){return true;}
            else{return false;}
        case 3:
            if(board[2]=="3"){return true;}
            else{return false;}
        case 4:
            if(board[3]=="4"){return true;}
            else{return false;}
        case 5:
            if(board[4]=="5"){return true;}
            else{return false;}
        case 6:
            if(board[5]=="6"){return true;}
            else{return false;}
        case 7:
            if(board[6]=="7"){return true;}
            else{return false;}
        case 8:
            if(board[7]=="8"){return true;}
            else{return false;}
        case 9:
            if(board[8]=="9"){return true;}
            else{return false;}
        default:
            return false;
    }
}

bool Board::isBoardFull(string board[9])
{
    if(board[0]!="1"&&board[1]!="2"&&board[2]!="3"&&board[3]!="4"&&board[4]!="5"&&board[5]!="6"&&board[6]!="7"&&board[7]!="8"&&board[8]!="9"){return true;}
    else{return false;}
}

int Board::getMove(string board[9])
{
    int option;
    cout << "Choose a square: ";
    cin >> option;
    cout << endl;
    if(isValid(&option, board))
    {
        return option;
    }
    else
    {
        cout << "Error: Please choose one of the available squares." << endl;
        getMove(board);
    }
}

void Board::makeMove(int* option, const string* player, string board[9])
{
    switch(*option)
    {
        case 1:
            if((*player)=="X"){board[0]="X";}
            else{board[0]="O";}
            break;
        case 2:
            if((*player)=="X"){board[1]="X";}
            else{board[1]="O";}
            break;
        case 3:
            if((*player)=="X"){board[2]="X";}
            else{board[2]="O";}
            break;
        case 4:
            if((*player)=="X"){board[3]="X";}
            else{board[3]="O";}
            break;
        case 5:
            if((*player)=="X"){board[4]="X";}
            else{board[4]="O";}
            break;
        case 6:
            if((*player)=="X"){board[5]="X";}
            else{board[5]="O";}
            break;
        case 7:
            if((*player)=="X"){board[6]="X";}
            else{board[6]="O";}
            break;
        case 8:
            if((*player)=="X"){board[7]="X";}
            else{board[7]="O";}
            break;
        case 9:
            if((*player)=="X"){board[8]="X";}
            else{board[8]="O";}
            break;
    }
}

string Board::getWinner(string board[9])
{
    if(board[0]=="X"&&board[1]=="X"&&board[2]=="X"){return "X";}
    else if(board[3]=="X"&&board[4]=="X"&&board[5]=="X"){return "X";}
    else if(board[6]=="X"&&board[7]=="X"&&board[8]=="X"){return "X";}
    else if(board[0]=="X"&&board[3]=="X"&&board[6]=="X"){return "X";}
    else if(board[1]=="X"&&board[4]=="X"&&board[7]=="X"){return "X";}
    else if(board[2]=="X"&&board[5]=="X"&&board[8]=="X"){return "X";}
    else if(board[0]=="X"&&board[4]=="X"&&board[8]=="X"){return "X";}
    else if(board[2]=="X"&&board[4]=="X"&&board[6]=="X"){return "X";}

    else if(board[0]=="O"&&board[1]=="O"&&board[2]=="O"){return "O";}
    else if(board[3]=="O"&&board[4]=="O"&&board[5]=="O"){return "O";}
    else if(board[6]=="O"&&board[7]=="O"&&board[8]=="O"){return "O";}
    else if(board[0]=="O"&&board[3]=="O"&&board[6]=="O"){return "O";}
    else if(board[1]=="O"&&board[4]=="O"&&board[7]=="O"){return "O";}
    else if(board[2]=="O"&&board[5]=="O"&&board[8]=="O"){return "O";}
    else if(board[0]=="O"&&board[4]=="O"&&board[8]=="O"){return "O";}
    else if(board[2]=="O"&&board[4]=="O"&&board[6]=="O"){return "O";}

    else{return "None";}
}