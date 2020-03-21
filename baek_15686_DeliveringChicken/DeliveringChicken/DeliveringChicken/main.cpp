//치킨배달 ㄹㅇ How Think This
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX_SIZE 52

using namespace std;

int N;  //도시의 크기
int M;  //폐업시키지 않을 최대 치킨집 개수
int city[MAX_SIZE][MAX_SIZE];
vector< pair <int, int> > chic;  //치킨집의 위치가 들어가는 벡터
vector<pair <int, int> > house;  //집의 위치가 들어가는 벡터

vector<pair <int,int> >pick;

int ret=1000000;

void dfs(int x)
{

	if (pick.size() == M)
	{
		int dist_sum = 0;
		for (int i = 0; i < house.size(); i++)  //각집에서의 치킨집까지의 거리를 구하고, 그중 최솟값이 치킨거리임.
		{
			
			int Min_val = 1000000;
			for (int j = 0; j < pick.size(); j++)
			{
				int dist = abs(pick[j].first - house[i].first) + abs(pick[j].second - house[i].second);
				if (dist < Min_val)
					Min_val = dist;
				
			}
			dist_sum += Min_val;  //가장 최솟값인 치킨거리를 ret에 더하여 도시의 치킨거리를 구함  
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

