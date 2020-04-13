#include <iostream>

using namespace std;
#define namesize 32
#define STUDENT_MAX	10  //최대 학생목록명수 지정
#define ADDRESSSIZE 128 //학생정보중, 최대 주소사이즈의 크기 지정
#define PHONE_SIZE 14 //학생정보중, 전화번호사이즈 크기 지정 

typedef struct {
	char strname[namesize];
	char straddress[ADDRESSSIZE];
	char strphone[PHONE_SIZE];
	int inum;
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}_tagStudent;

enum Menu {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main(void) {
	_tagStudent tStudetnArr[STUDENT_MAX] = {};  //0으로 구조체의 모든 변수를 초기화
	char strname[namesize] = {};
	int iStudentcount = 0;
	int iStudentnum = 1;  //학번은 1번부터 시작

	while (1) {
		system("cls");

		//메뉴를 출력함
		cout << "1. 학생등록 " << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		
			
		cin >> iMenu;  //메뉴 입력(scanf)  /*원래 입력해야할 값은 정수형인데, 실수로 문자를 입력했다면? 예외처리필요*/

		if (cin.fail()) {  //cin.fail을 사용하면 cin에 입력에러가 발생했을 경우, true가 반환되어 조건문이 발현됨
			//에러버퍼를 비운다
			cin.clear();
			//cin.ignore(검색하고자하는 버퍼의 크기를 지정, '\n') 이때, \n은 개행문자로 \n이 있는 곳까지 읽고 버림
			cin.ignore(1024, '\n');
			continue;  //while(1)문안에서 돌고돌게됨 즉, 다시 cin을 입력받게 함
		}
			
				//
		
		
		
		if (iMenu == MENU_EXIT) {
			break;
		}
		switch (iMenu) {
		case MENU_INSERT:      //학생정보로 학번,이름, 주소,전화번호가 등록됨.
			if (iStudentcount == STUDENT_MAX)  //등록된 학생수가 최대 등록학생수와 같으면 등록을 그만하도록 처리
				break;
			system("cls");
			cout << "====================" << endl;
			cout << "이름 : ";
			cin >> tStudetnArr[iStudentcount].strname;
			  //이름을 입력할때 들어간 엔터(\n)를 입력버퍼에서 삭제처리해줌
			cin.ignore(1024, '\n');
			cout << "주소 ; ";
			cin.getline(tStudetnArr[iStudentcount].straddress,ADDRESSSIZE);  //cin을 이용하면, 스페이스바(띄어쓰기)도 문자의 끝으로 인식하게됨
																 //따라서, cin.getline을 이용하여 띄어쓰기도 포함하여 문자열에 들어가도록 해줌
			cout << "전화번호 : ";
			cin.getline(tStudetnArr[iStudentcount].strphone, PHONE_SIZE);
			
			cout << "국어점수 : ";
			cin >> tStudetnArr[iStudentcount].ikor;

			cout << "영어점수 : ";
			cin >> tStudetnArr[iStudentcount].ieng;
			
			cout << "수학점수 : ";
			cin >> tStudetnArr[iStudentcount].imath;

			tStudetnArr[iStudentcount].itotal = tStudetnArr[iStudentcount].ikor +
											    tStudetnArr[iStudentcount].ieng +
												tStudetnArr[iStudentcount].imath;

			tStudetnArr[iStudentcount].favg = (tStudetnArr[iStudentcount].ikor +
											   tStudetnArr[iStudentcount].ieng +
											   tStudetnArr[iStudentcount].imath)/3.f;
			++iStudentcount;
			++iStudentnum;
			break;

		case MENU_DELETE:
			system("cls");
			cout << "삭제할 이름을 입력하세요 : ";
			cin.getline(strname, namesize);

			//등록되어 있는 학생수만큼 반복하여 학생을 찾는다
			for (int i = 0; i < iStudentcount; ++i) {
				if (strcmp(tStudetnArr[i].strname, strname) == 0) //학생을 찾았을 경우 strcmp(문자열, 문자열), 문자열끼리 같으면 0을 반환
				{
					for (int j = i; j < iStudentcount - 1; ++j) {
						tStudetnArr[j] = tStudetnArr[j + 1];
					}
					--iStudentcount;
					cout << "학생을 삭제하였습니다" << endl;
					break;
					
				}
			}
			cout << "찾는 학생이 목록에 없습니다" << endl;	
			break;

		case MENU_SEARCH:
			system("cls");
			cout << "==========학생탐색=========" << endl;
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 검색하세요 : ";
			cin.getline(strname, namesize);
			
			//등록되어 있는 학생수만큼 반복하여 학생을 찾는다
			for (int i = 0; i < iStudentcount; ++i) {
				if (strcmp(tStudetnArr[i].strname, strname) == 0) //학생을 찾았을 경우 strcmp(문자열, 문자열), 문자열끼리 같으면 0을 반환
				{
					cout << "이름 : ";
					cout << tStudetnArr[i].strname << endl;
					cout << "주소 ; ";
					cout << tStudetnArr[i].straddress << endl;
					cout << "전화번호 : ";
					cout << tStudetnArr[i].strphone << endl;
					cout << "국어점수 : ";
					cout << tStudetnArr[i].ikor << endl;
					cout << "영어점수 : ";
					cout << tStudetnArr[i].ieng << endl;

					cout << "수학점수 : ";
					cout << tStudetnArr[i].imath << endl;

					cout << "총점 : ";
					cout << tStudetnArr[i].itotal << endl;
					cout << "평균 : ";
					cout << tStudetnArr[i].favg << endl;
					break;
				}
				if(i==iStudentcount-1)
				{	
					cout << "찾는 학생이 목록에 없습니다" << endl;
					break;
				}
				
			}
			
			break;

		case MENU_OUTPUT:
			system("cls");
			cout << "=========학생출력=========" << endl;
			//등록된 학생수만큼 반복
			for (int i = 0; i < iStudentcount; ++i) {
				cout << "이름 : ";
				cout << tStudetnArr[i].strname << endl;
				cout << "주소 ; ";
				cout << tStudetnArr[i].straddress << endl;
				cout << "전화번호 : ";
				cout << tStudetnArr[i].strphone << endl;
				cout << "국어점수 : ";
				cout << tStudetnArr[i].ikor << endl;
				cout << "영어점수 : ";
				cout << tStudetnArr[i].ieng << endl;

				cout << "수학점수 : ";
				cout << tStudetnArr[i].imath << endl;

				cout << "총점 : ";
				cout << tStudetnArr[i].itotal << endl;
				cout << "평균 : ";
				cout << tStudetnArr[i].favg << endl;
			}
			break;
		default : 
			cout << "메뉴를 잘못입력하였습니다" << endl;
			break;
		}
		system("pause");  //
	}


	return 0;
}