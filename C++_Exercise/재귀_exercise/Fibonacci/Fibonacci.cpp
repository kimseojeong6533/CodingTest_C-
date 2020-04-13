#include <bits/stdc++.h>

using namespace std;


int Fibonacci(int N)
{
    if(N==1)
        return 1;
    if(N==2)
        return 1;
        
    return Fibonacci(N-1)+Fibonacci(N-2);    
    
    
}

int main()
{
    int N;
    cin>>N;
    int ret=Fibonacci(N);
    cout<<ret<<endl;
    
    return 0;
}
