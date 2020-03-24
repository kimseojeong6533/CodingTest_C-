#include <iostream>
#include <functional>
#include <queue>
#include <cstdio>

using namespace std;

typedef pair <pair <int,int>,int > Pair;

struct cmp
{
	bool operator()(Pair p1,Pair p2)
	{
		return p1.second < p2.second;
	}
};

int main(){

	// priority_queue
	priority_queue<Pair, vector<Pair>,cmp> pq;
	// or priority_queue<int> pq;

	// push(element)
	for(int i=5;i>=0;i--)
	{
		for(int j=5;j>=0;j--)
		{
			for(int k=5;k>=0;k--)
			{
				pq.push({{i,j},k});
			}
		}
	}
	
	cout << "pq top : " << pq.top().first.first<<pq.top().first.second<<pq.top().second << '\n';


	// empty(), size()
	if(!pq.empty()) cout << "pq size : " << pq.size() << '\n';

	// pop all
	while(!pq.empty()){
		cout << pq.top().first.first<<" "<<pq.top().first.second<<" "<<pq.top().second<<endl;
		pq.pop();
	}

	cout << '\n';

	return 0;

}
