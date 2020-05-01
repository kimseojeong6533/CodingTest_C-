#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

vector <int> v;
stack <int> s;

int main(void)
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf_s("%d", &num);
		v.push_back(num);
	}

	queue <int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	
	vector <char> ans;

	

	for (int i = 0; i < n; i++)
	{
		if (s.empty())
		{
			s.push(q.front());
			ans.push_back('+');
			q.pop();
		}

		while (!s.empty())
		{
			if (s.top() == v[i])
			{
				s.pop();
				ans.push_back('-');
				break;
			}
			else
			{
				if (q.empty() && i<n)
				{
					printf("NO\n");
					return 0;
				}
				int x = q.front();
				s.push(x);
				ans.push_back('+');
				q.pop();
			}
		}
		
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%c\n", ans[i]);
	}
	
	return 0;
}