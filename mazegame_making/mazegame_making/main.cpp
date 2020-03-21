#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;



/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 폭탄이펙트
*/
struct _tagPoint{
	int x;
	int y;
};

//타입을 재정의 
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

int iBombCount = 0;
POINT tBombPos[5] = {};  //설치한 폭탄의 위치 저장

void SetMaze(char Maze[21][21],PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;  //시작점 위치는 (0,0)
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

			if (Maze[i][j] == '4') {  //폭탄 
				cout << "♨";
			}
			else if (pPlayerPos->x == j && pPlayerPos->y == i) { //플레이어위치 
				cout << "☆";
			}
			else if (Maze[i][j] == '0') {  //벽
				cout << "■";  //특수문자는 2byte
			}
			else if (Maze[i][j] == '1') {  //길
				cout << "  ";
			}
			else if (Maze[i][j] == '2') {  //시작점
				cout << "★";
			}
			else if (Maze[i][j] == '3') {  //도착점
				cout << "◎";
			}
			
		}
		cout << " " << endl;
	}
}

void Moveup(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y - 1 >= 0)  // y값이 0이 아닐때만 (즉, 시작점이 아닐때만) 플레이어 위치를 위로 올려줌 
	{
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' && Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4') //미로가 벽이 아니고, 폭탄이 없어야 위치이동가능
		{
			--pPlayerPos->y;
		}
	}
}

void Movedown(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y + 1 <= 20)  // y값이 19이하 일때만,  
	{
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' && Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4') //미로가 벽이 아닐 경우
		{
			++pPlayerPos->y;
		}
	}
}

void Moveright(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 < 20)  // y값이 19이하 일때만,  
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0' && Maze[pPlayerPos->y][pPlayerPos->x+1] != '4') //미로가 벽이 아닐 경우
		{
			++pPlayerPos->x;
		}
	}
}

void Moveleft(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0)  // y값이 19이하 일때만,  
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' && Maze[pPlayerPos->y][pPlayerPos->x-1] != '4') //미로가 벽이 아닐 경우
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
		maze[pBombArr[i].y][pBombArr[i].x] = '1';  //폭탄의 위치를 없애줌

		if (pBombArr[i].y - 1 >= 0) 
		{
			if (maze[pBombArr[i].y - 1][pBombArr[i].x] == '0') //폭탄위치의 바로위가 벽이라면
				maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';  //길로 만듦.

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1) 
			{ //플레이어가 폭탄 바로 위쪽에 위치해있을 때 폭탄을 터뜨리면 시작점으로 보냄.
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].y + 1 < 20) 
		{
			if (maze[pBombArr[i].y + 1][pBombArr[i].x] == '0') //폭탄위치의 바로아래가 벽이라면
				maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';  //길로 만듦.

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1) 
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].x - 1 >= 0) 
		{
			if (maze[pBombArr[i].y][(pBombArr[i].x) - 1] == '0') //폭탄위치의 바로 왼쪽이 벽이라면
				maze[pBombArr[i].y][(pBombArr[i].x) - 1] = '1';  //길로 만듦.
			if (pPlayer->x == (pBombArr[i].x) - 1 && pPlayer->y == (pBombArr[i].y)) 
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].x + 1 < 20) 
		{
			if (maze[pBombArr[i].y][pBombArr[i].x + 1] == '0') //폭탄위치의 바로 오른쪽이 벽이라면
				maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';  //길로 만듦.
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
	

	for (int i = 0; i < *pBombCount; ++i) {  //같은곳에 폭탄설치 불가
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
		{
			return;
		}
	}
	pBombArr[*pBombCount] = *pPlayer;  //pBombArr에는 설치한 폭탄의 위치(x,y)가 저장됨. 
	++*pBombCount;  //폭탄은 5개까지만 설치가능
	cout << *pBombCount << endl;
	maze[pPlayer->y][pPlayer->x] = '4';   //설치한 곳에 폭탄마크 표시
}


int main(void) {

	//20 x 20 미로를 만든다

	char strMaze[21][21] = {};
	
	POINT tPlayerPos;  //플레이어포지션
	POINT tStartPos;  //시작포지션
	POINT tEndPos;    //도착포지션
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);  //미로를 설정


	while (1) {
		system("cls");
		
		//미로를 출력한다
		Output(strMaze,&tPlayerPos);
		cout << "" << endl;
		cout << "w : 위, s : 아래, a : 왼쪽, d : 오른쪽, t : 폭탄설치, u : 폭탄 터트리기, q : 종료";
		char cInput = _getch(); //키보드 입력은 받되 출력은 안하는 함수임

		if (cInput == 'q' || cInput == 'Q') 
			break;
		else if (cInput == 'u' || cInput == 'U')   //플레이어가 u를 누르면 폭탄이 터짐.
			Fire(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		else if (cInput == 't' || cInput == 'T')   //플레이어가 T를 누르면 폭탄이 설치됨.
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);  //미로의 플레이어 위치에 폭탄이 표시됨.
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);

	}
	
	return 0;
}