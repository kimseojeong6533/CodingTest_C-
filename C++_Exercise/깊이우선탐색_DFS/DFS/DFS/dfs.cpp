#include <iostream>
#include <vector>

using namespace std;

int number=7;
int c[8];  //�湮ó�� �迭 
vector <int> a[8];  //Ʈ�������� ���Ұ� ��� ���� 

void dfs(int x)
{
	if(c[x]==1)  //x��° ��尡 �湮ó�� �� ���¶�� �ٷ� return 
		return;
	c[x]=1; //x��° ��带 �湮ó���� 
	cout << x << ' ';
	for(int i=0;i<a[x].size();i++)  //x��° ���� ������ ��带 ã�� 
	{
		int y=a[x][i];  //������ ��带 y��� ������ ���� 
		dfs(y);  //������ ��带 �ݺ������� dfs�Լ��� �־� ó����. 
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

