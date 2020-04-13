#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int solution(string s)
{
	
	int answer=1;
	int len=s.length();
	
	for(int i=0;i<len-1;i++)
	{
		int p=i;
		int p2=p+1;
		int ans_max=1;  //palindrome의 중심숫자  
		while(s[p]==s[p2])
		{
			p2++;
			ans_max++;
		}
		
		
			
		int left=p-1;
		int right=p2;
		
		if(left<0 || right > len)
		{
			if(ans_max>answer)
				answer=ans_max;
			continue;
		}	
		
		while(s[left]==s[right])
		{
			ans_max+=2;
			left--;
			right++;
			
			if(left<0 || right > len)
				break;
		}
		
		if(ans_max>answer)
		{
			answer=ans_max;	
		}	
		
	}
	
	return answer;
}

int main(void)
{
	
	string s="aabcd";
	cout<<s<<endl;
	
	int result=solution(s);
	cout<<result<<endl;
	
	return 0;
}

