#include <stdio.h>

int a[1001][1001];
int n, m;  //n�� ���, m�� ������ ����

int main(void) {

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) { //������ ������ŭ �Է¹���
		int x, y;
		scanf_s("%d %d", &x, &y); //����Ǿ� �ִ� ������ �Է� 
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
