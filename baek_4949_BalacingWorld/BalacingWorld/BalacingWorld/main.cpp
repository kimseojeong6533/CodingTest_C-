#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void sol(string &v)
{
	stack <char> cha;
	bool flag = true;

	for (int j = 0; j < v.size(); j++)
	{
		if (v[j] == '(' || v[j] == '[')
		{
			cha.push(v[j]);
		}
		else if (v[j] == ')')
		{
				
			if (cha.empty() || cha.top() == '[')
			{
				flag = false;
				break;
			}
				
			else
			{
				cha.pop();
			}
				
		}
		else if (v[j] == ']')
		{
			if (cha.empty() || cha.top() == '(')
			{
				flag = false;
				break;
			}
			else
			{
				cha.pop();
			}
				
		}
	}
	
	if (!cha.empty())
		flag = false;
	
	
	if(flag)
		printf("yes\n");
	else
		printf("no\n");
	
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	//scanf_s(" %[^.]s",s,sizeof(s));  // " %[^.]"  : 띄어쓰기 포함하고 .이 나올때 까지 입력받음( s는 최종적으로 .을 뺀 나머지 부분이 입력됨)
	
	string s;
	while (1)
	{
		getline(cin, s);
		if (s[0] == '.' && s.size()==1)
			return 0;
		
		sol(s);
	}
	
	
}