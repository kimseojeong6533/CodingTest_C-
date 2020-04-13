#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node{
	int index;
	Node* next;
}Node;

Node** a;
int n, m, c[MAX_SIZE];  //n : ��������, m : ��������

void addFront(Node *root, int index)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {  //x�� �ε�������
	if (c[x]==1)  // x�ε����� �迭c���� 1(�湮��)�̶��, �ٷ� ����
		return;
	c[x] = 1; //�湮���� ����(x�ε����� �迭c���� 1�� �ƴ�)���¿��ٸ� ���� 1�� �־� �湮������ ó������
	printf("%d\n", x);
	Node *cur = a[x]->next;
	while (cur != NULL)
	{
		int next = cur->index;
		dfs(next);
		cur = cur->next;
	}

	

}

int main() {

	scanf("%d %d", &n, &m);

	a = (Node**)malloc(sizeof(Node)*(MAX_SIZE)); //a������ �����Լ��� ��帮��Ʈ�̹Ƿ� �����Ҵ��Ͽ� �ʱ�ȭ
	//����Ʈ a�� �� ��� ��, ��带 �����Ҵ��Ͽ� �ʱ�ȭ, �׸��� �� ������ ������ NULL�� �Ͽ� ���� �����ϵ�, ������ �ȵ��ִ� ���·� �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}

	for (int i = 0; i < m; i++)
	{

	}

	return 0;
}