#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 10
using namespace std;


int N, M;  //3~8
int map[MAX_SIZE][MAX_SIZE] = { 0, };
int v_map[MAX_SIZE][MAX_SIZE] = { 0, };  //���� ���ﶧ ���̴� ����
int dx[] = { -1,0,1,0 };  //��-��-��-��
int dy[] = { 0,1,0,-1 };

vector <pair <int, int> > blank;  //��ĭ�� �ִ� ����
vector <int> idx;
vector <pair <int, int> > sub;
queue <pair <int, int> > vir;  //���̷����� ��ġ�� ����ִ� ť
vector <pair <int, int> > vir2;  //���̷����� ��ġ�� ����ִ� ����
int Max_val = -9999;


void Beginning()  //v_map�� map
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			v_map[i][j] = map[i][j];
		}
	}
}


void SafetyZone()  //���� ������ �ִ�ũ�� ���ϱ�
{
	int safe = 0;
	//printf("=========================================\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (v_map[i][j] == 0)
			{
				safe++;
			}
			//printf("%d ", v_map[i][j]);
		}
		//printf("\n");
	}

	//printf("========================================\n");
	Max_val = max(safe, Max_val);

}


void Virusing()
{
	
	for (int p = 0; p < vir2.size(); p++)
	{
		vir.push({ vir2[p].first,vir2[p].second });
	}

	while (!vir.empty())
	{
		int x = vir.front().first;
		int y = vir.front().second;
		vir.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				if (v_map[nx][ny] == 0)  //
				{
					v_map[nx][ny] = 2;
					vir.push({ nx,ny });
				}
			}
		}
	}
}



bool desc(int a, int b) //������������ ����
{
	return a > b;
}


void Walling()  // ��ĭ�� ���� 3�� ����. (�ᱹ, n���� ��ĭ���� 3���� �̾ƾ� �� => ����)
{
	int n = blank.size();

	//3���� ��ĭ��ġ�� �̾Ƽ� �� ��ġ���� sub���Ϳ� ����. 
	for (int i = 0; i < 3; i++)
		idx.push_back(1);
	
	for (int i = 0; i < n - 3; i++)
		idx.push_back(0);

	sort(idx.begin(), idx.end(), desc);

	do {
		for (int i = 0; i < n; i++)
		{
			if (idx[i] == 1)
			{
				sub.push_back(blank[i]);  //3���� ����ġ�� sub���Ϳ� ��
			}
		}

		//sub�� �� ��ġ�� v_map���� �ű�.
		for (int k = 0; k < sub.size(); k++)
		{
			v_map[sub[k].first][sub[k].second] = 1;
		}
		//���̷��� ����(v_map�̿�)
		Virusing();
		
		//���������� ũ�� ���ϱ�
		SafetyZone();

		//v_map -> map �ʱ�ȭ (����ġ �ʱ�ȭ)
		Beginning();
		sub.clear();

	} while (next_permutation(idx.begin(), idx.end(), desc));

	return;
}


int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%d", &map[i][j]);   //0 : ��ĭ, 1 : ��, 2 : ���̷���
			v_map[i][j] = map[i][j];

			if (map[i][j] == 0)  //��ĭ�� blank���Ϳ� ����
				blank.push_back({ i,j });

			if (map[i][j] == 2)  //���̷��� ĭ�� vir���Ϳ� ����
			{
				vir2.push_back({ i,j });
			}
		}
	}

	Walling();
	cout << Max_val << endl;

	return 0;
}