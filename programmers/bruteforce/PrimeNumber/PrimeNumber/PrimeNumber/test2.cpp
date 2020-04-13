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

//nPr(����) �ߺ�0 -> set�����̳ʸ� �̿��ؼ� set�� ��´�
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

//�Ҽ��Ǻ�
void CheckPrime()
{

}


int main(void) {
	//���ڷε� ���ڿ��� �Է¹ް� �� ���ڸ� int���迭�� �ű�� �۾�
	string str1;
	getline(cin,str1);
	int len = str1.length();

	
	for (int i=0;i<len;i++)
	{
		int temp = str1[i]-'0';
		arr_str[i] = temp;
	}
	//���ڷε� ���ڿ��� �Է¹ް� �� ���ڸ� int���迭�� �ű�� �۾�



	int N = sizeof(arr_str) / sizeof(int);
	for (int i = 1; i <= N; i++)
	{
		Permutation(N, i);
	}
	
	system("pause");
	return 0;
}