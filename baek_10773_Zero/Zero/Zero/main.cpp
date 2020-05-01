#include <iostream>
#include <stack>
#include <vector>
using namespace std;

 
vector <int> v;

long long sol()
{
	stack <int> s;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 0)
		{
			s.pop();
		}
		else
		{
			s.push(v[i]);
		}
	}

	long long ans=0;
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	return ans;

}

int main(void)
{
	int K,N;
	cin >> K;

	  

	long long result;  //최종적으로 적어낸 수의 합은 2^32-1보다 작다 -> long : 4byte = 32bit -> -2^32 ~ 2^32-1 

	for (int i = 0; i < K; i++)
	{
		scanf_s("%d", &N);
		v.push_back(N);
	}
	result=sol();

	cout << result << endl;
	return 0;
}