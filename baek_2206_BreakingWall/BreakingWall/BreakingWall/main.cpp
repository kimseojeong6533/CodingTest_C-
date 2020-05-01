#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX_SIZE 1002

using namespace std;

int N, M;
int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };

int dx[] = { -1,0,1,0 };  //��-��-�Ʒ�-��
int dy[] = { 0,1,0,-1 };
int mind = 1000005;
bool flag = false;

void dfs(int x, int y,int cnt,int dist)
{
	if (x == N && y == M)
	{
		mind = min(mind, dist);
		//memset(visit, 0, sizeof(visit));  //visit �ʱ�ȭ
		flag = true;
		return;
	}
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
		{
			
			if (map[nx][ny] == 1 && cnt == 0)  //�ѹ��� ���� �ν��� ���� ���, ���� ������ ��
			{/*
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						printf("%d ", visit[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				*/

				if(visit[nx][ny]<visit[x][y]+1)
					visit[nx][ny]=visit[]
				dfs(nx, ny, cnt + 1,dist+1);
			}
			/*else if (map[nx][ny] == 1 && cnt != 0)  //�ѹ� ���� �ν� ���, ���� ��������
			{
				visit[nx][ny] = visit[x][y] + 1;
			}*/

			else if (map[nx][ny] == 0)  //���� �ƴ� ���
			{
				/*
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						printf("%d ", visit[i][j]);
					}
					printf("\n");
				}
				printf("\n");*/
				dfs(nx, ny, cnt,dist+1);
			}
			
		}
	}
}

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	printf("�Է� : \n");
	scanf_s("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	printf("\n");
	visit[1][1] = 1;
	dfs(1, 1, 0, 1);
	if (flag)
		cout << "�ִܰŸ� : " << mind - 1 << endl;
	else
		cout << "-1" << endl;

	return 0;
}