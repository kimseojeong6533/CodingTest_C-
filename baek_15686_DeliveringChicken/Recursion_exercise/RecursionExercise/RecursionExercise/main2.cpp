#include <iostream>
#include <vector>
using namespace std;

int m = 3;
vector< pair <int, int> > shop, pick;  //SHOP���� ġŲ���� ������  

void(dfs(int x))
{

	if (pick.size() == m)
	{
		for (int i = 0; i < pick.size(); i++)
		{
			printf("%d%d ", pick[i].first, pick[i].second);
			
		}
		printf("\n");
		return;
	}

	for (int i = x; i < shop.size(); i++)
	{
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}


int main()
{
	shop.push_back({ 0,1 });
	shop.push_back({ 1,1 });
	shop.push_back({ 3,4 });
	shop.push_back({ 4,4 });
	shop.push_back({ 5,5 });

	for (int i = 0; i < shop.size(); i++)  //5�� shop�� ũ���� 
	{
		dfs(i);
	}

	system("pause");
	return 0;
}