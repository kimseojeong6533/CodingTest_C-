#include <iostream>

using namespace std;
int main() {

	std::cout << "Test Output" << std::endl;
	std::cout << "가나다라" << std::endl;

								 //C++표준기능의 대부분은 std라는 namespace안에 존재함. (이름중복을 방지하기위함)
								 //cout : console out, 콘솔창에 출력해주는 기능, 큰따옴표 안에 있는 문자들을 화면에 출력해줌
								 //endl = \n,즉, 개행의 역할(enter)을 함
	cout << "test2" << endl;
	int num = 229;
	cout << num << endl;

	bool btest;
	btest = false;
	cout << btest << endl;

	float fNumber = 3.14f;
	cout << fNumber << endl;
	double dNum = 3.14159;
	cout << dNum << endl;

	   //1바이트, 즉, 한글,한문-1문자당 2바이트/영문,숫자-1문자당 1바이트  차지 ->char 변수 하나에 저장하기 힘듦.(char-2바이트)
	
	/* 사칙연산자 */
	cout << "10 < 20 = " << (10 < 20) << endl; //printf("10 < 20 = %d",(10<20))과 같음
	int Num;
	cout << "숫자를 입력하세요 : ";
	cin >> Num;  //scanf(%d,&Num)과 같음
	cout << ((10 <= Num) && (10 <= 20)) << endl;
	cout << "87 & 54 = " << (87 & 53) << endl;

	
	
	system("pause");
	return 0;
}