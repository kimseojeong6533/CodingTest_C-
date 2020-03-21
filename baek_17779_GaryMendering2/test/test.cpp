// �α��� ���� ���� ���ű��� ���� ���� ���ű��� �α� ������ �ּڰ��� ���غ���.
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
vector<pair <int, int> > gu_5; //5���ű��� �����(4��)�� �ִ� ����

int gu[6] = { 0, };  //�� ���� �α����� ���� �迭  
bool flag = true;
int Pre = 1000000;

//visit2�����迭,gu_5����,gu�迭 �ʱ�ȭ�ʿ� 

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
{  //���⿡�� �׳� �Ѿ���� 
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

void Makegu5_4(int x, int y, int d1, int d2)  //Make5_2�Լ��� ������ �̾�޾Ƽ� ������������ �Ʒ���
{											 //ó�� x=x+d2, y=y+d2�� 
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

void Makegu5_3(int x, int y, int d1, int d2)  //Make5_1�Լ��� ������ �̾�޾Ƽ� ���������� �Ʒ���
{											 //ó���� x=x+d1, y=y-d1; 
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
	gu_5.push_back({ nx-1,ny-1 }); //(�ǾƷ���)
	return;

}

void Makegu5_1(int x, int y,int d1, int d2)  //������ ���ʾƷ���
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

	gu_5.push_back({ nx-1,ny+1 }); //����(���ʾƷ���)�� gu_5�� ����
	Makegu5_3(nx-1, ny+1,d1, d2);
	return;
}

void Makegu5_2(int x, int y,int d1,int d2)  //������ �����ʾƷ���
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
		gu_5.push_back({ nx - 1,ny - 1 });  //����(�����ʾƷ���)�� gu_5�� ����
		Makegu5_4(nx - 1, ny - 1, d1, d2);

	}
	return;

}

//5���ű��� �� ä���
void Make5_full(int x, int y,int d1, int d2)  //����� ���ű�5�� ä���
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

//�� ���� �α����� gu�迭�� �ֱ�
void SumPeople()
{
	//�� ���ű��� �α����� gu�迭�� ����
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


void Make5(int d1,int d2)  //d1,d2�� ���� ������(x,y)������ ã��, 5�����ű��� ��輱 ã��  
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
				gu_5.push_back({ x,y }); //������ ��
				Makegu5_1(x,y,d1,d2);
				Makegu5_2(x,y,d1,d2);
				if (flag == false)
				{
					//visit�ʱ�ȭ�ϰ� 
					memset(visit, 0, sizeof(visit));
					flag = true;
					continue;
					
					
				}
				else  //(flag == true)
				{
					//������ �Ʒ����� �ݵ�� 5���ű� �ȿ� ���Ե�.
					
					Make2(x, y, d1, d2);
					Make1(x, y, d1, d2);
					
					Make4(x, y, d1, d2);
					Make3(x, y, d1, d2);

					Make5_full(x, y, d1, d2); //���ű�5�� �� ä���

					//�� ���� �α����� gu�迭�� �ֱ�
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

					//gu�迭���� �ִ��α����� �ּ��α����� ���ϰ� �� ���̱���
					int Maxval = -1;
					int Minval = 1000000;

					for (int i = 1; i <= 5; i++)
					{
						Maxval = max(Maxval, gu[i]);
						Minval = min(Minval, gu[i]);
					}
					Clearness(); //�ʱ�ȭ
					int result=(Maxval - Minval);  //���̰� ���� �������� Pre������ ��
					
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
			Make5(i,j);  //1~5���� ���ű��� ���� 
		}
	}

	cout << Pre << endl;
	return 0;
}
