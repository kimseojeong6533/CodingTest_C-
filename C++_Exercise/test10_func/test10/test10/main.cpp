#include <iostream>
using namespace std;
int g_num;
int Sum(int a, int b) {
	//���Լ��� ��ȯŸ�Կ� �´� ���� ��ȯ.(int Sum�̹Ƿ�, int ������ ��ȯ), �̷����¸� Call by Value��� ��
	return a + b;
}

void OutputText() {

	//�Լ��� ��ȯ���� void�̹Ƿ� ��ȯ���� ���� ��� �ȴ�. 
	cout << "test" << endl;
}
void ChangeNum(int a) {
	a = 1111;
}

//Call by Address�Լ� (�����͸� ���ڷ� ����� �Լ� ) 
void ChangeNumber(int* pNumber) { /*�Լ��� �����ε� : ���� �̸��� �Լ�����, ���ڰ� �ٸ��ų� ����� �ٸ� �Լ�
  �����ε��� ���� : ������ �Լ��� �̸��� ���ƾ���., ������ ���� �Ǵ� Ÿ���� �޶� �����ε��� ����., ��ȯ���� ����x
*/

	*pNumber = 25;
}


//�Լ��� ����Ʈ���� : ���ڴ� �⺻������ ���� �Ѱܹ���, �׷��� ���ڿ� ���� �Ѱ����� ���� ���, �����صξ��� �⺻���� 
//���ڷ� ����.

void Output(int inum1, int inum2 = 10) { //inum2�� �⺻���� �����Ǿ� ����

	cout << inum1 << inum2 << endl;
	
}




int main(void) {

	cout << Sum(10, 20) << endl;  //��� : 30
	OutputText();  //()���� ��� �Լ��� ȣ��ȴ�. 
	int num = 10;   //�������� num -> �޸𸮿�����, stack������ �Ҵ��.
	
	cout << num << endl;  //��������
	
	cout << g_num << endl;  //��������
	ChangeNum(num);
	ChangeNumber(&num);  //�������� num�� �̿��Ͽ�����, �����͸� ���ڷ� ����ϴ� �Լ��� ����Ͽ� ���� �ٲ�� ��
	                     // �Լ��� �����ε�(���ڰ� �ٸ��Ƿ�)
	cout << num << endl;  //��� 25


	cout << "==============" << endl;
	Output(10, 40);  //10�� 40�� ���
	Output(10); //10�� 10(�⺻��)�� ��� 
	

	system("pause");
	return 0;
}