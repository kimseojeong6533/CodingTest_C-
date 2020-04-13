#include <iostream>
#include <vector>

using namespace std;

int number=7;
int c[8];  //방문처리 배열 
vector <int> a[8];  //트리구조의 원소가 담길 벡터 

void dfs(int x)
{
	if(c[x]==1)  //x번째 노드가 방문처리 된 상태라면 바로 return 
		return;
	c[x]=1; //x번째 노드를 방문처리함 
	cout << x << ' ';
	for(int i=0;i<a[x].size();i++)  //x번째 노드와 인접한 노드를 찾음 
	{
		int y=a[x][i];  //인접한 노드를 y라는 변수에 담음 
		dfs(y);  //인접한 노드를 반복적으로 dfs함수에 넣어 처리함. 
	} 
	
	
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	dfs(1);
	
	return 0;
}

