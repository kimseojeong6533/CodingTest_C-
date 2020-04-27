#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack <char> pipe;

	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') pipe.push(arrangement[i]);
		else {
			pipe.pop();
			if (arrangement[i - 1] == '(') answer += pipe.size();
			else answer += 1;
		}
	}
	return answer;
}

int main(void)
{
	string arran = "()(((()())(())()))(())";
	int result = solution(arran);
	cout << result << endl;
	return 0;
}
