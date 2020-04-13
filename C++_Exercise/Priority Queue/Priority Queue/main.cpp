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
	int count;   //heap배열(최대힙구조)의 데이터개수이자, 인덱스역할
}priorityQueue;

void push(priorityQueue *pq, int data) //상향식
{
	if (pq->count > MAX_SIZE)	
		return;

	pq->heap[pq->count] = data;   
	int now = pq->count;  //데이터를 삽입한 자리의 인덱스
	int parent = (pq->count - 1) / 2;  //데이터를 삽입한 자리의 부모노드 인덱스

	//상향식으로 push, 즉 삽입한 인덱스의 데이터가 삽인한 인덱스의 부모노드인덱스보다 크다면 교환하는 방식
	while (now > 0 && pq->heap[now] > pq->heap[parent])  //now=0일때, 부모노드가 존재하지않으므로 >0처리를 해줌
	{
		swap(&pq->heap[now], &pq->heap[parent]);  //자식노드가 부모노드보다 값이 크다면 교환
		now = parent;  //상향식이므로 현재노드를 부모노드로
		parent = (parent - 1) / 2;  //부모노드를 현재부모의 부모노드로
	}
	pq->count++;
}

int pop(priorityQueue *pq) {
	if (pq->count <= 0)
		return _CRT_INT_MAX;

	int res = pq->heap[0]; //루트노드를 res변수에 담음 (res변수는 삭제할 데이터임, 최대힙이므로 우선순위가 가장높은, 여기서는 데이터값이 가장 높은 노드가 삭제됨)
	pq->count--;              //count변수는 데이터개수이자 인덱스이므로 -1을 해주어야 마지막데이터의 인덱스가 됨
	pq->heap[0] = pq->heap[pq->count];   //가장 마지막 원소를 루트노드에 담음 
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;

	//하향식(자식노드로 내려가면서 가장높은 값을 윗노드로 옮김)
	while (leftChild < pq->count)  //자식노드의 인덱스가 count보다 작은 동안에 반복
	{
		if (pq->heap[target] < pq->heap[leftChild])  target = leftChild; //target과 leftChild값을 비교하여 더 큰값이 target값이 됨
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;  //target값과 rightchild값을 비교하여 더 큰값이 target값이 됨
		if (target == now) break; //target값이 자식노드값이 아닐때, 즉, 자식노드와 비교했을 때, 가장 큰값이기때문에 교환할 필요가 없으므로 바로 break처리
		else {
			swap(&pq->heap[now], &pq->heap[target]);  //target노드와 
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


