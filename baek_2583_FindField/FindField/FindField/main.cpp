#include <iostream>
#include <vector>
#define MAX_SIZE 102

using namespace std;

int N, M, K;
int map[MAX_SIZE][MAX_SIZE];

typedef struct Box
{
	int ld_x;
	int ld_y;
	int ru_x;
	int ru_y;

}BOX;


int main(void)
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int ld_x;
		int ld_y;
		int ru_x;
		int ru_y;
		scanf_s("%d %d %d %d", &ld_x, &ld_y, &ru_x, &ru_y);
		

	}

	//

	return 0;
}