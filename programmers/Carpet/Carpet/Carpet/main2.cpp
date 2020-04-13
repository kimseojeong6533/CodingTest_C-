#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


vector<int> solution(int brown, int red) {
	vector<int> answer;

	int sum = brown + red;

	int cul = (int)sqrt(sum);

	for (int i = 3; i <= cul ; i++)
	{
		if (sum%i == 0)
		{
			int j = sum / i;
			if ((i - 2)*(j - 2) == red)
			{
				if (i >= j)
				{
					answer.push_back(i);
					answer.push_back(j);
					return answer;
				}
				else
				{
					answer.push_back(j);
					answer.push_back(i);
					return answer;
				}

			}
		}
	}


}

int main(void) {

	int brown = 24;
	int red = 24;
	vector<int> v;
	v = solution(brown, red);

	for (auto i : v)
	{
		cout << i << " ";
	}

	system("pause");
	return 0;
}
