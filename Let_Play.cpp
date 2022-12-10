#include "Let_Play.h"
#include<iostream>

using namespace std;

ChessPlay::ChessPlay() {
	ChessBoard Board = ChessBoard(pBoard);
	int turn = 1;
	while (1) {
		Board.ChessDisplay(pBoard, turn);


		int tmp = Board.GetCommand(pBoard, turn);
		if (tmp >= 1)
			turn++;
	}
}
ChessPlay::~ChessPlay() {

}