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
int dx[] = { 0,1,0,-1 }; //우-하-좌-상
int dy[] = { 1,0,-1,0 };

deque <pair <int, int> > v;
deque <pair <int, int> > cnty[MAX_SIZE][MAX_SIZE];  //연합되는 국가들의 위치가 담기는 벡터

void Moving(int a, int b)
{
	int cnt = cnty[a][b].size() + 1; //+1은 자기자신을 포함
	int people = A[a][b];

	for (int i = 0; i < cnty[a][b].size(); i++)
	{
		people += A[cnty[a][b][i].first][cnty[a][b][i].second];
	}

	//printf("=============================\n");

	int val = (int)(floor(people / cnt));
	A[a][b] = val;  //자기자신에 값을 넣음
	//printf("val : %d\n", val);

	for (int i = 0; i < cnty[a][b].size(); i++)
	{
		A[cnty[a][b][i].first][cnty[a][b][i].second] = val;  //자기자신이 아닌 자식들에게 값을 넣음
	}


	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}*/

	//people, visit,country 초기화 필요
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
		queue <pair <int, int> > country;  //연합국의 위치가 담기는 큐(연합시 사용)	

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i][j] == 0)
				{
					country.push({ i,j });  //bfs에 들어가는 큐
					v.push_back({ i,j });   //연합할 국가들을 묶는 첫번째 칸의 위치가 들어감.
					visit[i][j] = 1;        
					Unity(country,i,j);  //Bfs(L이상 R이하로 차이나는 국가들을 묶음)		
				}
			}
		}

		if (v.size() == N * N)  //더이상 연합국이 없을 때 (인구이동할 수 없을 때), while문을 나가고 time을 출력
			break;
		

		for (int i = 0; i < v.size(); i++)
		{
			if (cnty[v[i].first][v[i].second].size() >= 1)
				Moving(v[i].first,v[i].second);
		}

		
		//visit,country초기화
		memset(visit, 0, sizeof(visit));
		time++;
		v.clear();
	}

	printf("%d\n", time);
	return 0;

}