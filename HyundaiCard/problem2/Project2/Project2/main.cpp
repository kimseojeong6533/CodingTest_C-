#include <string>
#include <vector>

using namespace std;
int visit[101] = { 0, };
int same[100001] = { 0, };

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {

	int answer = 0;

	for (int i = 0; i < ip_addrs.size(); i++)
	{
		//if(visit[i]==1)
		//    continue;
		string sub = ip_addrs[i];

		int sub_cnt = 1;
		int ind2;
		int ind3;

		for (int j = 0; j < ip_addrs.size(); j++)
		{
			if (i == j)
				continue;
			if (ip_addrs[i] == ip_addrs[j])
			{
				sub_cnt++;  //같은 ip주소의 사람수 

				//조건1
				if (sub_cnt >= 4)
				{
					continue;
				}
				//조건2
				else if (sub_cnt >= 3)
				{
					ind3 = j;
					if (langs[i][0] == langs[ind2][0] && langs[ind2][0] == langs[ind3][0])
					{
						if (langs[i][0] == 'C')
						{
							visit[ind2] = 1;
							visit[ind3] = 1;

						}
						else if (langs[i][0] == 'J')
						{
							if (langs[i] == langs[ind2] && langs[ind2] == langs[ind3])
							{
								visit[ind2] = 1;
								visit[ind3] = 1;
							}
							else
							{
								answer++;
							}
						}
					}
				}
				//조건3
				else if (sub_cnt >= 2)
				{
					ind2 = j;
					if (langs[i][0] == langs[j][0])
					{
						if (langs[i][0] == 'C')
						{
							if (scores[i] == scores[j])
								visit[j] = 1;
						}
						else
						{
							if (scores[i] == scores[j])
								visit[j] = 1;


						}
					}
					else
						answer++;
				}


			}
		}
	}

	return answer;
}

int main(void)
{


	return 0;
}