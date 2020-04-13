#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b)
{
	return a > b;
}

int solution(vector<int> nums)
{
	int answer = 0;
	int maxval = 1;
	vector <int> idx;
	vector <int> sub;

	int n = nums.size();  //nums의 길이는 항상 짝수
	int r = n / 2;

	for (int i = 0; i < r; i++)
		idx.push_back(1);
	for (int i = 0; i < n - r; i++)
		idx.push_back(0);
	sort(idx.begin(), idx.end(), desc);

	do {
		for (int i = 0; i < n; i++)
		{
			if (idx[i] == 1)
				sub.push_back(nums[i]);
		}

		for (int i = 0; i < sub.size() - 1; i++)
		{
			if (sub[i] != sub[i + 1])
				maxval++;
		}

		answer = max(maxval, answer);
		maxval = 1;
		sub.clear();

	} while (next_permutation(idx.begin(), idx.end(), desc));
	return answer;
}
int main(void)
{
	
	return 0;
}