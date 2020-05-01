#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void sol(string &v)
{
	stack <char> cha;
	bool flag = true;

	if (v == "")
		return;

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
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	//scanf_s(" %[^.]s",s,sizeof(s));  // " %[^.]"  : 띄어쓰기 포함하고 .이 나올때 까지 입력받음( s는 최종적으로 .을 뺀 나머지 부분이 입력됨)
	
	while (1)
	{
		getline(cin, s);

		if (s == ".")
			return 0;
		
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.')
			{
				string sub;
				string sub2;
				for (int j = 0; j <= i; j++)
				{
					sub += s[j];
				}
				sol(sub);
				for (int j = i + 1; j < s.size(); j++)
				{
					sub2 += s[j];
				}
				sol(sub2);
			}
		}
		
		
	}

	
	/*string sub;
	vector <string> v;

	for (int i = 0; i < s.size(); i++)
	{
		
		if (s[i] != '.')
		{
			sub += s[i];
		}
		else  //마침표가 찍히면, sub를 벡터에 넣고 sub를 초기화
		{
			v.push_back(sub);
			sub.clear();
		}
	}
	*/
	
	
}
