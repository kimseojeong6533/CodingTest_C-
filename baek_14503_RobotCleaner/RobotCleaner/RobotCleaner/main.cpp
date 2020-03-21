#include <iostream>
#include <vector>
#define MAX_SIZE 51
using namespace std;

int N;  //����  (3�̻� 50����)
int M;  //����  

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };  //û�Ұ� �ȵǾ� ������ 0, û�Ұ� �Ǿ� ������ 1

int d;  //���� �ε��� (0 : ��, 1 : ��, 2 ; ��, 3 : ��)
int robot_r;  //�κ��� ���� ��ġ (x)
int robot_c;  //�κ��� ���� ��ġ (y)

int cleaning = 0;  //�κ�û�ұⰡ û���ϴ� ĭ�� ����
int cnt = 0;

void bfs(int x, int y,int d)
{
	cnt++;
	if (visit[x][y] == 0 && map[x][y]==0) //û������ ����, ���� �ƴ� ĭ�� û���Ѵ�
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

	for(int k=0;k<4;k++)  //4���� Ž������
	{

		dir = dir - 1;  //���� ������ ���ʺ��� Ž������
		if (dir < 0)
			dir = 3;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (k<=3 && map[nx][ny] == 0 && visit[nx][ny] == 0)  //û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� 1ĭ ���� 
			{
				bfs(nx, ny, dir);
				break;
			}

			if ((k == 3) && (map[nx][ny] == 1 || visit[nx][ny] == 1))  //4���� Ž���ߴµ�, ���� ����� �����鼭 �������� ���� ĭ�� ���̰ų�(map=1), û���� ���
			{

				int xx = x - dx[dir];  //���� ���⿡�� ������ ��ġ
				int yy = y - dy[dir];

				if (xx >= 0 && xx < N && yy >= 0 && yy < M)
				{
					if (map[xx][yy] == 1)  //�����ߴµ� ���� ��� �۵��� ����.
						return;
					else  //�����ߴµ� ���� �ƴϸ�, ���
					{
						bfs(xx, yy, dir);
						break;
					}

				}
				else  //�����ߴµ� ������(��)�̸� �۵��� ����.
					return;

			}
			else
				continue;
		}
		else
			continue;
		
	}
	
	      //���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
	  //���ʹ����� ���̶� ������ ���� ���� ���, �۵��� ����
	
}

int main(void)
{
	cin >> N >> M;
	scanf_s("%d %d %d", &robot_r, &robot_c, &d);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &map[i][j]);    //0 : ��ĭ(û�Ұ���), 1 : �� 
		}
	}

	bfs(robot_r, robot_c,d);
	int ret = cleaning;
	cout << ret << endl;

	return 0;
}