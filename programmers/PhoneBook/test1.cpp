#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s="1234";
	string a="0";
	if(s.find(a)>=0)
		cout<<s.find(a)<<endl;
	else
		cout<<"No"<<endl;
	
	return 0;
}
