#include <iostream>
#include "Let_Play.h"
using namespace std;


/// Board() -> ������
/// ����ü Pieces -> �� ���� ����, 
/// MoveTo() -> ������ ������ �̵�
/// display() -> ���� �������� ���� ǥ��
/// 
/// Board���� �� ����(command->move->display) �ݺ�

int main() {
	ChessPlay Play = ChessPlay();

	Play.~ChessPlay();
	return 0;
}