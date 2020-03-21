#include <iostream>
#include <vector>
#define MAX_SIZE 51
using namespace std;

int N;  //세로  (3이상 50이하)
int M;  //가로  

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };  //청소가 안되어 있으면 0, 청소가 되어 있으면 1

int d;  //방향 인덱스 (0 : 북, 1 : 동, 2 ; 남, 3 : 서)
int robot_r;  //로봇의 현재 위치 (x)
int robot_c;  //로봇의 현재 위치 (y)

int cleaning = 0;  //로봇청소기가 청소하는 칸의 개수
int cnt = 0;

void bfs(int x, int y,int d)
{
	cnt++;
	if (visit[x][y] == 0 && map[x][y]==0) //청소하지 않은, 벽이 아닌 칸만 청소한다
	{
		++cleaning;
		visit[x][y] = 1;
		
		for (int p = 0; p < N; p++)
		{
			for (int q = 0; q < M; q++)
			{
				printf("%d ", visit[p][q]);
			}
			printf("\n");
		}
		printf("%d\n", cnt);
	}
	printf("\n");


	int dir = d;

	for(int k=0;k<4;k++)  //4방향 탐색시작
	{

		dir = dir - 1;  //현재 방향의 왼쪽부터 탐색시작
		if (dir < 0)
			dir = 3;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (k<=3 && map[nx][ny] == 0 && visit[nx][ny] == 0)  //청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 1칸 전진 
			{
				bfs(nx, ny, dir);
				break;
			}

			if ((k == 3) && (map[nx][ny] == 1 || visit[nx][ny] == 1))  //4방을 탐색했는데, 원래 방향과 같으면서 원래방향 앞의 칸이 벽이거나(map=1), 청소한 경우
			{

				int xx = x - dx[dir];  //원래 방향에서 후진한 위치
				int yy = y - dy[dir];

				if (xx >= 0 && xx < N && yy >= 0 && yy < M)
				{
					if (map[xx][yy] == 1)  //후진했는데 벽인 경우 작동을 멈춤.
						return;
					else  //후진했는데 벽이 아니면, 재귀
					{
						bfs(xx, yy, dir);
						break;
					}

				}
				else  //후진했는데 범위밖(벽)이면 작동을 멈춤.
					return;

			}
			else
				continue;
		}
		else
			continue;
		
	}
	
	      //방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	  //뒷쪽방향이 벽이라 후진할 수도 없는 경우, 작동을 멈춤
	
}

int main(void)
{
	cin >> N >> M;
	scanf_s("%d %d %d", &robot_r, &robot_c, &d);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &map[i][j]);    //0 : 빈칸(청소가능), 1 : 벽 
		}
	}

	bfs(robot_r, robot_c,d);
	int ret = cleaning;
	cout << ret << endl;

	return 0;
}