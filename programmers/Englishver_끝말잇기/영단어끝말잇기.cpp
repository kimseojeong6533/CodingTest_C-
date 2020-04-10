//프로그래머스 끝말잇기 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int p=1;  //answer의 첫번째 요소
    int cnt=1;  //answer의 두번째 요소 ,p가 몇번째에 탈락하는지
    if(words[0].size()<2)
    {
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }
    
    string s1=words[0];   //tank
    char c1=s1[words[0].size()-1];  //tank-k
    
    vector <string> words2;
    words2.push_back(s1);
    
    for(int i=1;i<words.size();i++)
    {
        if(p%n==0 && p!=0)
        {
            p=1;
            cnt++;
            
        }
        else
            p++;    
        
        
        printf("p : %d, cnt : %d\n",p,cnt);
        if(words[i].size()<2)
        {
            answer.push_back(p);
            answer.push_back(cnt);
            return answer; 
        }
        
        //words2의 단어들과 비교해서 같은 것이 있으면 break;
        for(int j=0;j<words2.size();j++)
        {
            if(words[i]==words2[j])
            {
                answer.push_back(p);
                answer.push_back(cnt);
                return answer;
            }
        }
        
        string s2=words[i];   //kick
        
        char c2=s2[0];  //k
        if(c1==c2)  //tan(k)- k == (k)ick- k 
        {
            c1=s2[s2.size()-1];  //kic(k)-k
            s1=s2;  //tank -> kick
        }
        else
        {
            answer.push_back(p);
            answer.push_back(cnt);
            return answer;
        }
        
        words2.push_back(s2);
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main(void)
{
	
	//[hello, one, even, never, now, world, draw]
	vector <string> v;
	
	v.push_back("hello");
	v.push_back("one");
	v.push_back("even");
	v.push_back("never");
	v.push_back("now");
	v.push_back("world");
	v.push_back("draw");
	
	vector <int> ans;
	ans=solution(2,v);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	
}
