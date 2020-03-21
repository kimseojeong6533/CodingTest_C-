#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX_SIZE 102
using namespace std;

int N;  // N : 2 ~ 100(������ ũ��)
int K; //����� ���� (0 ~ 100)
int L;
int dx[] = { 1,0,-1,0 };  //��-�Ʒ�-��-��
int dy[] = { 0,1,0,-1 };
int map[MAX_SIZE][MAX_SIZE] = { 0, };
queue< pair <int, string> > q;
queue <int> direcq;
queue< pair <int, int> > flag;




int make_snake(int x, int y) {  //���� (1,1)���� ����
	
	int sec=0;  //���ϰ�, ������ ������������ ��
	int tail_x = x;
	int tail_y = y;   //���� ���� �ε���

	int direc = 0;  //���� �Ӹ��� dx,dy �迭�� �ε���
	int direc_tail=direc;  //���� ������ dx,dy �ε���
	direcq.push(direc);    //ó���� ���� �Ӹ��� ���� �ε����� direcq�� �ִ´�.
	int flag_x,flag_y = 0;   //������ ��ȯ�ɶ�, �������� �˷��ִ� ����
	
	while (1)  //���ѹݺ�
	{
		x = x + dx[direc];  //x,y�� ���� �Ӹ� �κ�, 
		y = y + dy[direc];

		sec++;

		if (map[y][x] == -2 || map[y][x] == 1)					  // map[][]==-2(��) or 1(��)�̶�� �Լ�����, 
			return sec;
		
		if (map[y][x] == -1)  //����� �ִٸ�, 
		{
			map[y][x] = 1;    //������... ���̴ϱ�.... �������� ����.....
			map[tail_y][tail_x] = 1;
			
		}
		else //����� ���ٸ�     //if(map[y][x]==0)
		{
			map[y][x] = 1;
			map[tail_y][tail_x] = 0;  //���� ������ 0���� ������ ǥ���ϰ�
			
			if (flag.empty())
			{
				tail_x = tail_x + dx[direc_tail];   
				tail_y = tail_y + dy[direc_tail];

				map[tail_y][tail_x] = 1;      //����ĭ�� ��(1)���� ����
			}
			else
			{
				if (tail_x == flag.front().first && tail_y == flag.front().second)  //��ȣ x,y���� �����ε����� ��������, ������ �����ε����� direc�� ������
				{
					direcq.pop();
					direc_tail = direcq.front();
					flag.pop();
				}
				tail_x = tail_x + dx[direc_tail];   //�����ε����� ���� ĭ���� �Ѿ��
				tail_y = tail_y + dy[direc_tail];

				map[tail_y][tail_x] = 1;      //����ĭ�� ��(1)���� ���� 
			}
		}
		
		if (!q.empty())
		{
			if (q.front().first == sec)  //�������� ���Ϳ� �ִ� ���� sec�� ���� ���, ������ȯ
			{

				flag_x = x;
				flag_y = y;
				flag.push(make_pair(flag_x, flag_y));  //flag x,y������ flagť�� ����
				//������ȯ
				if (q.front().second == "D")  //�������� ���
				{
					direc++;
					if (direc >= 4)
						direc = 0;

					direcq.push(direc);  //������ �����ϱ� ���ؼ� direcq�� �־��ش�.
					q.pop();
				}
				else  //������ ���
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




	  //ó�������Ҷ�, ���� ��ġ�� (1,1)���� ������ ---1�� ǥ��

	//���� �����̱� ����



	//������ȯ (v�� ù��° ���� sec�� ���� ���, v�� �ι�° ����� ������ȯ)  

}


int main(void)
{
	cin >> N;
	cin >> K;
	int k1, k2;
	
	for (int i = 0; i < K; i++)   //����� ��ġ�� �Է¹���
	{
		cin >> k1 >> k2;
		map[k1][k2] = -1;  //����� ��ġ�� 1�� ǥ��

	}

	for (int i = 0; i < N + 1; i++)
	{
		map[0][i] = -2;
		map[i][0] = -2;
		map[N + 1][i] = -2;
		map[i][N + 1] = -2;   //map�� ��ǥ�� (-2)
	}

	cin >> L;  // L : ���⺯ȯȽ�� 
	int L1;
	string L2;
	for (int i = 0; i < L; i++)  // L1�ʵڿ� L2(L : left, D : Right)�������� ȸ����Ű�� ���� �Է¹޾� ����pair�� ���� 
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