#include <iostream>

using namespace std;

int number =9;
int heap[9]={7,6,5,8,3,5,9,1,6};



int main(void)
{
	//최대힙만들기  (부모노드가 자식노드들보다 값이 큰 형태, 상향식방법, O(logN)) 
	for(int i=1;i<number;i++)	
	{
		int c=i;
		do{
			int root=(c-1)/2;  //root : c인덱스의 노드값의 부모노드인덱스 
			if(heap[root]<heap[c])
			{
				//부모노드의 값과 자식노드의 값을 비교하여 부모노드의 값이 더 작다면, 자식노드의 값과 부모노드의 값을 교환
				int temp=heap[root];
				heap[root]=heap[c];
				heap[c]=temp; 
			}
			c=root; //자식의 부모노드로, 부모노드의 부모노드로 향함 (c가 루트노드로 갈때까지 반복) 
		}while(c!=0);
	}
	
	for(int i=0;i<number;i++)
	{
		printf("%d ",heap[i]);	
	} 
	
	//최대힙의 경우, 루트노드가 트리에서 가장 큰값이 기 때문에, 오름차순으로 정렬하기위해서는 루트노드값과 맨마지막 인덱스의 값을 교환하여 힙을 구성해주어야함.
	for(int i=number-1;i>=0;i--)  
	{
		//루트노드값과 맨마지막 인덱스(자식노드)값을 교환함 
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp; 	
		
		//힙구조을 하향식으로 구성함. 
		int root=0;  //부모노드의 인덱스 
		int c=1;  
		do{
			c=2*root+1; //c: root의 자식노드 인덱스
			if(heap[c]<heap[c+1] && c<i-1)  //자식중에 더 큰값을 찾기, 마지막 노드의 값은 위에서 교환한뒤 고정이므로, i-1해줌.   
			{
				c++; //heap[c+1] 	
			}
			if(heap[root]<heap[c] && c<i)
			{
				int temp=heap[root];
				heap[root]=heap[c];
				heap[c]=temp; 	
			}
			root=c;  
		}while(c<i);
			
	}	 
	printf("\n힙정렬후 : \n");  //logN * N/2 => O(NlogN)
	for(int i=0;i<number;i++)
	{
		printf("%d ",heap[i]);	
	}
	return 0;
}
