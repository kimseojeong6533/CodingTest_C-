#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX_SIZE 200002
using namespace std;
//bfs로 풀어보자

int N, K;     // 0 <= N,K <= 100,000 
queue<pair <int,int> > q;

int visit[MAX_SIZE] = { 0, };

int Rapidtime(int x)
{
	int time = 0;
	q.push({x,time});
	
	while (!q.empty())
	{
		int size_q = q.size();
		for (int i = 0; i < size_q; i++)
		{
			int nx = q.front().first;
			int nt = q.front().second;
			q.pop();

			if (nx == K)
				return nt;

			if (nx < 0)
				continue;

			if (visit[nx] > 0)
				continue;

			if (nx > 100000)
				continue;

			visit[nx] = nt;

			q.push({ nx * 2, nt + 1 });
			q.push({ nx + 1, nt + 1 });
			q.push({ nx - 1, nt + 1 });
			
			
		}
	}
}

int main(void)
{
	cin >> N >> K;

	int result=Rapidtime(N);
	cout << result << endl;

	/*for (int i = 0; i < 2000; i++)
	{
		printf("%d ", visit[i]);
	}*/

	return 0;
}
