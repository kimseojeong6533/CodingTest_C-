#include <iostream>
#include <time.h>
using namespace std;

enum SRP {
	SRP_S=1,
	SRP_R,
	SRP_P,
	SRP_END
}; //����=1, ����=2, ��=3
int iAI;

int main(void) {

	int iPlayer;
	system("cls"); //����ȭ���� �����ϰ� ������
	//���� ���̺��� ����
	srand((unsigned int)time(0));

	while (1) {
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;
		if (iPlayer < SRP_S || iPlayer >SRP_END)
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�" << endl;
			system("pause"); //�Ͻ�����
			continue; //�ٽ� �Է�
		}
		else if (iPlayer == SRP_END) {
			break;
		}
		else {

			//���� ������
			iAI = rand() % 3 + SRP_S; //iAI�� 1~3���� 

			switch (iAI)
			{
			case SRP_S:
				cout << "AI : ����" << endl;
				break;
			case SRP_R:
				cout << "AI : ����" << endl;
				break;
			case SRP_P:
				cout << "AI : ��" << endl;
				break;

			}
			int iWin = iPlayer - iAI;

			if (iWin == 1 || iWin == -2)
				cout << "Player�� �¸�" << endl;
			else if (iWin == 0)
				cout << "���" << endl;
			else
				cout << "Player�� �й�" << endl;
		}
	}
	return 0;
}