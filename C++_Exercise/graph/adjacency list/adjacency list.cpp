#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index;   
	int distance;  //����ġ
	struct Node *next;  //���Ḯ��Ʈ�̹Ƿ� ������带 ����Ű�� ��Ҹ� �߰���
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
