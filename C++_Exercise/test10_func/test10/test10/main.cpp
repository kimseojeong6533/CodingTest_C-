#include <iostream>
using namespace std;
int g_num;
int Sum(int a, int b) {
	//이함수의 반환타입에 맞는 값을 반환.(int Sum이므로, int 값으로 반환), 이런형태를 Call by Value라고 함
	return a + b;
}

void OutputText() {

	//함수의 반환형이 void이므로 반환값이 굳이 없어도 된다. 
	cout << "test" << endl;
}
void ChangeNum(int a) {
	a = 1111;
}

//Call by Address함수 (포인터를 인자로 사용한 함수 ) 
void ChangeNumber(int* pNumber) { /*함수의 오버로딩 : 같은 이름의 함수지만, 인자가 다르거나 기능이 다른 함수
  오버로딩의 조건 : 무조건 함수의 이름이 같아야함., 인자의 개수 또는 타입이 달라서 오버로딩이 성립., 반환값은 영향x
*/

	*pNumber = 25;
}


//함수의 디폴트인자 : 인자는 기본적으로 값을 넘겨받음, 그런데 인자에 값을 넘겨주지 않을 경우, 대입해두었던 기본값이 
//인자로 들어간다.

void Output(int inum1, int inum2 = 10) { //inum2에 기본값이 설정되어 있음

	cout << inum1 << inum2 << endl;
	
}




int main(void) {

	cout << Sum(10, 20) << endl;  //결과 : 30
	OutputText();  //()까지 써야 함수가 호출된다. 
	int num = 10;   //지역변수 num -> 메모리영역중, stack영역에 할당됨.
	
	cout << num << endl;  //지역변수
	
	cout << g_num << endl;  //전역변수
	ChangeNum(num);
	ChangeNumber(&num);  //지역변수 num을 이용하였지만, 포인터를 인자로 사용하는 함수를 사용하여 값이 바뀌게 됨
	                     // 함수의 오버로딩(인자가 다르므로)
	cout << num << endl;  //결과 25


	cout << "==============" << endl;
	Output(10, 40);  //10과 40이 출력
	Output(10); //10과 10(기본값)이 출력 
	

	system("pause");
	return 0;
}