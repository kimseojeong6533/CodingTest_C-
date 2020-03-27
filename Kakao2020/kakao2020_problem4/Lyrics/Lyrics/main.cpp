#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> answer;

	for (int i = 0; i < queries.size(); i++)
	{
		string s_q = queries[i];

		int cnt = 0;
		
		for (int k = 0; k < words.size(); k++)
		{
			string w = words[k];
			bool flag = true;
			if (s_q.size() != w.size())
				continue;

			for (int j = 0; j < s_q.size(); j++)
			{
				if (s_q[j] == '?')
					continue;

				if (s_q[j] != w[j])
				{
					flag = false;
					break;
				}

			}
			if (flag == true)
				cnt++;

		}

		answer.push_back(cnt);
	}



	return answer;
}


int main(void)
{
	vector<string> words;
	words.push_back("frodo");
	words.push_back("front");
	words.push_back("frost");
	words.push_back("frozen");
	words.push_back("frame");
	words.push_back("kakao");

	vector <string> queries;
	queries.push_back("fro??");
	queries.push_back("????o");
	queries.push_back("fr???");
	queries.push_back("fro???");
	queries.push_back("pro?");
	
	
	vector <int> ans = solution(words, queries);

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}