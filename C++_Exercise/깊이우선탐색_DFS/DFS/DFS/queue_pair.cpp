#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std; 


int main(void){

	queue <pair <int,int> > q;
	q.push(make_pair(1,2));
	
	int a=2;
	int b=3;
	
	pair <int,int> p = make_pair(a,b);
	
	q.push(p);
	
	
	cout << q.front().first
	
	return 0;

}
