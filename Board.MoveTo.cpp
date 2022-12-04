#include"Board.h"
#include<algorithm>
#include<math.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
using namespace std;

int Pa(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]);
int Ro(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]);
int Kn(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]);
int Bi(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]);
int Qu(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]);
int Ki(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]);
void gotoXY(int x, int y);

int ChessBoard::MoveTo(int ax, int ay, int bx, int by, Piece _pBoard[][10]) {

	//	Piece _pBoard[10][10] = ChessBoard::_pBoard;
	int team = _pBoard[ay][ax].team;
	int type = _pBoard[ay][ax].type;
	int tmp_B[10][10] = { 0, };	//0 �Ұ��� 1 ���� 2 ����
	gotoXY(0, 13);
	if (ax < 1 || ax>8 || bx < 1 || bx>8 || ay < 1 || ay>8 || by < 1 || by>8) {
		return 0;
	}
	switch (type) {
	case -1:
		return 0;
		break;
	case 0:
		return 0;
		break;
	case 1:
		return Pa(team, ax, ay, bx, by, _pBoard);
		break;
	case 2:
		return Ro(team, ax, ay, bx, by, _pBoard);
		break;
	case 3:
		return Kn(team, ax, ay, bx, by, _pBoard);
		break;
	case 4:
		return Bi(team, ax, ay, bx, by, _pBoard);
		break;
	case 5:
		return Qu(team, ax, ay, bx, by, _pBoard);
		break;
	case 6:
		return Ki(team, ax, ay, bx, by, _pBoard);
		break;
	default:
		return 0;
		printf("   ");
	}

	return 0;
}
/// <summary>
/*
0  1  2  3  4  5  6  7  8  9
1  Ro Kn Bi Ki Qu Bi Kn Ro ��
2  Pa Pa Pa Pa Pa Pa Pa Pa ��
3  .. .. .. .. .. .. .. .. ��
4  .. .. .. .. .. .. .. .. ��
5  .. .. .. .. .. .. .. .. ��
6  .. .. .. .. .. .. .. .. ��
7  Pa Pa Pa Pa Pa Pa Pa Pa ��
8  Ro Kn Bi Ki Qu Bi Kn Ro ��
9  �� �� �� �� �� �� �� �� ��
*/
void _move(int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	_pBoard[by][bx].type = _pBoard[ay][ax].type;
	_pBoard[by][bx].team = _pBoard[ay][ax].team;
	_pBoard[ay][ax].type = 0;
	_pBoard[ay][ax].team = -1;
}
void Promotion(int bx, int by, Piece _pBoard[][10])
{
	int a;
	do
	{
		cout << "�ٲ� ���� �����ϼ���." << endl;
		cout << "1. Rock\n2. Knight\n3. Bishop\n4. Queen" << endl;
		cin >> a;

		switch (a)
		{
		case 1:
			_pBoard[by][bx].type = a + 1;
			break;
		case 2:
			_pBoard[by][bx].type = a + 1;
			break;
		case 3:
			_pBoard[by][bx].type = a + 1;
			break;
		case 4:
			_pBoard[by][bx].type = a + 1;
			break;
		default:
			cout << "�ٽ� �Է��ϼ���. " << endl << endl;
			break;
		}
	} while (a > 4 || a < 1);
}
int Pa(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	if (team == 1) {   // White
		if (_pBoard[by][bx].type > 0) {
			if (ay + 1 == by && abs(ax - bx) == 1) {
				_move(ax, ay, bx, by, _pBoard);
				if (ay == 7)
				{
					Promotion(bx, by, _pBoard);
				}
				return 2;
			}
		}
		else if (ay == 2) {
			if (ax == bx && (by - ay == 1 || (by - ay == 2 && _pBoard[ay + 1][by].type < 1))) {
				_move(ax, ay, bx, by, _pBoard);
				return 1;
			}

		}
		else {
			if ((ax == bx && by - ay == 1)) {
				_move(ax, ay, bx, by, _pBoard);
				if (ay == 7)
				{
					Promotion(bx, by, _pBoard);
				}
				return 1;
			}
		}
		return 0;
	}
	else if (team == 0) {      // Black
		if (_pBoard[by][bx].type > 0) {
			if (ay - 1 == by && abs(ax - bx) == 1) {
				_move(ax, ay, bx, by, _pBoard);
				if (ay == 2)
				{
					Promotion(bx, by, _pBoard);
				}
				return 2;
			}
		}
		else if (ay == 7) {
			if (ax == bx && (by - ay == -1 || (by - ay == -2 && _pBoard[ay - 1][by].type < 1))) {
				_move(ax, ay, bx, by, _pBoard);
				return 1;
			}

		}
		else {
			if ((ax == bx && by - ay == -1)) {
				_move(ax, ay, bx, by, _pBoard);
				if (ay == 2)
				{
					Promotion(bx, by, _pBoard);
				}
				return 1;
			}
		}
		return 0;
	}
	return 0;
}
int Ro(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	if (ax != bx && ay != by) {
		return 0;
	}

	if (ax == bx) {	//y�� �̵�
		for (int y = min(ay, by) + 1; y < max(ay, by); y++) {
			if (_pBoard[y][ax].type > 0) {
				return 0;
			}
		}
		if (_pBoard[by][bx].team != team) {
			_move(ax, ay, bx, by, _pBoard);
			return 2;
		}
		else if (_pBoard[by][bx].team == team) {
			return 0;
		}
		else if (_pBoard[by][bx].team == -1) {
			return 1;
		}
	}
	if (ay == by) {	//x�� �̵�
		for (int x = min(ax, bx) + 1; x < max(ax, bx); x++) {
			if (_pBoard[ay][x].type > 0) {
				return 0;
			}
		}
		if (_pBoard[by][bx].team != team) {
			_move(ax, ay, bx, by, _pBoard);
			return 2;
		}
		else if (_pBoard[by][bx].team == team) {
			return 0;
		}
		else if (_pBoard[by][bx].team == -1) {
			return 1;
		}
	}
	return 0;
}
int Kn(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	int tmp_Kn[9][2] = {
		{ax - 2,ay + 1},{ax - 2,ay - 1},{ax + 2,ay + 1},{ax + 2,ay - 1},
		{ax + 1,ay + 2},{ax - 1,ay + 2 },{ax + 1,ay - 2},{ax - 1,ay - 2}
	};
	for (int i = 0; i < 9; i++) {
		if (bx == tmp_Kn[i][0] && by == tmp_Kn[i][1]) {



			if (_pBoard[by][bx].type <= 0) {
				_move(ax, ay, bx, by, _pBoard);
				return 0;
			}
			else if (_pBoard[by][bx].type >= 1 && _pBoard[by][bx].team != team) {
				_move(ax, ay, bx, by, _pBoard);
				return 2;
			}
			else if (_pBoard[by][bx].type >= 1 && _pBoard[by][bx].team == team) {
				return 0;
			}
		}
	}
	return 0;
}
int Bi(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	if (abs(ax - bx) != abs(ay - by)) {
		return 0;
	}
	int N = abs(ax - bx);
	if (ax > bx && ay > by) {	//7
		for (int i = 1; i < N - 1; i++) {
			if (_pBoard[ay - i][ax - i].type >= 1) {
				return 0;
			}
		}
	}
	if (ax > bx && ay < by) {	//1
		for (int i = 1; i < N - 1; i++) {
			if (_pBoard[ay + i][ax - i].type >= 1) {
				return 0;
			}
		}
	}
	if (ax < bx && ay > by) {	//9
		for (int i = 1; i < N - 1; i++) {
			if (_pBoard[ay - i][ax + i].type >= 1) {
				return 0;
			}
		}
	}
	if (ax < bx && ay < by) {	//3
		for (int i = 1; i <= N - 1; i++) {
			if (_pBoard[ay + i][ax + i].type >= 1) {
				return 0;
			}
		}
	}
	if (_pBoard[by][bx].type <= 0) {
		_move(ax, ay, bx, by, _pBoard);
		return 1;
	}
	else if (_pBoard[by][bx].team == team) {
		return 0;
	}
	else if (_pBoard[by][bx].team != team && _pBoard[by][bx].team != -1) {
		_move(ax, ay, bx, by, _pBoard);
		return 2;
	}

	return 0;
}
int Qu(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	int Rtmp = Ro(team, ax, ay, bx, by, _pBoard);
	int Btmp = Bi(team, ax, ay, bx, by, _pBoard);


	return 0;
}
int Ki(int team, int ax, int ay, int bx, int by, Piece _pBoard[][10]) {
	if (ax == 4 && ay == 1 && bx == 2 && by == 1 && _pBoard[1][1].type == 2 && _pBoard[1][3].type < 1 && team == 1)
	{
		cout << "Castling �Ͽ����ϴ�." << endl;
		Ro(1, 1, 1, 3, 1, _pBoard);
		_move(ax, ay, bx, by, _pBoard);
		return 1;
	}
	if (ax ==  4&& ay == 8 && bx == 2 && by == 8 && _pBoard[8][1].type == 2 && _pBoard[8][3].type < 1 && team == 0)
	{
		cout << "Castling �Ͽ����ϴ�." << endl;
		Ro(0, 1, 8, 3, 8, _pBoard);
		_move(ax, ay, bx, by, _pBoard);
		return 1;
	}
	else if (abs(ay - by) > 1 || abs(ax - bx) > 1) {
		return 0;
	}

	if (_pBoard[by][bx].team == team) {
		return 0;
	}
	else if (_pBoard[by][bx].type < 1) {
		_move(ax, ay, bx, by, _pBoard);
		return 1;
	}
	else if (_pBoard[by][bx].team != team) {
		_move(ax, ay, bx, by, _pBoard);
		return 2;
	}
	else
		return 0;
}