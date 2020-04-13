#include <iostream>
using namespace std;

/*����ü : ���ӵ� ���ڿ� �̸��� �ο��ϴ� ���
	���� : enum ����ü�� {}
	����ü���� �̿��ؼ� ����üŸ���� �������� �����ϴ�.
	��, ����ü�� ��������� ����Ÿ���� �ɼ��� �ִ�. (����ڰ� ����Ÿ���� ��������)
	*/

enum NUM {
	NUM_0,  //�ƹ� ���� ���� ������ 0���� 1�� �����Ͽ� ���ʴ�� ������ ����ʴ�. -> Switch���� case �ڿ� Ȱ���ϴ� �뵵�� �ַ� ����.
	NUM_1,
	NUM_2,
	NUM_3
};

#define Max 1000


int main(void) {

	/*switch�� : ���� �������� üũ�ϴ� �� 
	
	*/
	int iNum;
	cout << "���ڸ� �Է� : ";
	cin >> iNum;

	switch (iNum) {
	case NUM_0: 
		cout << "�Է��� ���ڴ� 0�Դϴ�" << endl;
		break;
	case NUM_1:
		cout << "�Է��� ���ڴ� 1�Դϴ�" << endl;
		break;
	case NUM_2:
		cout << "�Է��� ���ڴ� 2�Դϴ�" << endl;
		break;
	default: //case�� �����Ǿ� ���� �ʴ� ���ڰ� �����
		cout << "�׿��� �����Դϴ�" << endl;
		break;
	}
	NUM eNum=(NUM)1;  //����ü Ÿ���� ������ ������ 4byte�� ������. , ����ü�� �̿��ؼ� ������ ������ ���� ǥ�������� ����ü�� ������ ���� �ȿ��� ���õ�.
	cout << sizeof(eNum) << endl;  //����� 4  //������ ũ�� �Ǵ� �޸�ũ�⸦ �˷��ִ� �Լ� : sizeof
	cout << typeid(NUM).name() << endl;  //�����  enum NUM, ������ Ÿ���� ���ڿ��� ��ȯ���ִ� �Լ� : typeid


	system("pause");
	return 0;
}