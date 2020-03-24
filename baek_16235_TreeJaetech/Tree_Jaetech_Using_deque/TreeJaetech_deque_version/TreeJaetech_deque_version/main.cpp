//�ð��ʰ�
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

int map[MAX_SIZE][MAX_SIZE] = { 0, };  //�Էµǰ�, A�� �߰��Ǵ� ��и�
int A[MAX_SIZE][MAX_SIZE];  //�̿�Ǵ� ��и� (�ʱ⿡ 5�� ����)

int N, M, K;  //N : ���� ũ��, M : ������ ����, K : ������ �� ��
int dx[] = { -1,-1,-1,0,0,1,1,1 };  //8��
int dy[] = { -1,0,1,-1,1,-1,0,1 };

typedef pair <pair <int, int>, int > Pair;

/*
struct cmp  //������ ���̺�, ������������ ���ĵ�.
{
	bool operator()(const Pair &p1, const Pair &p2)
	{
		return p1.second > p2.second;
	}
};*/

bool compare(const Pair &p1, const Pair &p2)
{
	return p1.second < p2.second;
}

deque <Pair> tree;  //����ִ� ������ ��� ����(���������� ������������ ���ĵ�)
deque <Pair> food;  //���� ������ ��� ����
deque <Pair> temp;


void Spring()
{
	sort(tree.begin(), tree.end(), compare);  //tree�� ��� ������ ������ ����������� ���ĵ�.
	while(!tree.empty())
	{
		int x = tree.front().first.first;
		int y = tree.front().first.second;
		int age = tree.front().second;
		tree.pop_front();

		if (A[x][y] - age >= 0) //�ڽ��� ���̸�ŭ ����� ���� �� �ִ� ���,
		{
			//����� �ش� ������ ���̸�ŭ �������, ���̰� 1 ����
			A[x][y] = A[x][y] - age;
			age++;
			temp.push_back({ { x,y }, age });  //�ӽ�ť�� ������ ������ �ִ´�.
		}
		else if (A[x][y] - age < 0) //�ڽ��� ���̸�ŭ ����� ���� �� ���� ���,
		{
			food.push_back(make_pair(make_pair(x, y), age));  //�ش� ������ ��ġ�� ���̸� ���������� ��� food���Ϳ� �ű�.
		}
		//printf("%d %d, %d\n", x, y, age);
		//printf("%d %d %d\n", x, y, age);
	}

	return;
}

void Summer()  //���� ���� ������ ������� ����
{
	while(!food.empty())  //���� ������ ��� ������ food���͸� �ݺ��ϸ� (�� ���� ������ ���� / 2)�� ������ �ִ� ĭ�� �߰���. 
	{
		int x = food.front().first.first;
		int y = food.front().first.second;
		int age = food.front().second;
		A[x][y] += floor(age / 2);
		food.pop_front();
		
	}

	
	return;
}

void Autumn() //������ �����Ѵ�, �����ϴ� ������ ���̰� 5�� ���
{
	while (!temp.empty())
	{
		int x = temp.front().first.first;
		int y = temp.front().first.second;
		int tree_age = temp.front().second;
		temp.pop_front();
		tree.push_back({ { x,y },tree_age });

		if (tree_age % 5 == 0)  //�����ϴ� ������ ���̰� 5�� ����̸�, �ֺ��� ����
		{
			for (int p = 0; p < 8; p++)
			{
				int nx = x + dx[p];
				int ny = y + dy[p];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
				{
					tree.push_back({ {nx,ny}, 1 }); //map�� ����� �ʴ� ������ 8���� ĭ�� ���̰� 1�� ������ ����.
				}
			}
		}
	}
	//printf("tree.size() : %d\n", tree.size());
	return;
}

void Winter()
{
	//S2D2�� ���� ���ƴٴϸ鼭 ���� ����� �߰�. �� ĭ�� �߰��Ǵ� ����� �Է����� �־��� A[r][c]��.
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
	//��
	Spring();
	//����
	Summer();
	//����
	Autumn();
	//�ܿ�
	Winter();
	return;
}

int main(void)
{
	cin >> N >> M >> K;

	//�ų� �ܿ￡ S2D2�ӽ��� �߰��ϴ� ��� 
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
		tree.push_back(make_pair(make_pair(x, y), old));
	}

	for (int year = 1; year <= K; year++)
	{
		//printf("�⵵ : %d\n", year);
		TreeJaetech();
	}

	//��Ƴ��� ������ ��(���)�� ���
	int Alivetree = tree.size();
	cout << Alivetree << endl;
	return 0;
}