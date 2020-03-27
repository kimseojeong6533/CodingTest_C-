#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define MAX_SIZE 52
using namespace std;

int N, L, R;  //N : 1~50, L,R : 1~100
int A[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

vector <pair <int, int> > country;  //���ձ��� ��ġ�� ���� ����


void Moving()
{
	int cnt = country.size();
	int people=0;
	
	for (int i = 0; i < country.size(); i++)
	{
		people += A[country[i].first][country[i].second];
	}

	printf("=============================\n");

	int val = (int)(floor(people / cnt));
	printf("val : %d\n", val);
	for (int i = 0; i < country.size(); i++)
	{
		A[country[i].first][country[i].second] = val;
	}

	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	//people, visit,country �ʱ�ȭ �ʿ�
	memset(visit, 0, sizeof(visit));

	return;
}

void Unity(int x, int y)  //���ձ��� ĭ�� ��ġ�� country�� ����.  using DFS
{
	bool flag = true;

	//queue <pair <int, int> > q;

	
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
			

		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
		{
			if (abs(A[nx][ny] - A[x][y]) >= L && abs(A[nx][ny] - A[x][y]) <= R && visit[nx][ny] < 1)
			{
				country.push_back({ nx,ny });  //country �ߺ����� �ʿ�
				visit[nx][ny] = 1;
				Unity(nx,ny);
			}
		}
	}
	


	//������� �Դٴ� ���� �ֺ��� L�̻� R���Ϸ� �α��� ���̳��� ������ ��濡 ���� �����.
	if (country.size() <= 1)
		return;
	
}

int main(void)
{
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &A[i][j]);
		}
	}

	int time = -1;

	while (1)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i][j] == 0)
				{
					
					country.clear();
					country.push_back({ i,j });
					visit[i][j] = 1;
					Unity(i, j);  //���ձ��� ����
					
					/*if (country.size() > 1)  //���ձ����� �α��� �̵���Ŵ.
					{
						Moving();
					}*/
				}
				
			}
		}

		if (country.size() > 1)  //���ձ����� �α��� �̵���Ŵ.
		{
			Moving();
		}

		if (country.size() == 1)  //���̻� ���ձ��� ���� ��,
		{
			cout << time << endl;
			return 0;
		}
		
		//visit,country�ʱ�ȭ
		memset(visit, 0, sizeof(visit));
		country.clear();
		time++;
	}
	
}