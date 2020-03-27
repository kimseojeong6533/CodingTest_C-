#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(vector <vector <int> > key, vector <vector <int> >lock)
{
	//


	//key값과 lock의 요소를 NxN만큼 더하고,  반복문을 돌렷을 때, 모든값이 1이면 true로 리턴, 아니면, false로 리턴 


}



int main(void)
{

	vector <vector <int> > key;
	vector <vector <int> > lock;

	vector <int> s_key;
	vector <int> s_lock;

	/* key이중벡터에 값을 넣는 과정*/
	s_key.push_back(0);
	s_key.push_back(0);
	s_key.push_back(0);
	key.push_back(s_key);

	s_key.clear();
	s_key.push_back(1);
	s_key.push_back(0);
	s_key.push_back(0);
	key.push_back(s_key);

	s_key.clear();
	s_key.push_back(0);
	s_key.push_back(1);
	s_key.push_back(1);
	key.push_back(s_key);
	s_key.clear();

	//lock이중벡터에 값을 넣는 과정
	s_lock.push_back(1);
	s_lock.push_back(1);
	s_lock.push_back(1);
	lock.push_back(s_lock);

	s_lock.clear();
	s_lock.push_back(1);
	s_lock.push_back(1);
	s_lock.push_back(0);
	lock.push_back(s_lock);
	
	s_lock.clear();
	s_lock.push_back(1);
	s_lock.push_back(0);
	s_lock.push_back(1);

	lock.push_back(s_lock);
	s_lock.clear();

	solution(key, lock);


}