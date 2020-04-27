#include <iostream>
#include <deque>
using namespace std;

int N;

int Card(int n)
{
	deque <int> d;
	
	//스택에 카드의 수만큼 쌓는다 
	for(int i=1;i<=n;i++)
	{
		d.push_back(i);
	}
	
	while(d.size()>1)
	{
		d.pop_front();
		
		int f=d.front();
		//printf("%d, ",f);
		if(d.size()==1)
			return f;
		
		d.pop_front();
		d.push_back(f);
	} 
	return d.front();
}

int main(void)
{
	cin>>N;
	int result=Card(N);
	cout<<result<<endl;
	return 0;
}
