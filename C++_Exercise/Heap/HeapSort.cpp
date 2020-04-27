#include <iostream>

using namespace std;

int number =9;
int heap[9]={7,6,5,8,3,5,9,1,6};



int main(void)
{
	//�ִ��������  (�θ��尡 �ڽĳ��麸�� ���� ū ����, ����Ĺ��, O(logN)) 
	for(int i=1;i<number;i++)	
	{
		int c=i;
		do{
			int root=(c-1)/2;  //root : c�ε����� ��尪�� �θ����ε��� 
			if(heap[root]<heap[c])
			{
				//�θ����� ���� �ڽĳ���� ���� ���Ͽ� �θ����� ���� �� �۴ٸ�, �ڽĳ���� ���� �θ����� ���� ��ȯ
				int temp=heap[root];
				heap[root]=heap[c];
				heap[c]=temp; 
			}
			c=root; //�ڽ��� �θ����, �θ����� �θ���� ���� (c�� ��Ʈ���� �������� �ݺ�) 
		}while(c!=0);
	}
	
	for(int i=0;i<number;i++)
	{
		printf("%d ",heap[i]);	
	} 
	
	//�ִ����� ���, ��Ʈ��尡 Ʈ������ ���� ū���� �� ������, ������������ �����ϱ����ؼ��� ��Ʈ��尪�� �Ǹ����� �ε����� ���� ��ȯ�Ͽ� ���� �������־����.
	for(int i=number-1;i>=0;i--)  
	{
		//��Ʈ��尪�� �Ǹ����� �ε���(�ڽĳ��)���� ��ȯ�� 
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp; 	
		
		//�������� ��������� ������. 
		int root=0;  //�θ����� �ε��� 
		int c=1;  
		do{
			c=2*root+1; //c: root�� �ڽĳ�� �ε���
			if(heap[c]<heap[c+1] && c<i-1)  //�ڽ��߿� �� ū���� ã��, ������ ����� ���� ������ ��ȯ�ѵ� �����̹Ƿ�, i-1����.   
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
	printf("\n�������� : \n");  //logN * N/2 => O(NlogN)
	for(int i=0;i<number;i++)
	{
		printf("%d ",heap[i]);	
	}
	return 0;
}
