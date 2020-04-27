#include <iostream> 
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	queue <int> truck;  //다리를 현재 건너고 있는 트럭

	int totaltime = 0;
	int total_weight = 0;



	for (int i = 0; i < truck_weights.size(); i++)
	{
		int size = truck_weights[i];
		while (1)
		{

			if (truck.empty())
			{
				truck.push(truck_weights[i]);
				total_weight += size;
				answer++;
				break;
			}

			else if (truck.size() == bridge_length)
			{
				total_weight -= truck.front();
				truck.pop();

			}
			else
			{
				if (size + total_weight > weight)
				{
					truck.push(0);
					answer++;
				}
				else
				{
					truck.push(size);
					total_weight += size;
					answer++;
					break;
				}
			}

		}
	}

	printf("%d\n", answer);
	answer += bridge_length;

	return answer;
}

int main(void)
{
	int length = 2;
	int w = 10;
	vector <int> truck_w;

	truck_w.push_back(7);
	truck_w.push_back(4);
	truck_w.push_back(5);
	truck_w.push_back(6);


	int result = solution(length, w, truck_w);
	cout << result << endl;
	return 0;
}