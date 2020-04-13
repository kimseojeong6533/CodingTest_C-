#include <iostream>
#include <string>
#define MAX_SIZE 11
using namespace std;

int dx[] = { -1,1,0,0 };  //위(0),아래(1),오른(2),왼(3)
int dy[] = { 0,0,1,-1 };

int visit[MAX_SIZE][MAX_SIZE] = { 0, };


int solution(string dirs) {
	int answer = 0;

	int i = 5;
	int j = 5;
	int k = -1;
	visit[i][j] = 1;
	int d = dirs.size();

	while (k < d)
	{
		k+=1;

		int m = i;
		int n = j;

		printf("k : %c\n", dirs[k]);
		for (int p = 0; p < 11; p++)
		{
			for (int q = 0; q < 11; q++)
			{
				printf("%d ", visit[p][q]);
			}
			printf("\n");
		}
		printf("answer : %d \n", answer);
		s


		if (dirs[k] == 'U')
		{
			i += dx[0];
			j += dy[0];

		}
		else if (dirs[k] == 'D')
		{
			i += dx[1];
			j += dy[1];


		}

		else if (dirs[k] == 'R')
		{
			i += dx[2];
			j += dy[2];

		}
		else if (dirs[k] == 'L')
		{
			i += dx[3];
			j += dy[3];

		}


		if (i < 0 || j < 0 || i>10 || j>10)
		{
			continue;
		}

		if (visit[i][j] == 0)
		{

			answer++;
			visit[i][j] = 1;
		}
		
	}


	return answer;

}

int main(void)
{
	string s = "ULURRDLLU";
	int ret = solution(s);
	cout << ret << endl;

	return 0;
}