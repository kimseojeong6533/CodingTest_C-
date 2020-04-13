#include <iostream>
#include <time.h>
using namespace std;

int main(void) {

	//난수 발생 
	srand((unsigned int)time(0));  //time(0) = 현재시간을 기준으로 time값을 뽑아 올 수 있음 이때, unsigned int로 형변환을 하여 0~양수값이 나오도록 해줌
	
	cout << rand() << endl;   //rand() : 임의의값을 얻어오는 기능
	cout << rand() << endl;
	cout << rand() << endl;
	cout << (rand()%101+100) << endl;  //0~99까지의 난수만 나올수 있도록 %100처리
	cout << (rand() % 10000 / 100.f) << endl; // 0.00~99.99까지 표현됨 ('100.f'는 소수점까지 표현해라!의 의미임)
	


	int iUpgrade = 0;
	cout << "Upgrade 기본수치를 구하세요 : ";
	cin >> iUpgrade;

	//강화확률을 구한다.
	float fPercent = (rand() % 10000 / 100.f);
	//강화확률 : 업그레이드가 0~3 : 100%성공, 4~6 : 40%성공, 7~9 : 10%성공, 10~13 : 1%성공, 14~15 : 0.01%성공
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3) {
		cout << "강화성공" << endl;
	}
	else if (iUpgrade >= 4 && iUpgrade <= 6) {
		if (fPercent < 40.f) {
			cout << "강화성공" << endl;
		}
		else
			cout << "강화 실패 " << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9) {
		if (fPercent < 10.f) {
			cout << "강화성공" << endl;
		}
		else
			cout << "강화실패" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13) {
		if (fPercent < 1.f) {
			cout << "강화성공" << endl;
		}
		else
			cout << "강화실패" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15) {
		if (fPercent < 0.01f) {
			cout << "강화성공" << endl;
		}
		else
			cout << "강화실패" << endl;
	}
	else
		cout << "강화실패" << endl;


	system("pause");
	return 0;
}