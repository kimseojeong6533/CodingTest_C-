#include <iostream>
using namespace std;
#define Max 32
//�����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ����� �ִ� ��� : ����ü
//���� : typedef Struct{}����ü�̸�;

typedef struct{
	int inum;  //�й�
	char strname[Max];
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}_tagStudent;  //�л� ����ü ����


int main(void) {

	_tagStudent tStudent= {};  //�ʱ�ȭ��.
	//����ü ����� �����Ҷ��� .�� ���
	
	//���ڿ��� �迭�� ���� ������ �ܼ�����(strname="������")���δ� �Ұ�
	//strcpy_s��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� ��

	strcpy_s(tStudent.strname, "�����ٶ�");
	cout << tStudent.strname << endl;
	system("pause");
	return 0;
}