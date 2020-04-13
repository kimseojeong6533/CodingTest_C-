#include <iostream>
#include <time.h>
using namespace std;

enum SRP {
	SRP_S=1,
	SRP_R,
	SRP_P,
	SRP_END
}; //가위=1, 바위=2, 보=3
int iAI;

int main(void) {

	int iPlayer;
	system("cls"); //도스화면을 깨끗하게 지워줌
	//난수 테이블을 생성
	srand((unsigned int)time(0));

	while (1) {
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;
		if (iPlayer < SRP_S || iPlayer >SRP_END)
		{
			cout << "잘못된 값을 입력하였습니다" << endl;
			system("pause"); //일시정지
			continue; //다시 입력
		}
		else if (iPlayer == SRP_END) {
			break;
		}
		else {

			//봇이 선택함
			iAI = rand() % 3 + SRP_S; //iAI는 1~3까지 

			switch (iAI)
			{
			case SRP_S:
				cout << "AI : 가위" << endl;
				break;
			case SRP_R:
				cout << "AI : 바위" << endl;
				break;
			case SRP_P:
				cout << "AI : 보" << endl;
				break;

			}
			int iWin = iPlayer - iAI;

			if (iWin == 1 || iWin == -2)
				cout << "Player가 승리" << endl;
			else if (iWin == 0)
				cout << "비김" << endl;
			else
				cout << "Player가 패배" << endl;
		}
	}
	return 0;
}