#include <iostream>

using namespace std;

int main(void) {

	/*
	레퍼런스 :  다른대상을 참조하게 만들어주는 기능, 참조를 하게되면, 그 대상에 접근하여 값을 변경가능
	단, 레퍼런스는 처음 레퍼런스 변수생성시, 참조하는 대상을 지정해주어야 함.
	변수타입 &레퍼런스명 = 참조할변수명;

	
	*/

	int iNumber = 100;
	int iNumber1 = 9999;
	int &iRefNum = iNumber;  //iRevNum 레퍼런스 변수는 iNumber변수를 참조함
	
	iRefNum = 1234;
	iRefNum = iNumber1;    //iNumber1의 값인 9999를 iRefNum이 참조하는 iNumber값에 넣어버림 (iNumber=100 -> 9999)
	                       //참조한 처음변수의 값을 바꿈(참조의 대상을 바꾸는 것이 아님)
	cout << iNumber1 << endl;   //레퍼런스변수는 참조한 처음 변수의 메모리에 접근이아니라, 값에 접근하여 값을 제어함.
	cout << sizeof(iRefNum) << endl;  //결과 : 4 (레퍼런스변수)

	system("pause");
	return 0;
}