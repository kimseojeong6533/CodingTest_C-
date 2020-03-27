#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <deque>
#define MAX_SIZE 52
using namespace std;

int N, L, R;  //N : 1~50, L,R : 1~100
int A[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

vector <pair <int, int> > country[MAX_SIZE][MAX_SIZE]; //���ձ��� ������ġ �ֺ��� ������ �����Ǵ� ĭ�� ��ġ�� ���� ����
vector <pair <int, int> > s_country;//���ձ��� ������ġ�� ���� ����
//deque <pair <int, int> > country[MAX_SIZE][MAX_SIZE];  

int a, b;

void Moving()
{
	
	for (int i = 0; i < s_country.size(); i++)
	{
		int x = s_country[i].first;
		int y = s_country[i].second;
		
		int cnt = country[x][y].size()+1;  //1�� �ڱ��ڽ�
		int people = A[x][y];

		for (int j = 0; j < country[x][y].size(); j++)
		{
			people += A[country[x][y][j].first][country[x][y][j].second];
		}
		
		int val = (int)(floor(people / cnt));
		A[x][y] = val;
		for (int j = 0; j < country[x][y].size(); j++)
		{
			A[country[x][y][j].first][country[x][y][j].second] = val;
		}

		country[x][y].clear();
	}
	

	printf("=============================\n");

	
	


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

	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
		{
			if (abs(A[nx][ny] - A[x][y]) >= L && abs(A[nx][ny] - A[x][y]) <= R && visit[nx][ny] < 1)
			{
				
				country[a][b].push_back({ nx,ny });  
				visit[nx][ny] = 1;
				Unity(nx, ny);
			}
		}
	}


	//������� �Դٴ� ���� �ֺ��� L�̻� R���Ϸ� �α��� ���̳��� ������ ��濡 ���� �����.
	if (country[a][b].size() ==0)
		return;

}

int main(void)
{
	bool flag = true;
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &A[i][j]);
		}
	}

	int time = 0;

	while (1)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i][j] == 0)
				{
					a = i;
					b = j;
					s_country.push_back({ a,b });
					visit[i][j] = 1;
					Unity(i, j);  //���ձ��� ����
				}
			}
		}
		
		Moving();

		for (int i = 0; i < s_country.size(); i++)
		{
			int x = s_country[i].first;
			int y = s_country[i].second;
			if (country[x][y].size() == 0 && (i==(s_country.size()-1)))  //���̻� ���ձ��� ���� ��,
			{
				flag = false;
				break;
			}
		}

		if (flag == false)
		{
			cout << time << endl;
			return 0;
		}
		time++;
		//visit,country,s_country�ʱ�ȭ
		memset(visit, 0, sizeof(visit));
		country[a][b].clear();
		s_country.clear();
	}
	
}