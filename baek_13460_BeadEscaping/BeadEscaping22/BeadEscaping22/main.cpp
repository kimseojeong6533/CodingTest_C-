#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 12
using namespace std;

int N, M;  //세로, 가로

char map[MAX_SIZE][MAX_SIZE];
char visit[MAX_SIZE][MAX_SIZE];

queue <pair <int, int> > Bead_R;  //빨간구슬의 위치
queue <pair <int, int> > Bead_B;  //파란구슬의 위치

int dx[] = { -1,0,1,0 };  //상,우,하,좌 (시계방향)
int dy[] = { 0,1,0,-1 };

int turn = 1;

bool flag = true;
bool meetflag = false;
int Moving()
{
	if (turn > 10)
		return -1;

	//좌, 우, 상, 하로 기울이기
	while (!Bead_R.empty() || !Bead_B.empty())  //10번
	{
		int R_x = Bead_R.front().first;   //빨간구슬의 위치
		int R_y = Bead_R.front().second;
		Bead_R.pop();
		visit[R_x][R_y] = 'R';

		int B_x = Bead_B.front().first;  //파란구슬의 위치
		int B_y = Bead_B.front().second;
		Bead_B.pop();
		visit[B_x][B_y] = 'B';

		int nx_R = R_x;
		int ny_R = R_y;
		int nx_B = B_x;
		int ny_B = B_y;
		int tempx = 0;
		int tempy = 0;
		
		for (int i = 0; i < 4; i++)  //빨간구슬을 <상,우,하,좌> 로 기울이기
		{
			while (1)  //빨간구슬 움직이기
			{
				int sub_nx = nx_R;
				int sub_ny = ny_R;

				nx_R += dx[i];
				ny_R += dy[i];

				//기울이다가 파란구슬을 만났을 때
				if (nx_R == nx_B && ny_R == ny_B)
				{
					tempx = nx_R;
					tempy = ny_R;
					meetflag = true;
				}

				if (map[nx_R][ny_R] == 'O')  //기울이다가 구멍을 만나면
				{
					flag = false;
					break;
				}

				if (map[nx_R][ny_R] == '#')  //벽을 만나면
				{
					if (sub_nx == R_x && sub_ny == R_y)  //벽과 맞닿아있을 경우, 큐에 넣지 않음
						break;

					Bead_R.push({ sub_nx,sub_ny });
					break;
				}
			}

			while (1)  //파란구슬 움직이기
			{
				int sub_nx = nx_B;
				int sub_ny = ny_B;

				nx_B += dx[i];
				ny_B += dy[i];

				if (nx_B == R_x && ny_B == R_y)
				{
					
				}
				if (map[nx_B][ny_B] == 'O')  //기울이다가 구멍을 만나면 -1을 리턴
					return -1;



				if (map[nx_B][ny_B] == '#') //벽또는 빨간구슬을 만나면
				{
					if (sub_nx == B_x && sub_ny == B_y)
						break;

					//빨간구슬 움직이기
					if (tempx > 0 && tempy > 0)
					{

					}
					

					Bead_B.push({ sub_nx,sub_ny });
					visit[sub_nx][sub_ny] = 'B';
					visit[B_x][B_y] = '.';
					break;
				}
			}
			if (flag == false)
				return turn;
		}

		//map상에 구슬의 위치를 바꿈


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