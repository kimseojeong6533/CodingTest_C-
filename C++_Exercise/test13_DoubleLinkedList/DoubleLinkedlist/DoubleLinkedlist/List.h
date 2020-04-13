
#pragma once //이 헤더파일을 딱 한번만 포함시키겠다, 헤더파일에는 보통 함수를 선언함.

#include <iostream>
#define NAME_SIZE 32

using namespace std;

enum SORTTYPE {
	ST_NONE,    //0
	ST_NUMBER,  //순방향정렬
	ST_AVG   //역방향정렬
};

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_SORT,
	MM_EXIT
};

enum OUTPUT_TYPE
{
	OT_NONE,  //0  
	OT_OUPUT, //1  (순방향출력)
	OT_INVERSE  //2 (역방향출력)
};


typedef struct _tagStudent {  //학생구조체(데이터값)
	char strname[NAME_SIZE];
	int inumber;
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}STUDENT, *PSTUDENT;

typedef struct _tagNode {  //노드구조체
	STUDENT tStudent;  //데이터
	_tagNode* pNext;       //Double Linked List이므로 다음노드인 pNext변수와 이전노드인 pPrev변수를 생성해줌
	_tagNode* pPrev;

}NODE, *PNODE;

typedef struct _tagList {  //리스트구조체  
					//pBegin과 pEnd노드는 명시적으로 리스트의 처음과 끝을 의미한다. 실제 데이터를 저장하는 노드가
						   //아니다. 실제 데이터를 저장하는 노드는 pBegin과 pEnd사이의 노드로 만들어준다. 
	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, *PLIST;

int OutputMenu();

int Inputint();        //숫자를 입력하는 함수
	
void InputString(char* pString, int iSize);   //학생정보를 입력하는 함수

void InitList(PLIST pList); //리스트 초기화

//void ClearList(PLIST pList); //리스트메모리해제

void DestroyList(PLIST pList);   //리스트삭제 

void Push_Back(PLIST pList); // 노드를 리스트의 뒤에 추가하기 

//void Push_Front();

void OutputStudent(const PSTUDENT pStudent);

void Output(PLIST pList);

void Search(PLIST pList);

void DeleteList(PLIST pList);

void SortList(PLIST pList);