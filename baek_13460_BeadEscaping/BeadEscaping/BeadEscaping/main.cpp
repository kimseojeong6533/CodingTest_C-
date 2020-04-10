#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 12
using namespace std;

int N, M;  //����, ����

char map[MAX_SIZE][MAX_SIZE];
char visit[MAX_SIZE][MAX_SIZE];

queue <pair <int, int> > Bead_R;  //���������� ��ġ
queue <pair <int, int> > Bead_B;  //�Ķ������� ��ġ

int dx[] = { -1,0,1,0 };  //��,��,��,�� (�ð����)
int dy[] = { 0,1,0,-1 };

int turn = 1;

bool flag = true;
int Moving()
{
	if (turn > 10)
		return -1;

	//��, ��, ��, �Ϸ� ����̱�
	while (!Bead_R.empty() || !Bead_B.empty())  //10��
	{
		int R_x = Bead_R.front().first;   //���������� ��ġ
		int R_y = Bead_R.front().second;  
		Bead_R.pop();
		visit[R_x][R_y] = 'R';

		int B_x = Bead_B.front().first;  //�Ķ������� ��ġ
		int B_y = Bead_B.front().second;
		Bead_B.pop();
		visit[B_x][B_y] = 'B';

		int nx_R = R_x;
		int ny_R = R_y;
		int nx_B = B_x;
		int ny_B = B_y;
		
		int temp_Rx=0;
		int temp_Ry=0;
		int temp_Bx=0;
		int temp_By=0;

		for (int i = 0; i < 4; i++)  //���������� <��,��,��,��> �� ����̱�
		{
			while (1)  //�������� �����̱�
			{
				int sub_nx = nx_R;
				int sub_ny = ny_R;

				nx_R += dx[i];
				ny_R += dy[i];

				if (nx_R==B_x && ny_R==B_y)  //����̴ٰ� ���������� �Ķ������� ������ ��, 
				{
					temp_Bx = nx_R;
					temp_By = ny_R;
					continue;
				}

				if (map[nx_R][ny_R] == 'O')  //����̴ٰ� ������ ������
				{
					flag = false;
					break;
				}

				if (map[nx_R][ny_R] == '#')  //���� ������
				{
					if (sub_nx == R_x && sub_ny == R_y)
						break;

					if(temp_Bx ==0 && temp_By==0)
						Bead_R.push({ sub_nx,sub_ny });
					

					break;
				}
			}

			while (1)  //�Ķ����� �����̱�
			{
				int sub_nx = nx_B;
				int sub_ny = ny_B;

				nx_B += dx[i];
				ny_B += dy[i];

				if (nx_B == R_x && ny_B == R_y)
				{
					temp_
				}
				if (map[nx_B][ny_B] == 'O')  //����̴ٰ� ������ ������ -1�� ����
					return -1;

				if (map[nx_B][ny_B] == '#' || map[nx_B][ny_B] == 'R') //���Ǵ� ���������� ������
				{
					if (sub_nx == B_x && sub_ny == B_y)
						break;
						
					Bead_B.push({ sub_nx,sub_ny });
					visit[sub_nx][sub_ny] = 'B';
					visit[B_x][B_y] = '.';
					break;
				}
			}
			if (flag == false)
				return turn;
		}

		//map�� ������ ��ġ�� �ٲ�


		turn++;

	}
	
}

int main(void)
{
	int result;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%c", &map[i][j]);
			visit[i][j] = map[i][j];

			if (map[i][j] == 'R')
				Bead_R.push({ i,j });

			if (map[i][j] == 'B')
				Bead_B.push({ i,j });
		}
	}

	int turn = 10;
	Moving();
		
	cout << result << endl;
	return 0;
}