#include <iostream>
#include <string>
#define MAX_SIZE 11
using namespace std;

int dx[]={-1,1,0,0};  //위(0),아래(1),오른(2),왼(3)
int dy[]={0,0,1,-1};

int map[MAX_SIZE][MAX_SIZE]={0,};
int visit[MAX_SIZE][MAX_SIZE]={0,};


int solution(string dirs) {
	int answer = 0;
    int i=5;
    int j=5;
    visit[i][j]=1;
    int k=0;
    
    while(k<dirs.length())
    {
		int m=i;
		int n=j;
		
        if(dirs[k]=='U')
        {

            i+=dx[0];
            j+=dy[0];
            
            if(i>=0 && j>=0)
            {
                if((visit[m][n]==0) && (visit[i][j] ==0 || visit[i][j]==1))  //현재 / 다음 
                {
                    
                    visit[m][n]=1;
                    
                }

            }
            if(i<0 || j<0)
            {
            	visit[m][n]=1;
            	i=m;
            	j=n;
            	
            	
			}
            
        
        }

        else if(dirs[k]=='D')
        {

            i+=dx[1];
            j+=dy[1];
            
            if(i>=0 && j>=0)
            {
                if((visit[m][n]==0) && (visit[i][j] ==0 || visit[i][j]==1))
                {
                
                    visit[m][n]=1;
                }

            }
            if(i<0 || j<0)
            {
            	visit[m][n]=1;
            	i=m;
            	j=n;
            	
			}
            
        
        }

        else if(dirs[k]=='R')
        {

            i+=dx[2];
            j+=dy[2];
            
            if(i>=0 && j>=0)
            {
                if((visit[m][n]==0) && (visit[i][j] ==0 || visit[i][j]==1))
                {
                    
                    visit[m][n]=1;
                }

            }
            if(i<0 || j<0)
            {
            	visit[m][n]=1;
            	i=m;
            	j=n;
            	
			}
            
        
        }

        else if(dirs[k]=='L')
        {

            i+=dx[3];
            j+=dy[3];
            
            if(i>=0 && j>=0)
            {
                if((visit[m][n]==0) && (visit[i][j] ==0 || visit[i][j]==1))
                {
        
                    visit[m][n]=1;
                }

            }
            if(i<0 || j<0)
            {
            	visit[m][n]=1;
            	i=m;
            	j=n;
            	
			}
            
        
        }
        
        for(int p=0;p<10;p++)
        {
            for(int q=0;q<10;q++)
            {
                printf("%d ",visit[p][q]);
            }
            printf("\n");
        }
        printf("\n");
        
        k++;
    }
    
    for(int i=0;i<MAX_SIZE;i++)
    {
    	for(int j=0;j<MAX_SIZE;j++)
    	{
    		if(visit[i][j]==1)
    			answer++;
		}
	}
    
	return answer;
	
}


int main(void)
{
	//ULURRDLLU
	//LULLLLLLU
	string s="LULLLLLLU";
	int ret=solution(s);
	cout<<ret<<endl;
	return 0;
}
