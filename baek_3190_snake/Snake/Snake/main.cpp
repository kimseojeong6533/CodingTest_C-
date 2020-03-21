#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX_SIZE 102
using namespace std;

int N;  // N : 2 ~ 100(보드의 크기)
int K; //사과의 개수 (0 ~ 100)
int L;
int dx[] = { 1,0,-1,0 };  //우-아래-왼-위
int dy[] = { 0,1,0,-1 };
int map[MAX_SIZE][MAX_SIZE] = { 0, };
queue< pair <int, string> > q;
queue <int> direcq;
queue< pair <int, int> > flag;




int make_snake(int x, int y) {  //뱀은 (1,1)에서 시작
	
	int sec=0;  //리턴값, 게임이 끝날때까지의 초
	int tail_x = x;
	int tail_y = y;   //뱀의 꼬리 인덱스

	int direc = 0;  //뱀의 머리의 dx,dy 배열의 인덱스
	int direc_tail=direc;  //뱀의 꼬리의 dx,dy 인덱스
	direcq.push(direc);    //처음에 뱀의 머리의 방향 인덱스를 direcq에 넣는다.
	int flag_x,flag_y = 0;   //방향이 전환될때, 꼬리에게 알려주는 변수
	
	while (1)  //무한반복
	{
		x = x + dx[direc];  //x,y는 뱀의 머리 부분, 
		y = y + dy[direc];

		sec++;

		if (map[y][x] == -2 || map[y][x] == 1)					  // map[][]==-2(벽) or 1(뱀)이라면 함수종료, 
			return sec;
		
		if (map[y][x] == -1)  //사과가 있다면, 
		{
			map[y][x] = 1;    //지나가... 뱀이니까.... 지나가는 거지.....
			map[tail_y][tail_x] = 1;
			
		}
		else //사과가 없다면     //if(map[y][x]==0)
		{
			map[y][x] = 1;
			map[tail_y][tail_x] = 0;  //현재 꼬리는 0으로 지도에 표시하고
			
			if (flag.empty())
			{
				tail_x = tail_x + dx[direc_tail];   
				tail_y = tail_y + dy[direc_tail];

				map[tail_y][tail_x] = 1;      //다음칸을 뱀(1)으로 설정
			}
			else
			{
				if (tail_x == flag.front().first && tail_y == flag.front().second)  //신호 x,y값이 꼬리인덱스와 같아지면, 꼬리의 방향인덱스는 direc과 같아짐
				{
					direcq.pop();
					direc_tail = direcq.front();
					flag.pop();
				}
				tail_x = tail_x + dx[direc_tail];   //꼬리인덱스는 다음 칸으로 넘어가서
				tail_y = tail_y + dy[direc_tail];

				map[tail_y][tail_x] = 1;      //다음칸을 뱀(1)으로 설정 
			}
		}
		
		if (!q.empty())
		{
			if (q.front().first == sec)  //방향정보 벡터에 있는 값과 sec이 같을 경우, 방향전환
			{

				flag_x = x;
				flag_y = y;
				flag.push(make_pair(flag_x, flag_y));  //flag x,y변수를 flag큐에 넣음
				//방향전환
				if (q.front().second == "D")  //오른쪽일 경우
				{
					direc++;
					if (direc >= 4)
						direc = 0;

					direcq.push(direc);  //꼬리가 참고하기 위해서 direcq에 넣어준다.
					q.pop();
				}
				else  //왼쪽일 경우
				{
					direc--;
					if (direc < 0)
						direc = 3;

					direcq.push(direc);
					q.pop();
				}
			}
		}
		/*
		for (int i = 0; i < N + 2; i++)
		{
			for (int j = 0; j < N + 2; j++)
			{
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		cout << sec << endl;
		cout << endl;*/
	}




	  //처음시작할때, 뱀의 위치는 (1,1)에서 시작함 ---1로 표기

	//뱀을 움직이기 시작



	//방향전환 (v의 첫번째 값과 sec이 같을 경우, v의 두번째 값대로 방향전환)  

}


int main(void)
{
	cin >> N;
	cin >> K;
	int k1, k2;
	
	for (int i = 0; i < K; i++)   //사과의 위치를 입력받음
	{
		cin >> k1 >> k2;
		map[k1][k2] = -1;  //사과의 위치는 1로 표시

	}

	for (int i = 0; i < N + 1; i++)
	{
		map[0][i] = -2;
		map[i][0] = -2;
		map[N + 1][i] = -2;
		map[i][N + 1] = -2;   //map에 벽표시 (-2)
	}

	cin >> L;  // L : 방향변환횟수 
	int L1;
	string L2;
	for (int i = 0; i < L; i++)  // L1초뒤에 L2(L : left, D : Right)방향으로 회전시키는 것을 입력받아 벡터pair에 넣음 
	{
		cin >> L1 >> L2;
		q.push(make_pair(L1,L2));
	}
	/*
	for (int i = 0; i < N+2; i++)
	{
		for (int j = 0; j < N+2; j++)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	*/


	int result=make_snake(1,1);
	cout << result << endl;

	/*system("pause");*/
	return 0;
}