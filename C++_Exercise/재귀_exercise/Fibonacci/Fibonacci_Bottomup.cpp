#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[91];

void Fibonacci2(int n)
{
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}

}
int main(void)
{
	
	cin>>n;
	
	Fibonacci2(n);
	cout<<dp[n]<<endl;
	
	return 0;
	
}
