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

	
	//scanf_s(" %[^.]s",s,sizeof(s));  // " %[^.]"  : ���� �����ϰ� .�� ���ö� ���� �Է¹���( s�� ���������� .�� �� ������ �κ��� �Էµ�)
	
	string s;
	while (1)
	{
		getline(cin, s);
		if (s[0] == '.' && s.size()==1)
			return 0;
		
		sol(s);
	}
	
	
}