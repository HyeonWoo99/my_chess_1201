#pragma once	// 해당 헤더파일이 여러번 include 되는 것을 방지
#include<stdio.h>
typedef struct Piece {	// typedef struct ~ << main함수에서 매번 struct를 사용할 필요 x
	int type;	// 1 Pawn 2 Rock 3 Knight 4 bishop 5 Queen 6 King
//	int x, y;
	int team;	// 0 black 1 white
}Piece;	//구조체 별칭

static Piece pBoard[10][10] = { 0, };
/* 0 1 2 3 4 5 6 7 8 9
0 -1-1-1-1-1-1-1-1-1-1
1 -1	            -1
2 -1                -1
3 -1                -1
4 -1                -1
5 -1                -1
6 -1                -1
7 -1                -1
8 -1                -1
9 -1-1-1-1-1-1-1-1-1-1
*/
class ChessBoard {
private:
//	static Piece pBoard[10][10];
	
public:
	ChessBoard(Piece _pBoard[][10]);
	Piece* ChessDisplay(Piece _pBoard[][10]);
	int MoveTo(int ax, int ay, int bx, int by, Piece _pBoard[][10]);
	int GetCommand2(Piece _pBoard[][10]);
	~ChessBoard() {

	}
};
