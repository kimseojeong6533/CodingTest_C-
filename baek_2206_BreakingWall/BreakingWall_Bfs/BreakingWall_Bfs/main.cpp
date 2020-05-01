#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX_SIZE 1002

//최단거리는 bfs이용한 
using namespace std;

int N, M;
int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };

int dx[] = { -1,0,1,0 };  //위-우-아래-왼
int dy[] = { 0,1,0,-1 };


queue <pair <pair <int, int>, int > > q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{

				if (map[nx][ny] == 1 && cnt == 0 && visit[nx][ny] == 0)  //한번도 벽을 부시지 않은 경우, 벽을 만낫을 때
				{
					
					visit[nx][ny] = visit[x][y] + 1;
					q.push({ {nx,ny},cnt + 1 });
					
				}
				else if (map[nx][ny] == 1 && cnt == 1 && visit[nx][ny] == 0)
				{
					visit[x][y] = 0;
					continue;
				}

				else if (map[nx][ny] == 0 && visit[nx][ny] == 0)  //벽이 아닌 경우
				{
					visit[nx][ny] = visit[x][y] + 1;
					q.push({ {nx,ny},cnt });

				}

			}
		}
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

}

int main(void)
{

	//printf("입력 : \n");
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	//printf("\n");

	visit[1][1] = 1;
	q.push({ {1,1},0 });
	bfs();

	if (visit[N][M]>0)
		cout << visit[N][M] << endl;
	else
		cout << "-1" << endl;

	return 0;
}