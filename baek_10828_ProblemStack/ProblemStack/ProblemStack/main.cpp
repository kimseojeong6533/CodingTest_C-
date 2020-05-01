#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	stack <int> st;
	
	for (int i = 0; i <= N; i++)
	{
		string s;
		
		getline(cin, s);
		//printf("\n");
		if (s == "pop")
		{
			if (st.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", st.top());
				st.pop();
			}
		}
		else if (s == "size")
		{
			printf("%d\n", st.size());
		}
		else if (s == "empty")
		{
			if (st.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (s == "top")
		{
			if (st.empty())
				printf("-1\n");
			else
				printf("%d\n", st.top());
		}
		else  //push
		{
			int j = 0;
			while(j<s.size())
			{
				if (s[j] == ' ')
				{
					j++;
					string sub;
					while (j<s.size())
					{
						sub += s[j];
						j++;
					}
					int f = stoi(sub);
					st.push(f);
					break;
				}
				j++;
			}
		}
	}
	
	


	return 0;
}