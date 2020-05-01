//백준 11866_요세푸스 순열 
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N;
	int K;
	queue <int> q;
	vector <int> v;
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		q.push(i);
	}
	
	while(!q.empty())
	{
		int cnt=1;
		while(1)
		{
			if(cnt==K)
			{
				v.push_back(q.front());
				q.pop();
				break;
			}
			else
			{
				int x=q.front();
				q.pop();
				q.push(x);
				cnt++;	
			}
		}	
	}
	
	printf("<");
	for(int i=0;i<v.size();i++)
	{
		if(i==v.size()-1)
		{
			printf("%d>\n",v[i]);
		}
		else
		{
			printf("%d, ",v[i]);	
		}
		
	}
	
	return 0;
}
 
