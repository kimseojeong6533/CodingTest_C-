#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;  //시험장의 개수
int B, C;  // B : 총감독이 한방에서 감시할 수 있는 명수, C : 부감독이 한방에서 감시할 수 있는 명수
 
vector <int> A;

int main(void)
{
	  //각 시험장에 있는 응시자수,
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int stu;
		cin >> stu;	
		A.push_back(stu);
	}
	cin >> B >> C;
	
	long long cnt = 0;  //int의 범위가 -128 ~ 127이므로 cnt가 최악의 경우(학생수는 999999명, 총감독 1명감독가능, 부감독 1명감독가능일 경우, 부감독은 999999명이 필요함) overflow가 발생하므로 long형으로 count해줌.
	//참고로 long long형의 printf시의 서식문자는 %lld, long형의 printf시의 서식문자는 %ld임.
	for (int i = 0; i < N; i++)
	{

		A[i] = A[i] - B;  //총감독이 감독하는 응시생수를 제외
		cnt++;
		if (A[i] > 0)  //방에 응시자가 없는 경우에는 부감독이 필요가 없음 (count할 필요 없음)
		{
			if (A[i] % C == 0)  //나누어 떨어질 경우
			{
				cnt += (A[i] / C);
			}
			else  //나누어떨어지지 않을 경우
			{
				cnt += (A[i] / C + 1);
			}
		}
		
	}

	cout << cnt << endl;

	system("pause");
	return 0;
}
