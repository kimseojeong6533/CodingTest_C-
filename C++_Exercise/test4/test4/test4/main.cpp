#include <iostream>
#include <time.h>
using namespace std;

int main(void) {

	//���� �߻� 
	srand((unsigned int)time(0));  //time(0) = ����ð��� �������� time���� �̾� �� �� ���� �̶�, unsigned int�� ����ȯ�� �Ͽ� 0~������� �������� ����
	
	cout << rand() << endl;   //rand() : �����ǰ��� ������ ���
	cout << rand() << endl;
	cout << rand() << endl;
	cout << (rand()%101+100) << endl;  //0~99������ ������ ���ü� �ֵ��� %100ó��
	cout << (rand() % 10000 / 100.f) << endl; // 0.00~99.99���� ǥ���� ('100.f'�� �Ҽ������� ǥ���ض�!�� �ǹ���)
	


	int iUpgrade = 0;
	cout << "Upgrade �⺻��ġ�� ���ϼ��� : ";
	cin >> iUpgrade;

	//��ȭȮ���� ���Ѵ�.
	float fPercent = (rand() % 10000 / 100.f);
	//��ȭȮ�� : ���׷��̵尡 0~3 : 100%����, 4~6 : 40%����, 7~9 : 10%����, 10~13 : 1%����, 14~15 : 0.01%����
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3) {
		cout << "��ȭ����" << endl;
	}
	else if (iUpgrade >= 4 && iUpgrade <= 6) {
		if (fPercent < 40.f) {
			cout << "��ȭ����" << endl;
		}
		else
			cout << "��ȭ ���� " << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9) {
		if (fPercent < 10.f) {
			cout << "��ȭ����" << endl;
		}
		else
			cout << "��ȭ����" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13) {
		if (fPercent < 1.f) {
			cout << "��ȭ����" << endl;
		}
		else
			cout << "��ȭ����" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15) {
		if (fPercent < 0.01f) {
			cout << "��ȭ����" << endl;
		}
		else
			cout << "��ȭ����" << endl;
	}
	else
		cout << "��ȭ����" << endl;


	system("pause");
	return 0;
}