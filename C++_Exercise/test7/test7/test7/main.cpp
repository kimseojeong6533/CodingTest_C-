#include <iostream>
using namespace std;

int main(void) {

	/*for문의 무한루프 : for(;;){} 
	
	*/
	/*
	for (int i = 0; i < 10; ++i) {
		cout << i << endl;
	}
	cout << "구구단2단" << endl;
	for (int i = 1; i < 10; ++i) {
		int num = 2 * i;
		cout << "2 * " <<i<< " = "<< num << endl;
	}*/

	//1~100사이의 숫자중 짝수만 출력하는 for문 작성
	/*for (int i = 2; i <= 100; i+=2) {
		cout << i << endl;
	}*/

	for (int i = 1; i < 100; ++i) {
		if (i%3==0 && i%7==0) {
			cout << i << endl;
		}
	}

	//중첩for문
	for (int i = 0; i <5; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("* ");
		}
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i < 5; ++i) {
		for (int j = 5; j > i; --j) {
			printf("* ");
		}
		printf("\n");
	}
	
	printf("\n");

	for (int i = 0; i < 5; ++i) {
		for(int j=4-1-i;j<=i+3-j;++j)
		printf("\n");
	}
	

	return 0;
}