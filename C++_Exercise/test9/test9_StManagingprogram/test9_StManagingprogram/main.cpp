#include <iostream>

using namespace std;
#define namesize 32
#define STUDENT_MAX	10  //�ִ� �л���ϸ�� ����
#define ADDRESSSIZE 128 //�л�������, �ִ� �ּһ������� ũ�� ����
#define PHONE_SIZE 14 //�л�������, ��ȭ��ȣ������ ũ�� ���� 

typedef struct {
	char strname[namesize];
	char straddress[ADDRESSSIZE];
	char strphone[PHONE_SIZE];
	int inum;
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}_tagStudent;

enum Menu {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main(void) {
	_tagStudent tStudetnArr[STUDENT_MAX] = {};  //0���� ����ü�� ��� ������ �ʱ�ȭ
	char strname[namesize] = {};
	int iStudentcount = 0;
	int iStudentnum = 1;  //�й��� 1������ ����

	while (1) {
		system("cls");

		//�޴��� �����
		cout << "1. �л���� " << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		
			
		cin >> iMenu;  //�޴� �Է�(scanf)  /*���� �Է��ؾ��� ���� �������ε�, �Ǽ��� ���ڸ� �Է��ߴٸ�? ����ó���ʿ�*/

		if (cin.fail()) {  //cin.fail�� ����ϸ� cin�� �Է¿����� �߻����� ���, true�� ��ȯ�Ǿ� ���ǹ��� ������
			//�������۸� ����
			cin.clear();
			//cin.ignore(�˻��ϰ����ϴ� ������ ũ�⸦ ����, '\n') �̶�, \n�� ���๮�ڷ� \n�� �ִ� ������ �а� ����
			cin.ignore(1024, '\n');
			continue;  //while(1)���ȿ��� �����Ե� ��, �ٽ� cin�� �Է¹ް� ��
		}
			
				//
		
		
		
		if (iMenu == MENU_EXIT) {
			break;
		}
		switch (iMenu) {
		case MENU_INSERT:      //�л������� �й�,�̸�, �ּ�,��ȭ��ȣ�� ��ϵ�.
			if (iStudentcount == STUDENT_MAX)  //��ϵ� �л����� �ִ� ����л����� ������ ����� �׸��ϵ��� ó��
				break;
			system("cls");
			cout << "====================" << endl;
			cout << "�̸� : ";
			cin >> tStudetnArr[iStudentcount].strname;
			  //�̸��� �Է��Ҷ� �� ����(\n)�� �Է¹��ۿ��� ����ó������
			cin.ignore(1024, '\n');
			cout << "�ּ� ; ";
			cin.getline(tStudetnArr[iStudentcount].straddress,ADDRESSSIZE);  //cin�� �̿��ϸ�, �����̽���(����)�� ������ ������ �ν��ϰԵ�
																 //����, cin.getline�� �̿��Ͽ� ���⵵ �����Ͽ� ���ڿ��� ������ ����
			cout << "��ȭ��ȣ : ";
			cin.getline(tStudetnArr[iStudentcount].strphone, PHONE_SIZE);
			
			cout << "�������� : ";
			cin >> tStudetnArr[iStudentcount].ikor;

			cout << "�������� : ";
			cin >> tStudetnArr[iStudentcount].ieng;
			
			cout << "�������� : ";
			cin >> tStudetnArr[iStudentcount].imath;

			tStudetnArr[iStudentcount].itotal = tStudetnArr[iStudentcount].ikor +
											    tStudetnArr[iStudentcount].ieng +
												tStudetnArr[iStudentcount].imath;

			tStudetnArr[iStudentcount].favg = (tStudetnArr[iStudentcount].ikor +
											   tStudetnArr[iStudentcount].ieng +
											   tStudetnArr[iStudentcount].imath)/3.f;
			++iStudentcount;
			++iStudentnum;
			break;

		case MENU_DELETE:
			system("cls");
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin.getline(strname, namesize);

			//��ϵǾ� �ִ� �л�����ŭ �ݺ��Ͽ� �л��� ã�´�
			for (int i = 0; i < iStudentcount; ++i) {
				if (strcmp(tStudetnArr[i].strname, strname) == 0) //�л��� ã���� ��� strcmp(���ڿ�, ���ڿ�), ���ڿ����� ������ 0�� ��ȯ
				{
					for (int j = i; j < iStudentcount - 1; ++j) {
						tStudetnArr[j] = tStudetnArr[j + 1];
					}
					--iStudentcount;
					cout << "�л��� �����Ͽ����ϴ�" << endl;
					break;
					
				}
			}
			cout << "ã�� �л��� ��Ͽ� �����ϴ�" << endl;	
			break;

		case MENU_SEARCH:
			system("cls");
			cout << "==========�л�Ž��=========" << endl;
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �˻��ϼ��� : ";
			cin.getline(strname, namesize);
			
			//��ϵǾ� �ִ� �л�����ŭ �ݺ��Ͽ� �л��� ã�´�
			for (int i = 0; i < iStudentcount; ++i) {
				if (strcmp(tStudetnArr[i].strname, strname) == 0) //�л��� ã���� ��� strcmp(���ڿ�, ���ڿ�), ���ڿ����� ������ 0�� ��ȯ
				{
					cout << "�̸� : ";
					cout << tStudetnArr[i].strname << endl;
					cout << "�ּ� ; ";
					cout << tStudetnArr[i].straddress << endl;
					cout << "��ȭ��ȣ : ";
					cout << tStudetnArr[i].strphone << endl;
					cout << "�������� : ";
					cout << tStudetnArr[i].ikor << endl;
					cout << "�������� : ";
					cout << tStudetnArr[i].ieng << endl;

					cout << "�������� : ";
					cout << tStudetnArr[i].imath << endl;

					cout << "���� : ";
					cout << tStudetnArr[i].itotal << endl;
					cout << "��� : ";
					cout << tStudetnArr[i].favg << endl;
					break;
				}
				if(i==iStudentcount-1)
				{	
					cout << "ã�� �л��� ��Ͽ� �����ϴ�" << endl;
					break;
				}
				
			}
			
			break;

		case MENU_OUTPUT:
			system("cls");
			cout << "=========�л����=========" << endl;
			//��ϵ� �л�����ŭ �ݺ�
			for (int i = 0; i < iStudentcount; ++i) {
				cout << "�̸� : ";
				cout << tStudetnArr[i].strname << endl;
				cout << "�ּ� ; ";
				cout << tStudetnArr[i].straddress << endl;
				cout << "��ȭ��ȣ : ";
				cout << tStudetnArr[i].strphone << endl;
				cout << "�������� : ";
				cout << tStudetnArr[i].ikor << endl;
				cout << "�������� : ";
				cout << tStudetnArr[i].ieng << endl;

				cout << "�������� : ";
				cout << tStudetnArr[i].imath << endl;

				cout << "���� : ";
				cout << tStudetnArr[i].itotal << endl;
				cout << "��� : ";
				cout << tStudetnArr[i].favg << endl;
			}
			break;
		default : 
			cout << "�޴��� �߸��Է��Ͽ����ϴ�" << endl;
			break;
		}
		system("pause");  //
	}


	return 0;
}