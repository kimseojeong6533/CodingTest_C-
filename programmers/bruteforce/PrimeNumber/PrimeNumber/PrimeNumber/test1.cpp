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
	s.insert(11);    //set�����̳ʴ� 011�� 11�� ���ٰ� ���⶧����(*set�����̳��� Ư����, �ߺ����ȉ�) s.size()=1�̰�, ���ҵ� 11�ϳ��� ���Ե�.
	set<int>::iterator iter;  //set�����̳ʸ� ����Ҷ��� ����ó�� ����� (iter�����͸� ����Ѵٰ� �����ϸ� ��)
	for (iter = s.begin(); iter != s.end(); ++iter)
	{
		cout << *iter << "";
		cout << endl;
	}
	cout << s.size() << endl;
	return 0;
}