#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX_SIZE 102

using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int field[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];

int N;
int maxval = -1;
int result = 0;  //resmax�� �񱳰�
int resmax = -1; //���� ����� �ʴ� ������ ������ �ִ밳���� �����.

//dfs�� Ǯ���

void SecureField(int &i, int &j, int &val)
{

	for (int d = 0; d < 4; d++)
	{
		int nx = i + dx[d];
		int ny = j + dy[d];

		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
		{
			if (field[nx][ny] > val && visit[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				SecureField(nx, ny, val);
			}
		}
	}

}

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &field[i][j]);
			maxval = max(maxval, field[i][j]);  //�������� ����ū���� maxval�� �� 
		}
	}

	int val = 0;

	while (val <= maxval)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (field[i][j] > val && visit[i][j] == 0)
				{
					result++;
					visit[i][j] = 1;
					SecureField(i, j, val);
				}

			}
		}

		resmax = max(resmax, result);

		result = 0;
		memset(visit, 0, sizeof(visit));  //visit�� result�� �ʱ�ȭ
		val++;
	}


	cout << resmax << endl;

	return 0;
}