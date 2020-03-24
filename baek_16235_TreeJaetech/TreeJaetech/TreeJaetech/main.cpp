//시간초과
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <functional>
#define MAX_SIZE 12

using namespace std;

int map [MAX_SIZE][MAX_SIZE] = { 0, };  //입력되고, A에 추가되는 양분맵
int A[MAX_SIZE][MAX_SIZE];  //이용되는 양분맵 (초기에 5로 시작)

int N, M, K;  //N : 땅의 크기, M : 나무의 개수, K : 지나갈 년 수
int dx[] = { -1,-1,-1,0,0,1,1,1 };  //8개
int dy[] = { -1,0,1,-1,1,-1,0,1 };

typedef pair <pair <int, int>, int > Pair;

struct cmp  //나무의 나이별, 오름차순으로 정렬됨.
{
	bool operator()(Pair &p1, Pair &p2)
	{
		return p1.second > p2.second;
	}
};


priority_queue <Pair,vector<Pair>, cmp> tree;  //살아있는 나무를 담는 벡터(나무나이의 오름차순으로 정렬됨)
vector <Pair> food;  //죽은 나무를 담는 벡터
priority_queue <Pair, vector<Pair>, cmp> temp;


void Spring()
{
	while(!tree.empty())
	{
		int x = tree.top().first.first;
		int y = tree.top().first.second;
		int age = tree.top().second;
		tree.pop();

		if (A[x][y] - age >= 0) //자신의 나이만큼 양분을 먹을 수 있는 경우,
		{
			//양분이 해당 나무의 나이만큼 사라지고, 나이가 1 증가
			A[x][y] = A[x][y] - age;
			age++;
			temp.push({{ x,y }, age});  //임시큐에 나무의 정보를 넣는다.
		}
		else if (A[x][y] - age < 0) //자신의 나이만큼 양분을 먹을 수 없는 경우,
		{
			food.push_back(make_pair(make_pair(x, y), age));  //해당 나무의 위치와 나이를 죽은나무가 담길 food벡터에 옮김.
		}
		//printf("%d %d, %d\n", x, y, age);
		//printf("%d %d %d\n", x, y, age);
	}
	
	return;
}

void Summer()  //봄에 죽은 나무가 양분으로 변함
{
	for (int i = 0; i < food.size(); i++)  //죽은 나무가 담긴 벡터인 food벡터를 반복하며 (각 죽은 나무의 나이 / 2)가 나무가 있던 칸에 추가됨. 
	{
		A[food[i].first.first][food[i].first.second] += floor(food[i].second/2);
	}

	food.clear();
	return;
}

void Autumn() //나무가 번식한다, 번식하는 나무는 나이가 5의 배수
{
	while(!temp.empty())
	{
		int x = temp.top().first.first;
		int y = temp.top().first.second;
		int tree_age = temp.top().second;
		temp.pop();
		tree.push({ { x,y },tree_age });

		if (tree_age % 5 == 0)  //번식하는 나무의 나이가 5의 배수이면, 주변에 번식
		{
			for (int p = 0; p < 8; p++)
			{
				int nx = x + dx[p];
				int ny = y + dy[p];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
				{
					tree.push({ {nx,ny}, 1 }); //map을 벗어나지 않는 인접한 8개의 칸에 나이가 1인 나무가 생김.
				}
			}
		}
	}
	//printf("tree.size() : %d\n", tree.size());
	return;
}

void Winter()
{
	//S2D2가 땅을 돌아다니면서 땅에 양분을 추가. 각 칸에 추가되는 양분은 입력으로 주어진 A[r][c]임.
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			A[i][j] += map[i][j]; 
		}
	}

	return;
}


void TreeJaetech()
{
	//봄
	Spring();
	//여름
	Summer();
	//가을
	Autumn();
	//겨울
	Winter();
	return;
}

int main(void)
{
	cin >> N >> M >> K;

	//매년 겨울에 S2D2머신이 추가하는 양분 
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &map[i][j]);
			A[i][j] = 5;
		}
	}

	int x, y, old;

	for (int i = 0; i < M; i++)
	{
		scanf_s("%d %d %d", &x, &y, &old);
		tree.push(make_pair(make_pair(x, y), old));
	}

	for (int year = 1; year <= K; year++)
	{
		//printf("년도 : %d\n", year);
		TreeJaetech();
	}

	//살아남은 나무의 수(결과)를 출력
	int Alivetree = tree.size();
	cout << Alivetree << endl;
	return 0;
}