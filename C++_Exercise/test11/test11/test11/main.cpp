#include <iostream>

using namespace std;

int main(void) {

	//동적할당을 하면 메모리의 heap영역에 메모리할당이 됌(메모리해제 전까지는 계속 남아있음 -> 할당후, 메모리를 해제하지 않으몀ㄴ
	//메모리공간이 계속 잡혀있게 됨. 이 공간은 다른 곳에서 사용이 불가능함 : 메모리 누수(leak)) 
	/*
	etc) 지역변수->스택영역, 정적변수(static), 전역변수(global) -> 데이터영역 
	*/
	//c++ : new + 할당할 타입/ c: malloc,calloc등 ->둘다 메모리의 주소를 반환함.
	int *num = new int; //(new뒤에 int의 크기만큼 공간을 할당함(4byte), 그리고 할당한 공간의 메모리주소를 num에 넣어줌)
	cout << num << endl;  // 할당된 메모리주소를 가진 *num(포인터변수)이 출력됨. (출력된것은 할당된 공간)
	delete(num);  //c++에서는 delete()로 동적할당한 메모리를 해제할 수 있음. 


	/*
	동적배열 할당 형태 :  new 타입[개수], 배열자체가 포인터 
	
	*/
	int *arr = new int[100];  //메모리공간에 400바이트 만큼의 공간을 할당하고 arr배열에 그 주소를 넣어준다.

	arr[0] = 300;
	cout << arr << endl;
	delete[] arr;  //동적배열을 지울때에는 detle[] 변수명으로 씀
	system("pause");
	return 0;
}