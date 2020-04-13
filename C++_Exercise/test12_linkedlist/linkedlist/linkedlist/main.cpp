#include <iostream>
using namespace std;
#define NAME_SIZE 32


enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

typedef struct {
	char strname[NAME_SIZE];
	int inumber;
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}STUDENT, *PSTUDENT;

/*
링크드리스트 : 자료구조의 한 종류, 자료구조랑 데이터를 관리하는 방법중 하나, 
데이터목록을 연결시켜서 접근할 수 있는 구조를 제공함, 데이터를 저장하기위한 노드라는 것이 존재. 
각 노드의 특징은 다음노드를 알 수 있게 한다. (현재 노드는 다음노드의 메모리주소를 저장함)
리스트는 선형구조로 되어 있어서 배열처럼 특정요소에 바로 접근이 불가함. -> 무조건 앞에서부터 차례대로 타고 들어가야함
노드를 새로 추가할 때는 노드를 생성하고 마지막 노드에 연결만 해주면 되기때문에, 개수의 제한이 없다. 
*/

typedef struct _tagNode{   //_tagNode라는 이름을 가진 노드구조체를 생성, 노드는 '데이터'와 '다음노드'로 구성되어 있음, 
						   //여기에서 데이터는 tStudent라는 구조체이고, 다음노드는 pnext라는 tag_node타입의 노드 포인터 변수임
	STUDENT tStudent;
	_tagNode* pNext;
}NODE, *PNODE;   //_tagNode구조체의 별칭을 NODE라고 선언, _tagNode구조체의 포인터변수 별칭을 PNODE를 생성

typedef struct _tagList {  //리스트구조체를 만듦
	PNODE pBegin;     //노드구조체의 포인터변수별칭인 PNODE를 이용하여 pBegin,pEnd이라는 노드변수를 생성
	PNODE pEnd;       
	int iSize;

}LIST, *PLIST;   //_tagList라는 구조체의 별칭을 LIST, 그 포인터변수의 별칭을 PLIST라 선언.


void InitList(PLIST pList) { //리스트구조체 초기화하는 함수

	pList->pBegin = NULL; //포인터는 가급적이면 초기화할때 null로 초기화하는 것이 좋음(초기화하지 않을경우, 쓰레기값
	pList->pEnd = NULL;					  //이 들어가게 되는데 이 쓰레기값도 TRUE를 나타나게 됨. 
	pList->iSize = 0;

}

int Inputint() {        //숫자를 입력하는 함수
	int iInput;
	cin >> iInput;
	if (cin.fail()) { //입력실패시
		cin.clear();  //cin의 입력버퍼를 지워줌 
		cin.ignore(1024, '\n');
		return -1;
	}
	return iInput;
}

int OutputMenu() {
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요 : " << endl;
	int iInput;
	iInput=Inputint();  //메뉴번호를 입력(숫자를 입력하는 함수인 Inputint()이용)
	if (iInput <= 0 || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}

void InputString(char* pString, int iSize) {  //학생정보를 입력하는 함수
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1); 
}


void Insert(PLIST pList) {  //학생정보를 추가(삽입)하는 함수(Menu 1번)
	STUDENT tStudent = {};
	system("cls");
	cout << "============학생추가============="<<endl;
	cout << "학번 : ";
	tStudent.inumber = Inputint();
	cout << "이름 : ";
	InputString(tStudent.strname, NAME_SIZE);
	cout << "국어 : ";
	tStudent.ikor = Inputint();
	cout << "영어 : ";
	tStudent.ieng = Inputint();
	cout << "수학 : ";
	tStudent.imath = Inputint();
	
	tStudent.itotal = tStudent.ikor + tStudent.ieng + tStudent.imath;
	tStudent.favg = (tStudent.itotal / 3.f);

	//추가할 리스트노드를 생성함
	//현재 추가하는 노드는 리스트의 가장 마지막 노드이므로, 다음노드가 존재하지 않음
	//따라서, 동적할당으로 생성한 노드의 다음 노드(pNext)를 가리키는 변수는 NULL로 초기화해주고
	//생성한 노드의 데이터변수인 tStudent에는 방금 입력한 tStudent데이터들을 넣어준다
	PNODE pNode = new NODE;
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL) {
		pList->pBegin = pNode;
	}
	else {
		pList->pEnd->pNext = pNode;  //현재, 리스트의 끝노드의 다음노드를 생성한 노드로 설정해준다.
	}
	pList->pEnd = pNode; //이후, 리스트의 끝노드를 방금 생성한 노드로 설정해줌.
	++pList->iSize;
	
}

void ClearList(PLIST pList) {  //리스트의 메모리해제 
	PNODE pNode = pList->pBegin; //pbegin이 가리키는 노드를 pNode변수에 저장.
	while (pNode!=NULL) {
		PNODE pNext = pNode->pNext; //1. pBegin이 가리키는 노드의 다음 노드를 pNext에 저장
		delete pNode;               //2. pBegin이 가리키는 노드를 메모리해제
		pNode = pNext;              //3. pNode에 1.에서 저장했던 노드를 저장
		                            //4. 1~3.반복(pNode가 NULL이 될때까지)
	}
	pList->pBegin = NULL;  //리스트의 모든 노드가 메모리해제되면, 리스트의 pBegin, pEnd값은 Null로, iSize값은 0으로 설정해줌.
	pList->pEnd = NULL;
	pList->iSize = 0;
}

void OutputStudent(const PSTUDENT pStudent) {  //포인터로 인자를 넘겨받는 것이 더 효율적임(포인터는 무조건 4byte이므로)
	cout << "학번 : ";                         //값을 변경하면 안되니까 const로 설정해준다.
	cout << pStudent->inumber << endl;
	cout << "이름 : ";
	cout << pStudent->strname << endl;
	cout << "국어 : ";
	cout << pStudent->ikor << endl;
	cout << "영어 : ";
	cout << pStudent->ieng << endl;
	cout << "수학 : ";
	cout << pStudent->imath << endl;
	cout << "총점 : ";
	cout << pStudent->itotal << endl;
	cout << "평균 : ";
	cout << pStudent->favg << endl;
}


void Output(PLIST pList) {
	int i = 0;
	PNODE pNode = pList->pBegin;
	system("cls");
	cout << "============학생출력=============" << endl;
	while (pNode != NULL) {
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;  //다음노드를 pNode에 저장하여 리스트모두 출력할 수 있도록 해줌.
	}
	cout << "학생수 : " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList) {
	system("cls");
	cout << "============학생탐색=============" << endl;
	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};  
	InputString(strName, NAME_SIZE); //strName이라는 지역변수에 탐색할 이름을 넣음
	PNODE pNode = pList->pBegin; //구조체의 첫번째 노드부터 탐색시작
	while (pNode != NULL) {  
		if (strcmp(pNode->tStudent.strname, strName)==0) { //strcmp로 노드의 strname변수와 탐색할 이름을 넣은 지역변수인 strName을 비교
			OutputStudent(&pNode->tStudent); //탐색성공하면 해당 노드의 Student구조체의 데이터들을 출력함.
			system("pause");
			return;
		}
		pNode = pNode->pNext; //다음노드를 검색

	}
	cout << "탐색한 이름이 없습니다" << endl; //while문을 빠져나오면 탐색한 이름이 없다는 의미이므로 출력해줌.
	system("pause");


}

void Delete(PLIST pList) {
	system("cls");
	cout << "============학생삭제=============" << endl;
	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE); //strName이라는 지역변수에 탐색할 이름을 넣음

	PNODE pNode = pList->pBegin;  //노드는 리스트의 첫번째 노드부터 탐색시작 
	PNODE pPrev = NULL;    //현재 노드가 리스트의 첫번째 노드이므로, 이전노드를 의미하는 pPrev변수는 NULL값이 들어감
	while (pNode != NULL) { //리스트의 노드 끝까지 반복
		if (strcmp(pNode->tStudent.strname, strName) == 0) { //삭제할이름을 찾으면
			PNODE pNext = pNode->pNext; //pNext라는 PNODE형변수에 현재 노드의 다음노드를 넣어줌.
			if (pPrev == NULL) {  //만약, 삭제할 이름의 노드가 첫번째 노드여서 pPrev값이 NULL이라면
				delete pNode;   //찾은 이름의 노드를 삭제
				pList->pBegin = pNext;  //리스트의 pBegin값을 pNext라고 설정해줌.
				if (pNext == NULL) { //다음노드가 없을 경우,(예를들어서 리스트에 노드가 하나만 있는데 그 하나의 노드를 삭제할 경우)
					pList->pEnd = NULL;  //pEnd값을 NULL로 설정해줌.
				}
			}
			else {  //이전노드가 있을 경우 (이전노드의 다음을 지운노드의 다음으로 연결해줌)
				delete pNode;
				pPrev->pNext = pNext;
				if (pNext==NULL) {//삭제할 노드가 리스트의 pEnd일 경우
					pList->pEnd = pPrev;
				}
			}
			cout << strName << "학생 삭제완료!" << endl;
			--pList->iSize;
			system("pause");
			return;
		}
		pPrev = pNode;
		pNode = pNode->pNext;  //pPrev는 현재 노드가, 현재노드는 다음노드가 들어가고 계속 반복
		
	}
	cout << "삭제할 학생을 찾을 수 없습니다" << endl;
	system("pause");

}

int main(void) {

	LIST tList;
	InitList(&tList); //리스트 초기화 
	while (true) {
		int iMenu = OutputMenu(); //입력한 메뉴값이 들어있는 OutputMenu()값을 iMenu변수에 넣어줌
		if (iMenu == MM_EXIT)
			break;
		switch (iMenu) {

		case MM_INSERT:
			Insert(&tList);
			break;

		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		}

	}

	return 0;
}