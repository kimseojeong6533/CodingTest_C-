#include <iostream>
#include <queue>
#define MAX_SIZE 102

using namespace std;

int N, M;
int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };

int dx[] = { -1,0,1,0 }; //상-동-하-서 (시계방향)
int dy[] = { 0,1,0,-1 };


void bfs() //지나야하는 최소칸의 수 를 반환
{
	visit[1][1] = 1;

	queue <pair <int, int> > q;
	q.push({ 1,1 });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				if (map[nx][ny] == 1 && visit[nx][ny]==0)
				{
					
					q.push({ nx,ny });
					visit[nx][ny]=visit[x][y]+1;
					
				}
			}
			
		}

	}

}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();

	cout << visit[N][M] << endl;

	return 0;
}
