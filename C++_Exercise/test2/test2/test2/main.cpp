#include <iostream>

using namespace std;
int main() {

	std::cout << "Test Output" << std::endl;
	std::cout << "�����ٶ�" << std::endl;

								 //C++ǥ�ر���� ��κ��� std��� namespace�ȿ� ������. (�̸��ߺ��� �����ϱ�����)
								 //cout : console out, �ܼ�â�� ������ִ� ���, ū����ǥ �ȿ� �ִ� ���ڵ��� ȭ�鿡 �������
								 //endl = \n,��, ������ ����(enter)�� ��
	cout << "test2" << endl;
	int num = 229;
	cout << num << endl;

	bool btest;
	btest = false;
	cout << btest << endl;

	float fNumber = 3.14f;
	cout << fNumber << endl;
	double dNum = 3.14159;
	cout << dNum << endl;

	   //1����Ʈ, ��, �ѱ�,�ѹ�-1���ڴ� 2����Ʈ/����,����-1���ڴ� 1����Ʈ  ���� ->char ���� �ϳ��� �����ϱ� ����.(char-2����Ʈ)
	
	/* ��Ģ������ */
	cout << "10 < 20 = " << (10 < 20) << endl; //printf("10 < 20 = %d",(10<20))�� ����
	int Num;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> Num;  //scanf(%d,&Num)�� ����
	cout << ((10 <= Num) && (10 <= 20)) << endl;
	cout << "87 & 54 = " << (87 & 53) << endl;

	
	
	system("pause");
	return 0;
}