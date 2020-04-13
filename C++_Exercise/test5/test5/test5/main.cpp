#include <iostream>
using namespace std;

/*열거체 : 연속된 숫자에 이름을 부여하는 기능
	형태 : enum 열거체명 {}
	열거체명을 이용해서 열거체타입의 변수선언도 가능하다.
	즉, 열거체를 사용자정의 변수타입이 될수도 있다. (사용자가 변수타입을 지정가능)
	*/

enum NUM {
	NUM_0,  //아무 값도 넣지 않으면 0부터 1씩 증가하여 차례대로 변수에 저장됨다. -> Switch문의 case 뒤에 활용하는 용도로 주로 쓰임.
	NUM_1,
	NUM_2,
	NUM_3
};

#define Max 1000


int main(void) {

	/*switch문 : 값이 무엇인지 체크하는 것 
	
	*/
	int iNum;
	cout << "숫자를 입력 : ";
	cin >> iNum;

	switch (iNum) {
	case NUM_0: 
		cout << "입력한 숫자는 0입니다" << endl;
		break;
	case NUM_1:
		cout << "입력한 숫자는 1입니다" << endl;
		break;
	case NUM_2:
		cout << "입력한 숫자는 2입니다" << endl;
		break;
	default: //case로 지정되어 있지 않는 숫자가 실행됨
		cout << "그외의 숫자입니다" << endl;
		break;
	}
	NUM eNum=(NUM)1;  //열거체 타입의 변수는 무조건 4byte를 차지함. , 열거체를 이용해서 선언한 변수는 값의 표현범위가 열거체에 나열된 값들 안에서 선택됨.
	cout << sizeof(eNum) << endl;  //결과는 4  //변수의 크기 또는 메모리크기를 알려주는 함수 : sizeof
	cout << typeid(NUM).name() << endl;  //결과는  enum NUM, 변수의 타입을 문자열로 반환해주는 함수 : typeid


	system("pause");
	return 0;
}