//홀수 마방진(MagicSquare)을 만드는 규칙에 따라서 만들어보자
#include <iostream>
#include <vector>
#define MAP_SIZE 3

int map[MAP_SIZE][MAP_SIZE] = { 0, };  // 3x3 마방진을 만들것이다.
int map_rever[MAP_SIZE][MAP_SIZE];
int map2[MAP_SIZE][MAP_SIZE];


int map90[MAP_SIZE][MAP_SIZE];
int map180[MAP_SIZE][MAP_SIZE];
int map270[MAP_SIZE][MAP_SIZE];




int map2[MAP_SIZE][MAP_SIZE];

void MakingMagicSquare()
{
	int n = 1;
	int i = 2;
	int j = 1;
	
	//초기값 
	map[i][j] = n;  //map[2][1]에 1을 넣고, 바로 n증가 (1->2) 시킴
	n++;
	i++;
	j++;
	
	while (n <= 9)
	{	
		if (i ==3 && j ==3)  //오른쪽아래칸이 사각형영역의 오른쪽아래칸, 즉 (2,2)일경우, 이전 숫자의 윗칸에 다음 숫자를 채운다.
		{
			i -= 2;
			j--;
			map[i][j] = n;

		}

		else if (i > 2 || j > 2)  //오른쪽아래칸이 범위밖이라면 
		{
			if (j<3 && map[0][j] == 0)
			{	
				i = 0;
				map[i][j] = n;
			}
			
			else if (i<3 && map[i][0] == 0)
			{
				j = 0;
				map[i][j] = n;
			}
		}

		else if(i<3 && j<3 && map[i][j]==0)  //오른쪽아래 칸이 비어있다면 거기에 값을 넣어줌
		{
			map[i][j] = n;
			
		}
		else if(i<3 && j<3 && map[i][j]!=0) //오른쪽아래 칸이 채워져있다면, 이전숫자 위치의 윗칸에 다음 숫자를 채운다.
		{
			//이전숫자 위치의 윗칸
			i = i - 2;
			j = j - 1;
			map[i][j] = n;  //숫자를 채움
	
		}
		i++;
		j++;
		n++;
	}
}

void Rotate90()
{
	
}

int main(void)
{
	MakingMagicSquare();
	//만든 마방진과 똑같은 이차원배열을 만듦 -> map2
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map2[i][j] = map[i][j];
		}
	}
	
	//마방진 회전 (90, 180, 270)
	
	
	//


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}