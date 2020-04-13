#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int c[8];
vector <int> a[8];



void bfs(int start)
{
	
	queue <int> q;
	q.push(start);
	c[start]=true;
	
	while(!q.empty())
	{
		int x=q.front(); //q에서 노드를 하나 꺼내고, 출력 
		q.pop();
		printf("%d ",x);
		for(int i=0;i<a[x].size();i++)  //꺼낸 노드의 자식노드를 살핌 
		{
			int y=a[x][i];
			if(!c[y])  //방문처리되지 않은 자식노드를 큐에 추가하고 방문처리함. 
			{
				q.push(y);
				c[y]=true;	
			}	
		}	
	}	
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	
	return 0 ;
}
