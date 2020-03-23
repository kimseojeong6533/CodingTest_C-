#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 10
using namespace std;


int N, M;  //3~8
int map[MAX_SIZE][MAX_SIZE] = { 0, };
int v_map[MAX_SIZE][MAX_SIZE] = { 0, };  //벽을 세울때 쓰이는 변수
int dx[] = { -1,0,1,0 };  //북-동-남-서
int dy[] = { 0,1,0,-1 };

vector <pair <int, int> > blank;  //빈칸을 넣는 벡터
vector <int> idx;
vector <pair <int, int> > sub;
queue <pair <int, int> > vir;  //바이러스의 위치가 들어있는 큐
vector <pair <int, int> > vir2;  //바이러스의 위치가 들어있는 벡터
int Max_val = -9999;


void Beginning()  //v_map을 map
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			v_map[i][j] = map[i][j];
		}
	}
}


void SafetyZone()  //안전 영여의 최대크기 구하기
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



bool desc(int a, int b) //내림차순으로 정렬
{
	return a > b;
}


void Walling()  // 빈칸에 벽을 3개 세움. (결국, n개의 빈칸에서 3개를 뽑아야 돼 => 조합)
{
	int n = blank.size();

	//3개의 빈칸위치를 뽑아서 그 위치들을 sub벡터에 넣음. 
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
				sub.push_back(blank[i]);  //3개의 벽위치가 sub벡터에 들어감
			}
		}

		//sub에 들어간 위치를 v_map으로 옮김.
		for (int k = 0; k < sub.size(); k++)
		{
			v_map[sub[k].first][sub[k].second] = 1;
		}
		//바이러스 퍼짐(v_map이용)
		Virusing();
		
		//안전영역의 크기 구하기
		SafetyZone();

		//v_map -> map 초기화 (벽위치 초기화)
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
			scanf_s("%d", &map[i][j]);   //0 : 빈칸, 1 : 벽, 2 : 바이러스
			v_map[i][j] = map[i][j];

			if (map[i][j] == 0)  //빈칸을 blank벡터에 넣음
				blank.push_back({ i,j });

			if (map[i][j] == 2)  //바이러스 칸을 vir벡터에 넣음
			{
				vir2.push_back({ i,j });
			}
		}
	}

	Walling();
	cout << Max_val << endl;

	return 0;
}