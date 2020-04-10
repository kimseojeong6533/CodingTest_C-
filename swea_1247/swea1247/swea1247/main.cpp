#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int N;

int main(void)
{

	cin >> N;

	int C_x, C_y;
	for (int i = 0; i < N; i++)
	{
		
		if (i == 0)
		{
			int H_x, H_y;
			scanf_s("%d %d", &H_x, &H_y);
		}
		else
			scanf_s("%d %d", &C_x, &C_y);
	}

	return 0;
}