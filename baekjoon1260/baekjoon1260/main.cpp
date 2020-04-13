#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> vec[10001];
int visit_b[10001] = { 0, };
int visit_d[10001] = { 0, };


void bfs(int start)
{
	queue <int> q;
	q.push(start);
	visit_b[start] = 1;    //�湮�Ѱ��� 1�� ó��
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d ", now);
		
		sort(vec[now].begin(),vec[now].end());
		

		for (int j = 0; j < vec[now].size(); j++)
		{
			int x = vec[now][j];
			if (!visit_b[x])
			{
				visit_b[x] = 1;
				q.push(x);
			}
		}

	}

}

void dfs(int x)
{
	if (visit_d[x]) return;
	visit_d[x] = true;

	cout << x << ' ';
	for (int i = 0; i < vec[x].size(); i++)
	{
		int df = vec[x][i];
		dfs(df);
	}

}

int main(void)
{
	int N, M, V;  //N : ��������, M : ��������, V : Ž���� ������ ������ȣ
	int num1, num2;
	
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
		
	}

	dfs(V);
	printf("\n");
	bfs(V);
	

	system("pause");
	return 0;
}