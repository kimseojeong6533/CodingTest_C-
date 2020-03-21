// 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 구해보자.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAX_SIZE 22

using namespace std;

int N;
int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
queue<pair <int, int> > gu5_inside;
vector<pair <int, int> > gu_5; //5선거구의 경계점(4개)을 넣는 벡터

int gu[6] = { 0, };  //각 구의 인구수를 넣을 배열  
bool flag = true;
int Pre = 1000000;

//visit2차원배열,gu_5벡터,gu배열 초기화필요 

void Clearness()
{
	memset(visit, 0, sizeof(visit));
	gu_5.clear();
	memset(gu, 0, sizeof(gu));
    return;
}

void Make1(int x, int y, int d1, int d2)
{
	for (int i = 1; i <= (x + d1-1); i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (visit[i][j] == 5)
				break;
			
			visit[i][j] = 1;
		}
	}
	return;
}

void Make2(int x, int y, int d1, int d2)  
{
	for (int i = (x+d2); i >=1; i--)
	{
		for (int j = N; j >= y+1; j--)
		{
			if (visit[i][j] == 5)	
				break;
			
			visit[i][j] = 2;
		}
		
	}
	return;
}

void Make3(int x, int y, int d1, int d2)
{
	for (int i = x + d1; i <= N; i++)
	{
		for (int j = 1; j <= (y - d1 + d2-1); j++)
		{
			if (visit[i][j] == 5)
				break;

			visit[i][j] = 3;
			
		}
		
	}
    return;
	
}

void Make4(int x, int y, int d1, int d2)
{  //여기에서 그냥 넘어가버림 
	for (int i = (x+d2+1);i <= N;i++)
	{
		for (int j = N; j >= (y - d1 + d2); j--)
		{
			if (visit[i][j] == 5)
				break;

			visit[i][j] = 4;

		}
	}
    return;
	
}

void Makegu5_4(int x, int y, int d1, int d2)  //Make5_2함수의 끝점을 이어받아서 오른쪽위에서 아래로
{											 //처음 x=x+d2, y=y+d2임 
	int nx = x;
	int ny = y;
	while (nx <= x + d1 && ny >= y - d1)
	{
		if (nx<1 || nx>N || ny<1 || ny>N)
		{
			flag = false;
			return;
		}
		visit[nx][ny] = 5;
		nx += 1;
		ny -= 1;
	}
	
	return;
}

void Makegu5_3(int x, int y, int d1, int d2)  //Make5_1함수의 끝점을 이어받아서 왼쪽위에서 아래로
{											 //처음에 x=x+d1, y=y-d1; 
	int nx = x;
	int ny = y;
	while (nx <= x + d2 && ny <= y + d2)
	{
		
		if (nx<1 || nx>N || ny<1 || ny>N)
		{
			flag = false;
			return;
		}
		visit[nx][ny] = 5;
		nx += 1;
		ny += 1;
	}
	gu_5.push_back({ nx-1,ny-1 }); //(맨아래점)
	return;

}

void Makegu5_1(int x, int y,int d1, int d2)  //위에서 왼쪽아래로
{
	int nx = x;
	int ny = y;
	  
	while (nx <= x + d1 && ny >= (y - d1))
	{
		
		if (nx<1 || nx>N || ny<1 || ny>N)
		{
			flag = false;
			return;
		}
		visit[nx][ny] = 5;
		nx += 1;
		ny -= 1;
	}

	gu_5.push_back({ nx-1,ny+1 }); //끝점(왼쪽아래점)을 gu_5에 넣음
	Makegu5_3(nx-1, ny+1,d1, d2);
	return;
}

void Makegu5_2(int x, int y,int d1,int d2)  //위에서 오른쪽아래로
{
	if (flag == true)
	{
		int nx = x;
		int ny = y;

		while (nx <= x + d2 && ny <= y + d2)
		{
			if (nx<1 || nx>N || ny<1 || ny>N)
			{
				flag = false;
				return;
			}
			visit[nx][ny] = 5;
			nx += 1;
			ny += 1;
		}
		gu_5.push_back({ nx - 1,ny - 1 });  //끝점(오른쪽아래점)을 gu_5에 넣음
		Makegu5_4(nx - 1, ny - 1, d1, d2);

	}
	return;

}

//5선거구의 속 채우기
void Make5_full(int x, int y,int d1, int d2)  //빈곳의 선거구5를 채운다
{
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 0)
				visit[i][j] = 5;
		}
	}
	return;
}

//각 구의 인구수를 gu배열에 넣기
void SumPeople()
{
	//각 선거구별 인구수를 gu배열에 넣음
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 1)
			{
				gu[1] += map[i][j];
			}
			else if (visit[i][j] == 2)
			{
				gu[2] += map[i][j];
			}
			else if (visit[i][j] == 3)
			{
				gu[3] += map[i][j];
			}
			else if (visit[i][j] == 4)
			{
				gu[4] += map[i][j];
			}
			else if (visit[i][j] == 5)
			{
				gu[5] += map[i][j];
			}
		}
	}
	return;
}


void Make5(int d1,int d2)  //d1,d2에 따른 기준점(x,y)범위를 찾고, 5번선거구의 경계선 찾음  
{
	
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{

			if(x >= 1 && x<(x + d1 + d2) && (x + d1 + d2) <= N && y - d1 >= 1 && y>y - d1 && y < (y + d2) && (y + d2) <= N)
			{ 
				gu_5.clear();
				/*if (x == 1 && y == 3 && d1 == 2 && d2 == 3)
				{
					printf("x == 1 && y == 3 && d1 == 2 && d2 == 3");
				}*/

				visit[x][y] = 5;
				gu_5.push_back({ x,y }); //맨위의 점
				Makegu5_1(x,y,d1,d2);
				Makegu5_2(x,y,d1,d2);
				if (flag == false)
				{
					//visit초기화하고 
					memset(visit, 0, sizeof(visit));
					flag = true;
					continue;
					
					
				}
				else  //(flag == true)
				{
					//기준점 아래점은 반드시 5선거구 안에 포함됨.
					
					Make2(x, y, d1, d2);
					Make1(x, y, d1, d2);
					
					Make4(x, y, d1, d2);
					Make3(x, y, d1, d2);

					Make5_full(x, y, d1, d2); //선거구5의 속 채우기

					//각 구의 인구수를 gu배열에 넣기
					SumPeople();
					/*
					cout << endl;
					for (int i = 1; i <= N; i++)
					{
						for (int j = 1; j <= N; j++)
						{
							printf("%d ", visit[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					*/

					//gu배열에서 최대인구수와 최소인구수를 구하고 그 차이구함
					int Maxval = -1;
					int Minval = 1000000;

					for (int i = 1; i <= 5; i++)
					{
						Maxval = max(Maxval, gu[i]);
						Minval = min(Minval, gu[i]);
					}
					Clearness(); //초기화
					int result=(Maxval - Minval);  //차이가 가장 작은값이 Pre변수에 들어감
					
					Pre = min(Pre, result);
				}
			}

		}
	}
    return;
}



int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Make5(i,j);  //1~5까지 선거구를 나눔 
		}
	}

	cout << Pre << endl;
	return 0;
}
