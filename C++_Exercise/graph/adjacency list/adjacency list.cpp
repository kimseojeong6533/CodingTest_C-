#include <stdio.h>
#include <stdlib.h>

typedef struct {
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

/*void showAll(Node *root)
{
	Node *cur = root->next;
}*/
