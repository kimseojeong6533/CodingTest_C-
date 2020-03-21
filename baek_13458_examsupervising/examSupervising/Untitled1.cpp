#include <iostream>
#define MAX_SIZE 1000001
using namespace std;

int N;  //시험장의 개수
int B, C;  // B : 총감독이 한방에서 감시할 수 있는 명수, C : 부감독이 한방에서 감시할 수 있는 명수
int stu;  //각 시험장에 있는 응시자수, 
int A[MAX_SIZE];

int solution(int B,int C)  //각 시험장마다 응시생을 모두 감독하기위해 필요한 최소 감독관의 수
{
	int answer;

	int num1_sv = N;  //총 감독관의 수
	int num2_sv=0;  //부감독관의 수
	int hel;
	
	for (int i = 0; i < N; i++)
	{

		A[i] = A[i] - B;  //총감독이 감독하는 응시생수를 제외
		if (A[i] % C == 0)  //나누어 떨어질 경우
		{
			int hel = A[i] / C;
			num2_sv += hel;
		}
		else  //나누어떨어지지 않을 경우
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

