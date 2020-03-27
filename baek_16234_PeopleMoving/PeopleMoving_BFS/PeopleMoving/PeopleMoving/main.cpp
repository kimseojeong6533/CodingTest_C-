#include <iostream>
#include <deque>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE 52
using namespace std;

int N, L, R;  //N : 1~50, L,R : 1~100
int A[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };
int dx[] = { 0,1,0,-1 }; //��-��-��-��
int dy[] = { 1,0,-1,0 };

deque <pair <int, int> > v;
deque <pair <int, int> > cnty[MAX_SIZE][MAX_SIZE];  //���յǴ� �������� ��ġ�� ���� ����

void Moving(int a, int b)
{
	int cnt = cnty[a][b].size() + 1; //+1�� �ڱ��ڽ��� ����
	int people = A[a][b];

	for (int i = 0; i < cnty[a][b].size(); i++)
	{
		people += A[cnty[a][b][i].first][cnty[a][b][i].second];
	}

	//printf("=============================\n");

	int val = (int)(floor(people / cnt));
	A[a][b] = val;  //�ڱ��ڽſ� ���� ����
	//printf("val : %d\n", val);

	for (int i = 0; i < cnty[a][b].size(); i++)
	{
		A[cnty[a][b][i].first][cnty[a][b][i].second] = val;  //�ڱ��ڽ��� �ƴ� �ڽĵ鿡�� ���� ����
	}


	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}*/

	//people, visit,country �ʱ�ȭ �ʿ�
	memset(visit, 0, sizeof(visit));
	cnty[a][b].clear();
	return;
}

void Unity(queue <pair <int,int> > country, int i, int j)
{
	while (!country.empty())
	{
		int x = country.front().first;
		int y = country.front().second;
		country.pop();

		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
			{
				if (abs(A[nx][ny] - A[x][y]) >= L && abs(A[nx][ny] - A[x][y]) <= R && visit[nx][ny] == 0)
				{
					country.push({ nx,ny });
					cnty[i][j].push_back({ nx, ny });
					visit[nx][ny] = 1;  
				}
			}
		}
	}

	return;
}


int main(void)
{
	cin.tie(NULL);

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
		queue <pair <int, int> > country;  //���ձ��� ��ġ�� ���� ť(���ս� ���)	

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i][j] == 0)
				{
					country.push({ i,j });  //bfs�� ���� ť
					v.push_back({ i,j });   //������ �������� ���� ù��° ĭ�� ��ġ�� ��.
					visit[i][j] = 1;        
					Unity(country,i,j);  //Bfs(L�̻� R���Ϸ� ���̳��� �������� ����)		
				}
			}
		}

		if (v.size() == N * N)  //���̻� ���ձ��� ���� �� (�α��̵��� �� ���� ��), while���� ������ time�� ���
			break;
		

		for (int i = 0; i < v.size(); i++)
		{
			if (cnty[v[i].first][v[i].second].size() >= 1)
				Moving(v[i].first,v[i].second);
		}

		
		//visit,country�ʱ�ȭ
		memset(visit, 0, sizeof(visit));
		time++;
		v.clear();
	}

	printf("%d\n", time);
	return 0;

}