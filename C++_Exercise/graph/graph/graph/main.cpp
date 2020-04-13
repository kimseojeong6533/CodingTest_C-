#include <stdio.h>

int a[1001][1001];
int n, m;  //n은 노드, m은 간선의 개수

int main(void) {

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) { //간선의 개수만큼 입력받음
		int x, y;
		scanf_s("%d %d", &x, &y); //연결되어 있는 점들을 입력 
		a[x][y] = 1;     
		a[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
