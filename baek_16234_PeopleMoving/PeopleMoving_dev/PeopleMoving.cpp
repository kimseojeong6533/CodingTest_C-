#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
#define MAX_SIZE 52
using namespace std;

int N, L, R;  //N : 1~50, L,R : 1~100
int A[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

vector <pair <int, int> > country;  //���ձ��� ��ġ�� ���� ����
bool flag = true;

void Moving()
{
	if (country.size() == 0)
	{
		flag = false;
		return;
	}

	int cnt = country.size();
	
	int people=0;
	
	for (int i = 0; i < country.size(); i++)
	{
		people += A[country[i].first][country[i].second];
	}
	

	int val = (int)(floor(people / cnt));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			A[i][j] = val;
		}
	}
	
	//people, visit,country �ʱ�ȭ �ʿ�
	country.clear();
	memset(visit, 0, sizeof(visit));
	people = 0;

	return;

}

void Unity(int x, int y)
{
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
		{
			if (abs(A[nx][ny] - A[x][y]) >= L && abs(A[nx][ny] - A[x][y]) <= R && visit[nx][ny] < 1)
			{
				country.push_back({ nx,ny });  //country �ߺ����� �ʿ�
				printf("%d %d\n", nx, ny);
				visit[nx][ny] += 1;
				Unity(nx, ny);
			}

			//������ �������� L�̸�, �Ǵ� R �ʰ� �� ���, 
			/*if (abs(A[nx][ny] - A[x][y]) < L || abs(A[nx][ny] - A[x][y]) > R)
			{
				visit[nx][ny] = 2;
			}*/
		}
	}
	//���ձ����� �α��� �̵���Ŵ.
	Moving();

	if (flag == false)
		return;
	else
		return;

}

int main(void)
{
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	int time = 0;
	while (1)
	{
		country.push_back({ 1,1 });
		visit[1][1] = 1;
		Unity(1, 1);
		//country�� ����� ���ٸ� break;
		if (flag == false)
			break;
		time++;	
	}
	
	cout << time << endl;

	return 0;
}
