#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#define MAX_VALUE 100
using namespace std;


int arr_str[MAX_VALUE] = {};

int swap(int i, int j)
{
	int temp;
	if (i == j) return 0;
	temp = arr_str[i];
	arr_str[i] = arr_str[j];
	arr_str[j] = temp;
	return 0;
}

//nPr(순열) 중복0 -> set컨테이너를 이용해서 set에 담는다
int Permutation(int TotalN, int N)
{
	int i;

	if (N == 1) {
		for (i = 0; i < TotalN; i++) {
			printf("%d ", arr_str[i]);
		}
		printf("\n");
		return 0;
	}

	for (i = 0; i < N; i++) {
		swap(i, N - 1);
		Permutation(TotalN, N - 1);
		swap(i, N - 1);
	}
}

//소수판별
void CheckPrime()
{

}


int main(void) {
	//숫자로된 문자열을 입력받고 각 숫자를 int형배열로 옮기는 작업
	string str1;
	getline(cin,str1);
	int len = str1.length();

	
	for (int i=0;i<len;i++)
	{
		int temp = str1[i]-'0';
		arr_str[i] = temp;
	}
	//숫자로된 문자열을 입력받고 각 숫자를 int형배열로 옮기는 작업



	int N = sizeof(arr_str) / sizeof(int);
	for (int i = 1; i <= N; i++)
	{
		Permutation(N, i);
	}
	
	system("pause");
	return 0;
}