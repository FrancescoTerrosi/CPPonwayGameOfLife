#include <iostream>
#include <cstring>

void printBoard(int* board, int board_size, int border_length);

void checkProximities(int i, int* next_board, int* board, int board_size, int border_length);

bool checkGameOver(int* board, int board_size);

int* gameLoop(int* board, int board_size, int border_length);

int* handleLoop(int* board, int board_size, int border_length);

