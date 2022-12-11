#pragma once	// �ش� ��������� ������ include �Ǵ� ���� ����
#include<stdio.h>
typedef struct Piece {	// typedef struct ~ << main�Լ����� �Ź� struct�� ����� �ʿ� x
	int type;	// 1 Pawn 2 Rock 3 Knight 4 bishop 5 Queen 6 King
	//	int x, y;
	int team;	// 0 �� 1 ȭ��Ʈ
}Piece;	//����ü ��Ī

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
