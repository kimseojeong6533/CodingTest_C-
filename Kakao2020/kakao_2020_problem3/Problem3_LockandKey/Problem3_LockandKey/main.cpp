#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(vector <vector <int> > key, vector <vector <int> >lock)
{
	//


	//key���� lock�� ��Ҹ� NxN��ŭ ���ϰ�,  �ݺ����� ������ ��, ��簪�� 1�̸� true�� ����, �ƴϸ�, false�� ���� 


}



int main(void)
{

	vector <vector <int> > key;
	vector <vector <int> > lock;

	vector <int> s_key;
	vector <int> s_lock;

	/* key���ߺ��Ϳ� ���� �ִ� ����*/
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

	//lock���ߺ��Ϳ� ���� �ִ� ����
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