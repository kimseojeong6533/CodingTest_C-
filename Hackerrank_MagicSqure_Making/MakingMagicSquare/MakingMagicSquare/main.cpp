//Ȧ�� ������(MagicSquare)�� ����� ��Ģ�� ���� ������
#include <iostream>
#include <vector>
#define MAP_SIZE 3

int map[MAP_SIZE][MAP_SIZE] = { 0, };  // 3x3 �������� ������̴�.
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
	
	//�ʱⰪ 
	map[i][j] = n;  //map[2][1]�� 1�� �ְ�, �ٷ� n���� (1->2) ��Ŵ
	n++;
	i++;
	j++;
	
	while (n <= 9)
	{	
		if (i ==3 && j ==3)  //�����ʾƷ�ĭ�� �簢�������� �����ʾƷ�ĭ, �� (2,2)�ϰ��, ���� ������ ��ĭ�� ���� ���ڸ� ä���.
		{
			i -= 2;
			j--;
			map[i][j] = n;

		}

		else if (i > 2 || j > 2)  //�����ʾƷ�ĭ�� �������̶�� 
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

		else if(i<3 && j<3 && map[i][j]==0)  //�����ʾƷ� ĭ�� ����ִٸ� �ű⿡ ���� �־���
		{
			map[i][j] = n;
			
		}
		else if(i<3 && j<3 && map[i][j]!=0) //�����ʾƷ� ĭ�� ä�����ִٸ�, �������� ��ġ�� ��ĭ�� ���� ���ڸ� ä���.
		{
			//�������� ��ġ�� ��ĭ
			i = i - 2;
			j = j - 1;
			map[i][j] = n;  //���ڸ� ä��
	
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
	//���� �������� �Ȱ��� �������迭�� ���� -> map2
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map2[i][j] = map[i][j];
		}
	}
	
	//������ ȸ�� (90, 180, 270)
	
	
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