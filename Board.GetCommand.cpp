#define _CRT_SECURE_NO_WARNINGS
#include"Board.h"
#include<algorithm>
#include <iostream>

using namespace std;

int ChessBoard::GetCommand(Piece _pBoard[][10]) {
	int ax, ay, bx, by;
	cin >> ax;
	cin >> ay;

	int type = _pBoard[ay][ax].type;
	switch (type) {
	case -1:
		cout << "คำ ";
		break;
	case 0:
		cout <<".. ";
		break;
	case 1:
		cout <<"Pa ";
		break;
	case 2:
		cout <<"Ro ";
		break;
	case 3:
		cout <<"Kn ";
		break;
	case 4:
		cout <<"Bi ";
		break;
	case 5:
		cout <<"Qu ";
		break;
	case 6:
		cout <<"Ki ";
		break;
	default:
		cout <<"   \n";
	}
	cout <<"\n";
	cin >> bx >> by;
	
	cout <<"%d %d\n", _pBoard[ay][ax].team, _pBoard[ay][ax].type;
	if (ax == -1)
		exit(0);
	return MoveTo(ax, ay, bx, by, _pBoard);
}