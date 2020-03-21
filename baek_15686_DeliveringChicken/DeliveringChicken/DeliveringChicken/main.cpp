//ġŲ��� ���� How Think This
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX_SIZE 52

using namespace std;

int N;  //������ ũ��
int M;  //�����Ű�� ���� �ִ� ġŲ�� ����
int city[MAX_SIZE][MAX_SIZE];
vector< pair <int, int> > chic;  //ġŲ���� ��ġ�� ���� ����
vector<pair <int, int> > house;  //���� ��ġ�� ���� ����

vector<pair <int,int> >pick;

int ret=1000000;

void dfs(int x)
{

	if (pick.size() == M)
	{
		int dist_sum = 0;
		for (int i = 0; i < house.size(); i++)  //���������� ġŲ�������� �Ÿ��� ���ϰ�, ���� �ּڰ��� ġŲ�Ÿ���.
		{
			
			int Min_val = 1000000;
			for (int j = 0; j < pick.size(); j++)
			{
				int dist = abs(pick[j].first - house[i].first) + abs(pick[j].second - house[i].second);
				if (dist < Min_val)
					Min_val = dist;
				
			}
			dist_sum += Min_val;  //���� �ּڰ��� ġŲ�Ÿ��� ret�� ���Ͽ� ������ ġŲ�Ÿ��� ����  
		}
		if (ret > dist_sum)
			ret = dist_sum;

		return;
	}

	for (int i = x; i < chic.size(); i++)
	{
		pick.push_back(chic[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}





int main(void)
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &city[i][j]);
			if (city[i][j] == 2)
			{
				chic.push_back(make_pair(i, j));
			}
			if (city[i][j] == 1)
			{
				house.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0);
	cout << ret << endl;
	
	return 0;
}

