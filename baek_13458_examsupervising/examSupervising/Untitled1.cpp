#include <iostream>
#define MAX_SIZE 1000001
using namespace std;

int N;  //�������� ����
int B, C;  // B : �Ѱ����� �ѹ濡�� ������ �� �ִ� ���, C : �ΰ����� �ѹ濡�� ������ �� �ִ� ���
int stu;  //�� �����忡 �ִ� �����ڼ�, 
int A[MAX_SIZE];

int solution(int B,int C)  //�� �����帶�� ���û��� ��� �����ϱ����� �ʿ��� �ּ� �������� ��
{
	int answer;

	int num1_sv = N;  //�� �������� ��
	int num2_sv=0;  //�ΰ������� ��
	int hel;
	
	for (int i = 0; i < N; i++)
	{

		A[i] = A[i] - B;  //�Ѱ����� �����ϴ� ���û����� ����
		if (A[i] % C == 0)  //������ ������ ���
		{
			int hel = A[i] / C;
			num2_sv += hel;
		}
		else  //����������� ���� ���
		{
			int hel = A[i] / C + 1;
			num2_sv += hel;
		}
	}
	
	answer = num1_sv + num2_sv;
	return answer;
}



int main(void)
{

	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &stu);
		A[i] = stu;
	}
	cin >> B >> C;
	

	
	int ret=solution(B,C);

	cout << ret << endl;


	return 0;
}

