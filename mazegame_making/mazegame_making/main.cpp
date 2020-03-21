#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;



/*
0 : ��
1 : ��
2 : ������
3 : ������
4 : ��ź
5 : ��ź����Ʈ
*/
struct _tagPoint{
	int x;
	int y;
};

//Ÿ���� ������ 
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

int iBombCount = 0;
POINT tBombPos[5] = {};  //��ġ�� ��ź�� ��ġ ����

void SetMaze(char Maze[21][21],PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;  //������ ��ġ�� (0,0)
	*pPlayerPos = *pStartPos; //

	pEndPos->x = 19;
	pEndPos->y = 19;

	strcpy_s(Maze[0], "21100000000000000000");
	strcpy_s(Maze[1], "00111111111100000000");
	strcpy_s(Maze[2], "00100010000111111100");
	strcpy_s(Maze[3], "01100010000000000100");
	strcpy_s(Maze[4], "01000011110001111100");
	strcpy_s(Maze[5], "01000000001111000000");
	strcpy_s(Maze[6], "01100000001000000000");
	strcpy_s(Maze[7], "00100000001111111000");
	strcpy_s(Maze[8], "00001110000000001000");
	strcpy_s(Maze[9], "01111011111111111000");
	strcpy_s(Maze[10], "01000000000000000000");
	strcpy_s(Maze[11], "01111100111111100000");
	strcpy_s(Maze[12], "00000111100000111110");
	strcpy_s(Maze[13], "01111100000000000010");
	strcpy_s(Maze[14], "01000000001111111110");
	strcpy_s(Maze[15], "01111110011000000000");
	strcpy_s(Maze[16], "00000010010000000000");
	strcpy_s(Maze[17], "01111110011111000000");
	strcpy_s(Maze[18], "01000000000001100000");
	strcpy_s(Maze[19], "11000000000000111113");
	
}

void Output(char Maze[21][21],PPOINT pPlayerPos) {
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {

			if (Maze[i][j] == '4') {  //��ź 
				cout << "��";
			}
			else if (pPlayerPos->x == j && pPlayerPos->y == i) { //�÷��̾���ġ 
				cout << "��";
			}
			else if (Maze[i][j] == '0') {  //��
				cout << "��";  //Ư�����ڴ� 2byte
			}
			else if (Maze[i][j] == '1') {  //��
				cout << "  ";
			}
			else if (Maze[i][j] == '2') {  //������
				cout << "��";
			}
			else if (Maze[i][j] == '3') {  //������
				cout << "��";
			}
			
		}
		cout << " " << endl;
	}
}

void Moveup(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y - 1 >= 0)  // y���� 0�� �ƴҶ��� (��, �������� �ƴҶ���) �÷��̾� ��ġ�� ���� �÷��� 
	{
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' && Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4') //�̷ΰ� ���� �ƴϰ�, ��ź�� ����� ��ġ�̵�����
		{
			--pPlayerPos->y;
		}
	}
}

void Movedown(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y + 1 <= 20)  // y���� 19���� �϶���,  
	{
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' && Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4') //�̷ΰ� ���� �ƴ� ���
		{
			++pPlayerPos->y;
		}
	}
}

void Moveright(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 < 20)  // y���� 19���� �϶���,  
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0' && Maze[pPlayerPos->y][pPlayerPos->x+1] != '4') //�̷ΰ� ���� �ƴ� ���
		{
			++pPlayerPos->x;
		}
	}
}

void Moveleft(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0)  // y���� 19���� �϶���,  
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' && Maze[pPlayerPos->y][pPlayerPos->x-1] != '4') //�̷ΰ� ���� �ƴ� ���
		{
			--pPlayerPos->x;
		}
	} 
}


void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput) {
	switch (cInput) 
	{ 
	case 'w': 
	case 'W':
		Moveup(Maze, pPlayerPos);
		break;

	case 'a':
	case 'A':
		Moveleft(Maze, pPlayerPos);
		break;

	case 'd':
	case 'D':
		Moveright(Maze, pPlayerPos);
		break;

	case 's':
	case 'S':
		Movedown(Maze, pPlayerPos);
		break;
	}
}

void Fire(char maze[21][21], PPOINT pPlayer, PPOINT pBombArr, int* pBombCount) 
{
	for (int i = 0; i < *pBombCount; ++i) 
	{
		maze[pBombArr[i].y][pBombArr[i].x] = '1';  //��ź�� ��ġ�� ������

		if (pBombArr[i].y - 1 >= 0) 
		{
			if (maze[pBombArr[i].y - 1][pBombArr[i].x] == '0') //��ź��ġ�� �ٷ����� ���̶��
				maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';  //��� ����.

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1) 
			{ //�÷��̾ ��ź �ٷ� ���ʿ� ��ġ������ �� ��ź�� �Ͷ߸��� ���������� ����.
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].y + 1 < 20) 
		{
			if (maze[pBombArr[i].y + 1][pBombArr[i].x] == '0') //��ź��ġ�� �ٷξƷ��� ���̶��
				maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';  //��� ����.

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1) 
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].x - 1 >= 0) 
		{
			if (maze[pBombArr[i].y][(pBombArr[i].x) - 1] == '0') //��ź��ġ�� �ٷ� ������ ���̶��
				maze[pBombArr[i].y][(pBombArr[i].x) - 1] = '1';  //��� ����.
			if (pPlayer->x == (pBombArr[i].x) - 1 && pPlayer->y == (pBombArr[i].y)) 
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].x + 1 < 20) 
		{
			if (maze[pBombArr[i].y][pBombArr[i].x + 1] == '0') //��ź��ġ�� �ٷ� �������� ���̶��
				maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';  //��� ����.
			if (pPlayer->x == (pBombArr[i].x) + 1 && pPlayer->y == (pBombArr[i].y)) 
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

	}
	*pBombCount = 0;
}

void CreateBomb(char maze[21][21], const PPOINT pPlayer,PPOINT pBombArr,int* pBombCount) {
	
	if (*pBombCount >= 5) 
		return; 
	

	for (int i = 0; i < *pBombCount; ++i) {  //�������� ��ź��ġ �Ұ�
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
		{
			return;
		}
	}
	pBombArr[*pBombCount] = *pPlayer;  //pBombArr���� ��ġ�� ��ź�� ��ġ(x,y)�� �����. 
	++*pBombCount;  //��ź�� 5�������� ��ġ����
	cout << *pBombCount << endl;
	maze[pPlayer->y][pPlayer->x] = '4';   //��ġ�� ���� ��ź��ũ ǥ��
}


int main(void) {

	//20 x 20 �̷θ� �����

	char strMaze[21][21] = {};
	
	POINT tPlayerPos;  //�÷��̾�������
	POINT tStartPos;  //����������
	POINT tEndPos;    //����������
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);  //�̷θ� ����


	while (1) {
		system("cls");
		
		//�̷θ� ����Ѵ�
		Output(strMaze,&tPlayerPos);
		cout << "" << endl;
		cout << "w : ��, s : �Ʒ�, a : ����, d : ������, t : ��ź��ġ, u : ��ź ��Ʈ����, q : ����";
		char cInput = _getch(); //Ű���� �Է��� �޵� ����� ���ϴ� �Լ���

		if (cInput == 'q' || cInput == 'Q') 
			break;
		else if (cInput == 'u' || cInput == 'U')   //�÷��̾ u�� ������ ��ź�� ����.
			Fire(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		else if (cInput == 't' || cInput == 'T')   //�÷��̾ T�� ������ ��ź�� ��ġ��.
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);  //�̷��� �÷��̾� ��ġ�� ��ź�� ǥ�õ�.
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);

	}
	
	return 0;
}