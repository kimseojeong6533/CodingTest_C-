#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node{
	int index;
	Node* next;
}Node;

Node** a;
int n, m, c[MAX_SIZE];  //n : 정점개수, m : 간선개수

void addFront(Node *root, int index)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {  //x는 인덱스변수
	if (c[x]==1)  // x인덱스의 배열c값이 1(방문함)이라면, 바로 리턴
		return;
	c[x] = 1; //방문하지 않음(x인덱스의 배열c값이 1이 아님)상태였다면 값에 1을 넣어 방문함으로 처리해줌
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

	a = (Node**)malloc(sizeof(Node)*(MAX_SIZE)); //a변수는 전역함수인 노드리스트이므로 동적할당하여 초기화
	//리스트 a의 각 요소 즉, 노드를 동적할당하여 초기화, 그리고 각 노드들의 연결을 NULL로 하여 노드는 생성하되, 연결은 안되있는 상태로 초기화
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