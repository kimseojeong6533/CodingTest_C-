#include <string>
#include <vector>

using namespace std;
int visit[31][31]={0,};

int dx[]={0,1,1};  //위, 아래, 
int dy[]={1,0,1};

vector <pair <int,int> > block;
int bfs(int &x,int &y,int &m,int &n)
{
    vector <pair <int,int> > sub;
    int nums=0;
    char elem=board[i][j];  //보드안에 있는 것들은 char형
    for(int d=0;d<3;d++)
    {
        int nx=x+dx[d];
        int ny=y+dy[d];
        
        if(nx>=0 && nx<m && ny>=0 && ny<m)
        {
            if(board[nx][ny]==elem)
            {
                nums++;
                sub.push_back({nx,ny});
            }
            
            else
                return 0;
            
        }
        if(nums>=3)
        {
            for(int i=0;i<sub.size();i++)
            {
                block.push_back({sub[i].first,sub[i].second});
            }
            sub.clear();
            return 4;
        }
            
    }
}

int solution(int m, int n, vector<string> board) {  //m : 행, n : 렬
    int answer = 0;  //지워지는 총 블록의 개수 
    
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            answer+=Dfs(i,j,m,n);
        }
    }
    
    //block벡터에 있는 요소들을 꺼내서 보드에서 지움
    for(int i=0;i<block.size();i++)
    {
        board[block[i].first][block[i].second]='.';
    }
    
    //지워진후, 위에 있는 블럭이 아래로 내려옴
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]!='.')
            {
                int x=i;
                int y=j;
                int a;
                
                while(board[++x][y]!='.')
                {
                    
                }
            }
        }
    }
    
    
    return answer;
}
