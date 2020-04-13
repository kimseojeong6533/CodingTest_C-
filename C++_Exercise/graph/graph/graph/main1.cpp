#include <stdio.h>
#include <stdlib.h>

//인접리스트 : V개의 노드에 실제 간선만큼 원소가 들어있으므로, O(E)만큼의 메모리(공간)를 차지(공간복잡도), 
//             노드의 처음부터 읽어나가므로, O(V)의 시간복잡도를 지님
//간선의 수가 V^2에 비해 훨씬 적다 -> 인접리스트 이용
typedef struct Node{
	int index;   
	int distance;  //가중치
	struct Node *next;  //연결리스트이므로 다음노드를 가리키는 요소를 추가함
}Node;

void addFront(Node *root, int index, int distance)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

void showAll(Node *root)
{
	Node *cur = root->next;
	while (cur != NULL)
	{
		printf("%d(거리) : %d",cur->index,cur->distance);
		cur = cur->next;
	}
}

int main() {

	int n, m;  //n은 정점의 개수, m은 간선의 개수
	scanf_s("%d %d", &n, &m);

	//a리스트 초기화
	Node** a = (Node**)malloc(sizeof(Node*)*(n + 1)); //a는 Node n+1(인덱스가 1부터 시작하므로)개로 구성된 노드모임 즉, 리스트
	for (int i = 1; i <= n; i++)  
	{
		a[i] = (Node*)malloc(sizeof(Node)); //리스트의 각 요소들은 Node로 구성됨
		a[i]->next = NULL; //노드의 다음노드는 Null로 설정하여 각 노드가 생성되되, 연결은 안되있는 상태
	}
	
	//간선의 개수만큼 반복해서 간선의 x,y,distance값을 입력해줌
	for (int i = 1; i <= m; i++)  
	{
		int x, y, distance;
		scanf_s("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance); //x번째 노드, 인덱스 y, distance가 입력됨. (x:출발노드,y:도착노드, x->y)
	}
	
	//각 노드(i=1~n)가 연결된 인덱스와 distance값이 출력됨.
	for (int i = 1; i <= n; i++)
	{
		printf("원소 [%d] : ", i); 
		showAll(a[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}