#include "Board.h"
#include<Windows.h>
#include<conio.h>
#include <iostream>
using namespace std;

#define	UP		72
#define	DOWN	80
#define	LEFT	75
#define RIGHT	77
#define ENTER	13
void gotoXY(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos); // 커서 이동
}

int ChessBoard::GetCommand(Piece _pBoard[][10], int turn) {
	int ax = 0, ay = 0, bx = 0, by = 0;
	int input = 0;
	int x = 3;
	int y = 1;
	int turn_ = turn;
	while (input != ENTER)
	{
		gotoXY(x, y);
		input = _getch();
		if (input == 224)
			input = _getch();
		switch (input)
		{
		case UP:
			if (y > 0)
				y--;
			break;
		case DOWN:
			if (y < 10)
				y++;
			break;
		case RIGHT:
			if (x < 10 * 3)
				x += 3;
			break;
		case LEFT:
			if (x > 0)
				x -= 3;
			break;
		case ENTER:
			ax = x / 3;
			ay = y;
			if (_pBoard[ay][ax].type == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "폰";
			}
			if (_pBoard[ay][ax].type == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "록";
			}
			if (_pBoard[ay][ax].type == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "나";
			}
			if (_pBoard[ay][ax].type == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "비";
			}
			if (_pBoard[ay][ax].type == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "퀸";
			}
			if (_pBoard[ay][ax].type == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "킹";
			}
			break;
		}
	}
	input = 0;
	while (input != ENTER)
	{
		gotoXY(x, y);
		input = _getch();
		if (input == 224)
			input = _getch();
		switch (input)
		{
		case UP:
			if (y > 0)
				y--;
			break;
		case DOWN:
			if (y < 10)
				y++;
			break;
		case RIGHT:
			if (x < 10 * 3)
				x += 3;
			break;
		case LEFT:
			if (x > 0)
				x -= 3;
			break;
		case ENTER:
			bx = x / 3;
			by = y;
			break;
		}
	}
	return MoveTo(ax, ay, bx, by, _pBoard, turn_);
}