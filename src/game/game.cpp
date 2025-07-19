#include <iostream>
#include <cstring>

void printBoard(int* board, int board_size, int border_length)
{
    for (int i = 0; i < board_size; i++) {
        std::cout << board[i];
        if (i > 0 && i%border_length == border_length-1) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl << "############" << std::endl;
}

void checkProximities(int i, int* next_board, int* board, int board_size, int border_length)
{

    int neighbours = 0;

    //LEFT
    if (i%border_length != 0)
    {
        if (board[i-1] == 1)
        {
            neighbours++;
        }
    }
    
    //UP
    if (i - border_length >= 0)
    {
        if (board[i-border_length] == 1)
        {
            neighbours++;
        }
    }

    //RIGHT
    if (i%border_length != border_length-1)
    {
        if (board[i+1] == 1)
        {
            neighbours++;
        }
    }

    //BOTTOM
    if (i + border_length < board_size)
    {
        if (board[i+border_length] == 1)
        {
            neighbours++;
        }
    }

    //TOP LEFT
    if (i - border_length - 1 >= 0 && i%border_length != 0)
    {
        if (board[i-border_length-1] == 1)
        {
            neighbours++;
        }
    }

    //TOP RIGHT
    if (i - border_length + 1 >= 0 && i%border_length != border_length-1)
    {
        if (board[i-border_length+1] == 1)
        {
            neighbours++;
        }
    }

    //BOTTOM LEFT
    if (i + border_length - 1 < board_size && i%border_length != 0)
    {
        if (board[i+border_length-1] == 1)
        {
            neighbours++;
        }
    }

    //BOTTOM RIGHT
    if (i + border_length + 1 < board_size && i%border_length != border_length-1)
    {
        if (board[i+border_length+1] == 1)
        {
            neighbours++;
        }
    }

    if (board[i] == 1)
    {
        if (neighbours == 2 || neighbours == 3)
        {
            next_board[i] = 1;
        }
        else
        {
            next_board[i] = 0;
        }
    }
    else
    {
        if (neighbours == 3)
        {
            next_board[i] = 1;
        }
    }

}

bool checkGameOver(int* board, int board_size)
{

    for (int i = 0; i < board_size; i++) {
        if (board[i] == 1) {
            return false;
        }
    }

    return true;

}

void gameLoop(int* next_board, int* board, int board_size, int border_length)
{
    for (int i = 0; i < board_size; i++) {
        checkProximities(i, next_board, board, board_size, border_length);
    }
}

int* handleLoop(int* board, int board_size, int border_length)
{

    int* nextBoard = new int[board_size];

    for (int i = 0; i < board_size; i++) {
        nextBoard[i] = 0;
    }

    gameLoop(nextBoard, board, board_size, border_length);

    return nextBoard;

}

