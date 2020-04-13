#include "List.h"
#include <algorithm>
using namespace std;
//함수를 정의하는 List.cpp파일



static int Inputint() {        //숫자를 입력하는 함수
	int iInput;
	cin >> iInput;
	if (cin.fail()) { //입력실패시
		cin.clear();  //cin의 입력버퍼를 지워줌 
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void InputString(char* pString, int iSize) {  //학생정보를 입력하는 함수
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

int OutputMenu() {
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 학생정렬" << endl;
	cout << "6. 종료" << endl;
	cout << "메뉴를 선택하세요 : " << endl;
	int iInput;
	iInput = Inputint();  //메뉴번호를 입력(숫자를 입력하는 함수인 Inputint()이용)
	if (iInput <= 0 || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}
void InitList(PLIST pList) { //리스트를 초기화하는 함수
	pList->iSize = 0;
	pList->pBegin = new NODE;  //노드구조체로 동적할당만 해놓는다(데이터가 없는 노드이므로)
	pList->pEnd = new NODE;	   //노드구조체로 동적할당만 해놓는다(데이터가 없는 노드이므로)
	pList->pBegin->pNext = pList->pEnd;  //pBegin과 pEnd가 서로 가르키도록 해준다.
	pList->pEnd->pPrev = pList->pBegin;
	pList->pEnd->pNext = NULL;  //pEnd의 다음노드는 없으므로 NULL처리
	pList->pBegin->pPrev = NULL; //pBegin의 이전노드는 없으므로 NULL처리
}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	while (pNode != NULL) {
		PNODE pNext = pNode->pNext; //pNext변수에 현재 노드의 다음 노드를 설정해줌
		delete pNode;  //현재 노드의 메모리해제
		pNode = pNext;  //pNode를 다음노드가 들어가있는 pNext변수로 설정해줌.
	}
	
	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;

}

/*void Push_Front()
{
	
}*/

void Push_Back(PLIST pList)
{
	STUDENT tStudent = {};
	system("cls");
	cout << "============학생추가=============" << endl;
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

	PNODE pNode = new NODE;  //새롭게 추가할 노드생성
	pNode->tStudent = tStudent;  //새롭게 추가한 노드의 데이터(학생정보)에는 방금 입력한 학생정보가 들어감
	PNODE pPrev= pList->pEnd->pPrev;  //pPrev노드변수는 현재 End노드의 이전노드로 설정한다.
	
	pPrev->pNext = pNode;  //pPrev변수의 다음노드는 새롭게 추가한 노드로 설정한다.
	pNode->pPrev = pPrev;  //새롭게 추가한 노드의 이전노드는 위의 pPrev노드변수(현재 end노드의 이전노드)로 설정한다

	pNode->pNext = pList->pEnd; //새롭게 추가한 노드의 다음노드를 pEnd에 설정한다
	pList->pEnd->pPrev = pNode;  //end노드의 이전노드를 새롭게 추가한 노드로 설정한다

	++pList->iSize;  //리스트숫자 증가

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

void Output(PLIST pList)
{
	int iMenu;
	while (1)
	{
		system("cls");
		cout << "============학생출력=============" << endl;
		cout << "메뉴를 선택하세요 : 1. 정방향출력    2. 역방향출력" << endl;
		iMenu = Inputint();  //숫자입력함수 이용

		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)  //1 또는 2를 입력할때까지 계속 메뉴가 나옴
			break;
	}

	PNODE pNode = NULL;
	switch (iMenu)
	{
		case OT_OUPUT:  //순방향출력
			pNode = pList->pBegin->pNext;  //begin의 다음노드부터 
			while (pNode != pList->pEnd)
			{
				OutputStudent(&pNode->tStudent);
				pNode = pNode->pNext;
			}
			break;

		case OT_INVERSE:
			pNode = pList->pEnd->pPrev;
			while (pNode != pList->pBegin)
			{
				OutputStudent(&pNode->tStudent);
				pNode = pNode->pPrev;
			}
			break;
	}
	cout << "학생수 : " << pList->iSize << endl;
	system("pause");
	
}

void Search(PLIST pList)
{
	system("cls");
	cout << "============학생출력=============" << endl;
	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);
	
	PNODE pNode = pList->pBegin;
	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strname, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;

		}
		pNode = pNode->pNext;
	}
	cout << "탐색한 이름이 리스트에 없습니다" << endl;
	system("pause");
	return;
}

void DeleteList(PLIST pList)  //특정노드를 삭제하는 함수
{
	system("cls");
	cout << "============학생삭제=============" << endl;
	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd) 
	{
		if (strcmp(pNode->tStudent.strname, strName) == 0) {
		
			pNode->pPrev->pNext = pNode->pNext;  //현재노드의 이전노드의 다음을 현재노드의 다음노드로 설정
			pNode->pNext->pPrev = pNode->pPrev;  //현재노드의 다음노드의 이전을 현재노드의 이전노드로 설정
			delete pNode;
			--pList->iSize;
			cout << strName << "학생 삭제완료!" << endl;
			system("pause");
			return;
		}
		cout << "삭제할 학생이름을 찾지 못했습니다" << endl;
		system("pause");
		return;
	}


}


void SortList(PLIST pList)
{
	int iSortmenu;
	while (true) {
		system("cls");
		cout << "============학생정렬=============" << endl;
		cout << "메뉴를 선택하세요 : 1. 학번순정렬    2. 평균순정렬" << endl;
		iSortmenu = Inputint();  //숫자입력함수 이용

		if (iSortmenu >= ST_NUMBER && iSortmenu <= ST_AVG)  //1 또는 2를 입력할때까지 계속 메뉴가 나옴
			break;
	}

	PNODE pFirst = pList->pBegin->pNext;
	
	//버블정렬을 이용(학번의 오름차순 정렬, i=pFirst, j=pSecond)
	while (pFirst != pList->pEnd->pPrev) //pFirst변수가 리스트의 End노드의 이전노드가 아닐동안 반복 
	{
		PNODE pSecond = pFirst->pNext;   //pSecond변수는 항상 pFirst의 다음노드를 가르키도록 설정
		while (pSecond != pList->pEnd)   //pSecond노드가 리스트의 end노드까지 반복(= End노드가 아닐동안까지 반복)
		{
			bool bSwap = false;
			switch (iSortmenu)
			{
			case ST_NUMBER:
				if (pFirst->tStudent.inumber > pSecond->tStudent.inumber) //오름차순이 아니면 bSwap변수를 true로
				{
					bSwap = true;
				}
				break;

			case ST_AVG:
				if (pFirst->tStudent.favg > pSecond->tStudent.favg)  //오름차순이 아니면 bSwap변수를 true로
				{
					bSwap = true;
				}
				break;
			}
			//bool변수 bSwap이 true일경우, 두 노드를 바꿈
			if (bSwap) 
			{

				//First노드의 이전노드와 다음노드를 저장해준다.
				PNODE pFirstPrev = pFirst->pPrev; //
				PNODE pFirstNext = pFirst->pNext;

				//Second노드의 이전노드와 다음노드를 저장해준다.
				PNODE pSecondPrev = pSecond->pPrev; //
				PNODE pSecondNext = pSecond->pNext;

				


				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;

				//바꾸려는 두노드가 붙어 있지 않은 경우
				if (pSecond != pFirstNext)
				{
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;  

				}
				else  //바꾸려는 두노드가 붙어 있는 경우
				{
					pSecond->pNext = pFirst;
					pFirst->pPrev = pSecond;
					
				}

				pSecondNext->pPrev = pFirst;  
				pFirst->pNext = pSecondNext;

				//노드교환
				PNODE pTemp = pFirst;  
				pFirst = pSecond;
				pSecond = pTemp;
				
			}
			pSecond = pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}
	cout << "정렬이 완료되었습니다" << endl;
	system("pause");
	return;	
}
