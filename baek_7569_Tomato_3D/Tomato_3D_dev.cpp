#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 102
using namespace std;

int M, N, K;  //세로, 가로, 높이
int map[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE][MAX_SIZE] = { 0, };
vector <int> v;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int dz[] = { 1,-1 };  

queue <pair <pair <int, int>, int> > q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)  //앞, 뒤, 왼, 오른
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				if (map[nx][ny][z] == 0)
				{
					map[nx][ny][z] = 1;
					visit[nx][ny][z] = visit[x][y][z] + 1;  //visit의 최대값-1이 토마토가 모두익는 최소일. 
					q.push({ {nx,ny},z });
				}
			}
		}

		for (int d = 0; d < 2; d++)  //위, 아래
		{
			int	nz = z + dz[d];
			if (nz >= 1 && nz <= K)
			{
				if (map[x][y][nz] == 0)
				{
					map[x][y][nz] = 1;
					visit[x][y][nz] = visit[x][y][z] + 1;
					q.push({ {x,y},nz });
				}
			}
		}

		
		for (int z = 1; z <= K; z++)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					printf("%d", visit[i][j][z]);
				}
				printf("\n");
			}
			//printf("\n");
		}
		
		printf("\n");
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;

	cin >> M >> N >> K;

	for (int z = 1; z <= K; z++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				scanf_s("%d", &map[i][j][z]);  //1 : 익은 토마토, 0 : 익지않은 토마토, -1 : 토마토 없음

				if (map[i][j][z] == 1)
				{
					visit[i][j][z] = 1;
					q.push({ {i,j},z });
				}
				if (map[i][j][z] == -1)
				{
					cnt++;
				}
			}
		}
	}

	int size = q.size();
	if ((cnt + size) == (N * M * K)) //저장될 떄부터 모든 토마토가 익어 있는 상태
	{
		printf("0");
		return 0;
	}

	bfs();
	
	for (int z = 1; z <= K; z++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j][z] == 0)  //토마토가 모두 익지는 못하는 상황 
				{
					printf("-1");
					return 0;
				}
			}
		}
	}

	int maxval = -1;
	for (int z = 1; z <= K; z++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				maxval = max(visit[i][j][z], maxval);
			}
		}
	}
	
	printf("%d", maxval - 1);
	return 0;
}
