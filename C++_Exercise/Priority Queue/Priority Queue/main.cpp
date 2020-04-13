#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

typedef struct {
	int heap[MAX_SIZE];
	int count;   //heap�迭(�ִ�������)�� �����Ͱ�������, �ε�������
}priorityQueue;

void push(priorityQueue *pq, int data) //�����
{
	if (pq->count > MAX_SIZE)	
		return;

	pq->heap[pq->count] = data;   
	int now = pq->count;  //�����͸� ������ �ڸ��� �ε���
	int parent = (pq->count - 1) / 2;  //�����͸� ������ �ڸ��� �θ��� �ε���

	//��������� push, �� ������ �ε����� �����Ͱ� ������ �ε����� �θ����ε������� ũ�ٸ� ��ȯ�ϴ� ���
	while (now > 0 && pq->heap[now] > pq->heap[parent])  //now=0�϶�, �θ��尡 �������������Ƿ� >0ó���� ����
	{
		swap(&pq->heap[now], &pq->heap[parent]);  //�ڽĳ�尡 �θ��庸�� ���� ũ�ٸ� ��ȯ
		now = parent;  //������̹Ƿ� �����带 �θ����
		parent = (parent - 1) / 2;  //�θ��带 ����θ��� �θ����
	}
	pq->count++;
}

int pop(priorityQueue *pq) {
	if (pq->count <= 0)
		return _CRT_INT_MAX;

	int res = pq->heap[0]; //��Ʈ��带 res������ ���� (res������ ������ ��������, �ִ����̹Ƿ� �켱������ �������, ���⼭�� �����Ͱ��� ���� ���� ��尡 ������)
	pq->count--;              //count������ �����Ͱ������� �ε����̹Ƿ� -1�� ���־�� �������������� �ε����� ��
	pq->heap[0] = pq->heap[pq->count];   //���� ������ ���Ҹ� ��Ʈ��忡 ���� 
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;

	//�����(�ڽĳ��� �������鼭 ������� ���� ������ �ű�)
	while (leftChild < pq->count)  //�ڽĳ���� �ε����� count���� ���� ���ȿ� �ݺ�
	{
		if (pq->heap[target] < pq->heap[leftChild])  target = leftChild; //target�� leftChild���� ���Ͽ� �� ū���� target���� ��
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;  //target���� rightchild���� ���Ͽ� �� ū���� target���� ��
		if (target == now) break; //target���� �ڽĳ�尪�� �ƴҶ�, ��, �ڽĳ��� ������ ��, ���� ū���̱⶧���� ��ȯ�� �ʿ䰡 �����Ƿ� �ٷ� breakó��
		else {
			swap(&pq->heap[now], &pq->heap[target]);  //target���� 
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;

}

int main(void) {

	int n, data;
	scanf_s("%d", &n);
	priorityQueue pq;
	pq.count = 0;
	for (int i = 0; i< n; i++) {
		scanf_s("%d", &data);
		push(&pq, data);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", pq.heap[i]);
	}
	printf("\n");
	
	for (int i = 0; i < n; i++) {
		int data = pop(&pq);
		printf("%d ", data);

	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", pq.heap[i]);
	}

	return 0;
}


