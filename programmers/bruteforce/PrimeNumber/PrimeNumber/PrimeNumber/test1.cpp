#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	set <int>s;
	string num = "011";
	s.insert(stoi(num));
	s.insert(11);    //set컨테이너는 011과 11을 같다고 보기때문에(*set컨테이너의 특성상, 중복허용안됌) s.size()=1이고, 원소도 11하나만 들어가게됨.
	set<int>::iterator iter;  //set컨테이너를 출력할때는 왼쪽처럼 써야함 (iter포인터를 사용한다고 생각하면 됌)
	for (iter = s.begin(); iter != s.end(); ++iter)
	{
		cout << *iter << "";
		cout << endl;
	}
	cout << s.size() << endl;
	return 0;
}