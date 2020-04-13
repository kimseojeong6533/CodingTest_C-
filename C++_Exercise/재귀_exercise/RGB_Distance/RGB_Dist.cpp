#include <bits/stdc++.h>
#define MAX_SIZE 1000001
using namespace std;

int N;
int color[MAX_SIZE];

vector <int> v[4];

void dp(int i)  // 
{
	
	for(int x=0;x<3;x++)
	{
		
	}
	
}

int main(void)
{
	cin>>N;  //집의 수 
	int red,green,blue;
	
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d",&red,&green,&blue);
		v[i].push_back(red);
		v[i].push_back(green);
		v[i].push_back(blue);
	} 
	
	for(int i=1;i<N-1;i++)  //0번째와 마지막번째 집은  제외 
	{
		dp(i);
	}
	
	return 0;
}
