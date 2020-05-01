#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector <string> sc;

void sol()
{
	for (int j = 0; j < sc.size(); j++)
	{
		string s = sc[j];
		stack <char> p;
		bool flag = false;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				p.push(s[i]);
			}
			else
			{
				if (!p.empty())
				{
					p.pop();
				}
				else
				{
					flag = true;
					break;
				}

			}
		}

		if (p.empty())
		{
			if (flag)
				printf("NO\n");
			else
				printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}
	
		
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		string s;
		cin >> s;
		sc.push_back(s);
	}

	sol();

	return 0;
}