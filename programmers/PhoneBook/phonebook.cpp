#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i=0;i<phone_book.size();i++)
    {
        for(int j=0;j<phone_book.size();j++)
        {
            if(i==j)
                continue;
            if(phone_book[j].find(phone_book[i])>=0) 
            {
            	cout<<phone_book[j].find(phone_book[i])<<endl;
            	cout<<"phone_book[j] : "<<phone_book[j]<<endl;
            	cout<<"phone_book[i] : "<<phone_book[i]<<endl;
				return false;
			}    
            
        }
        
    }
    
    return answer;
}

int main(void)
{
	vector <string> p;
	p.push_back("123");
	p.push_back("456");
	p.push_back("789");
	bool answer=solution(p);
	
	if(answer==0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;
	return 0;
}
