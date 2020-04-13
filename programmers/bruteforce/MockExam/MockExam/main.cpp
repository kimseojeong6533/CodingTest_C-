#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_SIZE 10
using namespace std;

vector <int> v1;
vector<int> solution(vector<int> answers) {  //answers벡터에는 정답이 들어가있음
	vector<int> answer; //0번재는 수포자1, 1번째는 수포자2, 2번재는 수포자3의 정답개수가 들어감

	int math1[MAX_SIZE] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };  //수포자1의 문제는 20개이다.
	int math2[MAX_SIZE] = { 2, 1, 2, 3, 2, 4, 2, 5, 2, 1 };
	int math3[MAX_SIZE] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int i = 0;
	int math_ans=0;
	for (int num = 0; num < 3; num++)
	{
		while (i <= MAX_SIZE)
		{
			for (int j = 0; j < answers.size(); j++)
			{
				if (math1[i] == answers[j])
				{
					math_ans++;
				}
				i++;
			}
		}
		answers.push_back(math_ans);
	}
	sort(answers.begin(), answers.end());
	for (int i = 0; i < 3; i++)
	{
		cout << answers[i] << endl;
	}
	

	return answer;
}

int main(void) {
	vector<int> result;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	result=solution(v1);
	for (int i = 0; result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	system("pause");
	return 0;
}

