#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Que(int n, int cnt)
{
	queue <pair <int,int> > q;
	q.push({n,cnt});
	
	while(!q.empty())
	{
		int x=q.front().first;
		int c=q.front().second;
		q.pop();
		//printf("x : %d, c : %d\n",x,c);
		
		if(x==1)
		{
			return c;
		}
		
		if(x%3==0)
		{
				
			//printf("x : %d, c : %d\n",x,c);
			q.push({x/3,c+1});
		}
		if(x%2==0)
		{
			//printf("x : %d, c : %d\n",x,c);
			q.push({x/2,c+1});
		}
		q.push({x-1,c+1});		
	}
}

int main(void)
{
	int N;
	int cnt=0;
	cin>>N;
	
	int result=Que(N,cnt);
	cout<<result<<endl;
		
	return 0;
}
