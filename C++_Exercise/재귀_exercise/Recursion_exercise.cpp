#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
void Hello(int cnt)
{
	if(v.size()==3)
	{
		printf("%d ",cnt);
		return;
	}
		
	
	v.push_back(cnt);
	Hello(cnt+1);
	v.pop_back();
}

int main(void)
{
	for(int i=0;i<5;i++)
		Hello(i);
	
	return 0;
}
