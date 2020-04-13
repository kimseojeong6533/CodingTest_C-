#include <iostream>
using namespace std;
#define Max 32
//관련있는 변수들을 모아서 하나의 새로운 타입을 만들어 주는 기능 : 구조체
//형태 : typedef Struct{}구조체이름;

typedef struct{
	int inum;  //학번
	char strname[Max];
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}_tagStudent;  //학생 구조체 생성


int main(void) {

	_tagStudent tStudent= {};  //초기화됨.
	//구조체 멤버에 접근할때는 .을 사용
	
	//문자열을 배열에 넣을 때에는 단순대입(strname="가나다")으로는 불가
	//strcpy_s라는 함수를 이용해서 문자열을 복사해 주어야 함

	strcpy_s(tStudent.strname, "가나다라");
	cout << tStudent.strname << endl;
	system("pause");
	return 0;
}