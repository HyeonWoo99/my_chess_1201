#pragma once	// 해당 헤더파일이 여러번 include 되는 것을 방지
#include<stdio.h>
typedef struct Piece {	// typedef struct ~ << main함수에서 매번 struct를 사용할 필요 x
	int type;	// 1 Pawn 2 Rock 3 Knight 4 bishop 5 Queen 6 King
	//	int x, y;
	int team;	// 0 블랙 1 화이트
}Piece;	//구조체 별칭

static Piece pBoard[10][10] = { 0, };


class ChessBoard {
public:
	ChessBoard(Piece _pBoard[][10]);
	Piece* ChessDisplay(Piece _pBoard[][10],int turn);
	int MoveTo(int ax, int ay, int bx, int by, Piece _pBoard[][10], int turn);
	int GetCommand(Piece _pBoard[][10], int turn);
	~ChessBoard() {

	}
};
