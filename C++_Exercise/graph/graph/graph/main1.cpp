#include <stdio.h>
#include <stdlib.h>

//��������Ʈ : V���� ��忡 ���� ������ŭ ���Ұ� ��������Ƿ�, O(E)��ŭ�� �޸�(����)�� ����(�������⵵), 
//             ����� ó������ �о���Ƿ�, O(V)�� �ð����⵵�� ����
//������ ���� V^2�� ���� �ξ� ���� -> ��������Ʈ �̿�
typedef struct Node{
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

void showAll(Node *root)
{
	Node *cur = root->next;
	while (cur != NULL)
	{
		printf("%d(�Ÿ�) : %d",cur->index,cur->distance);
		cur = cur->next;
	}
}

int main() {

	int n, m;  //n�� ������ ����, m�� ������ ����
	scanf_s("%d %d", &n, &m);

	//a����Ʈ �ʱ�ȭ
	Node** a = (Node**)malloc(sizeof(Node*)*(n + 1)); //a�� Node n+1(�ε����� 1���� �����ϹǷ�)���� ������ ������ ��, ����Ʈ
	for (int i = 1; i <= n; i++)  
	{
		a[i] = (Node*)malloc(sizeof(Node)); //����Ʈ�� �� ��ҵ��� Node�� ������
		a[i]->next = NULL; //����� �������� Null�� �����Ͽ� �� ��尡 �����ǵ�, ������ �ȵ��ִ� ����
	}
	
	//������ ������ŭ �ݺ��ؼ� ������ x,y,distance���� �Է�����
	for (int i = 1; i <= m; i++)  
	{
		int x, y, distance;
		scanf_s("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance); //x��° ���, �ε��� y, distance�� �Էµ�. (x:��߳��,y:�������, x->y)
	}
	
	//�� ���(i=1~n)�� ����� �ε����� distance���� ��µ�.
	for (int i = 1; i <= n; i++)
	{
		printf("���� [%d] : ", i); 
		showAll(a[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}