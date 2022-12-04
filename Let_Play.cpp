#include "Let_Play.h"
#include<iostream>

using namespace std;

ChessPlay::ChessPlay() {
	//	cout << "1\n";
	ChessBoard Board = ChessBoard(pBoard);
	//	cout << "2\n";
	int turn = 1;
	while (1) {
		Board.ChessDisplay(pBoard);


		int tmp = Board.GetCommand2(pBoard);
		if (tmp >= 1)
			turn++;
	}
	//	cout << "3\n";
}
ChessPlay::~ChessPlay() {

}