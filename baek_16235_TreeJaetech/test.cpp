#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 12
using namespace std;

int N, M, K;

int A[MAX_SIZE][MAX_SIZE];  //�Է¹��� ��� �迭
vector <int> map[MAX_SIZE][MAX_SIZE];  //���� �迭
int food[MAX_SIZE][MAX_SIZE]; //5�� ����ִ� �߰� ��й迭

int dx[] = { -1,-1,-1,0,0,1,1,1 }; //8��
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int result = 0;

void SpringAndSummer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j].size() == 0)
				continue;
			
			vector <int> temp;
			int dead_tree = 0;
			sort(map[i][j].begin(),map[i][j].end()); //���̰� � �������� ����� �Ա⶧���� ��������(�⺻��)���� ����

			for (int k = 0; k < map[i][j].size(); k++)
			{
				int age = map[i][j][k];
				if (A[i][j] - age >= 0)  //������ ���̸�ŭ ����� ���� �� �ִ� ���,
				{
					A[i][j] = A[i][j] - age;  //������ ���̸�ŭ ����� �پ���, ���̰� 1��� ������.
					age++;
					temp.push_back(age);
				}
				else if (A[i][j] - age < 0)
				{
					dead_tree += (int)(age/2);  //������ ������ ���ݸ�ŭ dead_tree�� ������.(�ش� ������ ����)
				}

			}
			map[i][j].clear();
			A[i][j] = A[i][j] + dead_tree;  //���� ������ ������ ���ݸ�ŭ ���� ���� dead_tree�� ��иʿ� �߰���.

			for (int k = 0; k < temp.size(); k++)
			{
				map[i][j].push_back(temp[k]);
			}
		}
	}
	return;
}



void Autumn()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j].size() == 0)
				continue;

			for (int k = 0; k < map[i][j].size(); k++)
			{
				int age = map[i][j][k];
				if (age % 5 == 0)  //
				{
					for (int d = 0; d < 8; d++)
					{
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
						{
							map[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
	return;
}

void Winter()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			A[i][j] = A[i][j] + food[i][j];
		}
	}

	return;
}


void Start()
{
	SpringAndSummer();

	Autumn();

	Winter();

	return;

}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &A[i][j]);
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int val,x,y;
		scanf("%d %d %d", &x,&y,&val);
		map[x][y].push_back(val);
	}

	for (int yr = 1; yr <= K; yr++)
	{
		Start();
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			result+=map[i][j].size();
		}
	}

	cout << result << endl;
	
	return 0;
}

