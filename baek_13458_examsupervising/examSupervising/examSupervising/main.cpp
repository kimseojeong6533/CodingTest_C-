#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;  //�������� ����
int B, C;  // B : �Ѱ����� �ѹ濡�� ������ �� �ִ� ���, C : �ΰ����� �ѹ濡�� ������ �� �ִ� ���
 
vector <int> A;

int main(void)
{
	  //�� �����忡 �ִ� �����ڼ�,
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int stu;
		cin >> stu;	
		A.push_back(stu);
	}
	cin >> B >> C;
	
	long long cnt = 0;  //int�� ������ -128 ~ 127�̹Ƿ� cnt�� �־��� ���(�л����� 999999��, �Ѱ��� 1��������, �ΰ��� 1���������� ���, �ΰ����� 999999���� �ʿ���) overflow�� �߻��ϹǷ� long������ count����.
	//����� long long���� printf���� ���Ĺ��ڴ� %lld, long���� printf���� ���Ĺ��ڴ� %ld��.
	for (int i = 0; i < N; i++)
	{

		A[i] = A[i] - B;  //�Ѱ����� �����ϴ� ���û����� ����
		cnt++;
		if (A[i] > 0)  //�濡 �����ڰ� ���� ��쿡�� �ΰ����� �ʿ䰡 ���� (count�� �ʿ� ����)
		{
			if (A[i] % C == 0)  //������ ������ ���
			{
				cnt += (A[i] / C);
			}
			else  //����������� ���� ���
			{
				cnt += (A[i] / C + 1);
			}
		}
		
	}

	cout << cnt << endl;

	system("pause");
	return 0;
}
