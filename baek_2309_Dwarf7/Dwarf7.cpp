#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

bool desc(int a, int b)
{
	return a>b;
}
vector <int> Nanzang()
{
	vector <int> idx;
	vector <int> sub;
	
	int r=7;  //¿œ∞ˆ≥≠¿Ô¿Ã  
	for(int i = 0; i < r; i++)
        idx.push_back(1);
    for(int i = 0; i < v.size()-r; i++)
        idx.push_back(0);
    sort(idx.begin(), idx.end(),desc);
	
	do{
        for(int i = 0; i < v.size(); i++)
		{
            if(idx[i] == 1)
            	sub.push_back(v[i]);							
        }
    	
    	int sum=0;
		for(int i=0;i<sub.size();i++)
		{
			sum+=sub[i];
		}    
        
        if(sum==100)
        	return sub;
        sub.clear();
        
    }while(next_permutation(idx.begin(), idx.end(),desc));
}

int main(void)
{
	
	
	for(int i=0;i<9;i++)
	{
		int height;
		scanf("%d",&height);
		v.push_back(height);
	}
	
	vector <int> res=Nanzang();
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++)
	{
		printf("%d\n",res[i]);
	}
	
	return 0;
}
