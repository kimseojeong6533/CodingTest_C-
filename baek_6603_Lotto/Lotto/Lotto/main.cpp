#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b)  //내림차순 
{
	return a > b;
}


void Choosing(vector <int> &v)
{
	int k = v.size();
	vector <int> idx;
	vector <int> sub;
	
	for (int i = 0; i < 6; i++)
	{
		idx.push_back(1);
	}

	for (int i = 0; i < k - 6; i++)
	{
		idx.push_back(0);
	}

	sort(idx.begin(), idx.end(), desc);

	do {

		for (int i = 0; i < k; i++)
		{
			if (idx[i] == 1)
				sub.push_back(v[i]);
		}
		sort(sub.begin(), sub.end());  //오름차순으로 정렬후 출력 

		for (int i = 0; i < sub.size(); i++)
		{
			printf("%d ", sub[i]);
		}
		printf("\n");
		sub.clear();

	} while (next_permutation(idx.begin(), idx.end(), desc));

}

int main(void)
{

	vector <int> v;

	while (1)
	{
		int index = 0;
		int cnt = 0;
		int num;

		while (cnt <= index)  //숫자 k와 이후의 k개의 숫자들을 벡터에 집어넣는다. 
		{
			scanf_s("%d", &num);
			if (num == 0)
				return 0;
			if (cnt == 0)
				index = num;
			else
				v.push_back(num);
			cnt++;

		}

		Choosing(v);

		printf("\n");
		v.clear();

	}
}