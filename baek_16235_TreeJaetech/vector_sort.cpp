#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair <pair <int, int>, int> > tree;

/*bool compare(int a, int b)  //오름차순 
{
	return a < b;
}*/

int main(void)
{
	int x,y,old;
	for(int i=0;i<3;i++)
	{
		scanf("%d %d %d",&x,&y,&old);
		tree.push_back(make_pair(make_pair(x,y),old));	
	}	
	
	
	sort(tree.begin(),tree.end());
	
	
	for(int i=0;i<tree.size();i++)
	{
		printf("%d %d %d\n",tree[i].first.first,tree[i].first.second,tree[i].second);
	}
	
	return 0;
}
