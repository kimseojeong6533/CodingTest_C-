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

vector <pair <int, int> > country;  //연합국의 위치가 담기는 벡터


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

	//people, visit,country 초기화 필요
	memset(visit, 0, sizeof(visit));

	return;
}

void Unity(int x, int y)  //연합국인 칸의 위치를 country에 담음.  using DFS
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
				country.push_back({ nx,ny });  //country 중복제거 필요
				visit[nx][ny] = 1;
				Unity(nx,ny);
			}
		}
	}
	


	//여기까지 왔다는 것은 주변에 L이상 R이하로 인구가 차이나는 국가가 사방에 없는 경우임.
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
					Unity(i, j);  //연합국을 만듦
					
					/*if (country.size() > 1)  //연합국끼리 인구를 이동시킴.
					{
						Moving();
					}*/
				}
				
			}
		}

		if (country.size() > 1)  //연합국끼리 인구를 이동시킴.
		{
			Moving();
		}

		if (country.size() == 1)  //더이상 연합국이 없을 때,
		{
			cout << time << endl;
			return 0;
		}
		
		//visit,country초기화
		memset(visit, 0, sizeof(visit));
		country.clear();
		time++;
	}
	
}