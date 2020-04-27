#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    deque <pair <int,int> > deq;  //레이저의 인덱스가 들어가는 
    
    for(int i=0;i<arrangement.size();i++)
    {
        if(arrangement[i]==')')
        {
            arrangement[i-1]='.';
            arrangement[i]='*';
            //deq.push_back({i-1,i});
        }
    }
    
	for(int i=0;i<arrangement.size();i++)
    {
    	if(arrangement[i]=='*' || arrangement[i]=='.')
    		continue;
    		
    	if(arrangement[i]=='(')
    	{
    		int f=1;
    		int b=0;
    		int star=0;
    		
    		int j=i+1;
    		while(j<arrangement[i])
    		{
    			if(arrangement[j]=='(')
		        	f++;
		        
		        else if(arrangement[j]==')')
		        	b++;
				
				else if(arrangement[j]=='*')
					star++;
					
				if(f==b)
				{
					if(star>0);
						answer+=star+1;					
					break;	
				}
				j++;
			}
		}
	        
    }
    
    return answer;
}

int main(void)
{
	string arran="()(((()())(())()))(())";
	int result=solution(arran);
	cout<<result<<endl;
	return 0;
}

