#include <iostream>

using namespace std;

int main(void) {

	/*
	���۷��� :  �ٸ������ �����ϰ� ������ִ� ���, ������ �ϰԵǸ�, �� ��� �����Ͽ� ���� ���氡��
	��, ���۷����� ó�� ���۷��� ����������, �����ϴ� ����� �������־�� ��.
	����Ÿ�� &���۷����� = �����Һ�����;

	
	*/

	int iNumber = 100;
	int iNumber1 = 9999;
	int &iRefNum = iNumber;  //iRevNum ���۷��� ������ iNumber������ ������
	
	iRefNum = 1234;
	iRefNum = iNumber1;    //iNumber1�� ���� 9999�� iRefNum�� �����ϴ� iNumber���� �־���� (iNumber=100 -> 9999)
	                       //������ ó�������� ���� �ٲ�(������ ����� �ٲٴ� ���� �ƴ�)
	cout << iNumber1 << endl;   //���۷��������� ������ ó�� ������ �޸𸮿� �����̾ƴ϶�, ���� �����Ͽ� ���� ������.
	cout << sizeof(iRefNum) << endl;  //��� : 4 (���۷�������)

	system("pause");
	return 0;
}