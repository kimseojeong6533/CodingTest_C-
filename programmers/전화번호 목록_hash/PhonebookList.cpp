//test¿ë 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(void)
{
	vector <string> v;
	v.push_back("8");
	v.push_back("13456");
	v.push_back("79");
	v.push_back("112");
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.sizµµe();i++)
	{
		cout<<v[i]<<endl;
	}
	
	return 0;
}
