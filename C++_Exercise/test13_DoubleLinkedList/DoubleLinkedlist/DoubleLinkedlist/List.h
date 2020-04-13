
#pragma once //�� ��������� �� �ѹ��� ���Խ�Ű�ڴ�, ������Ͽ��� ���� �Լ��� ������.

#include <iostream>
#define NAME_SIZE 32

using namespace std;

enum SORTTYPE {
	ST_NONE,    //0
	ST_NUMBER,  //����������
	ST_AVG   //����������
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
	OT_OUPUT, //1  (���������)
	OT_INVERSE  //2 (���������)
};


typedef struct _tagStudent {  //�л�����ü(�����Ͱ�)
	char strname[NAME_SIZE];
	int inumber;
	int ikor;
	int ieng;
	int imath;
	int itotal;
	float favg;
}STUDENT, *PSTUDENT;

typedef struct _tagNode {  //��屸��ü
	STUDENT tStudent;  //������
	_tagNode* pNext;       //Double Linked List�̹Ƿ� ��������� pNext������ ��������� pPrev������ ��������
	_tagNode* pPrev;

}NODE, *PNODE;

typedef struct _tagList {  //����Ʈ����ü  
					//pBegin�� pEnd���� ��������� ����Ʈ�� ó���� ���� �ǹ��Ѵ�. ���� �����͸� �����ϴ� ��尡
						   //�ƴϴ�. ���� �����͸� �����ϴ� ���� pBegin�� pEnd������ ���� ������ش�. 
	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, *PLIST;

int OutputMenu();

int Inputint();        //���ڸ� �Է��ϴ� �Լ�
	
void InputString(char* pString, int iSize);   //�л������� �Է��ϴ� �Լ�

void InitList(PLIST pList); //����Ʈ �ʱ�ȭ

//void ClearList(PLIST pList); //����Ʈ�޸�����

void DestroyList(PLIST pList);   //����Ʈ���� 

void Push_Back(PLIST pList); // ��带 ����Ʈ�� �ڿ� �߰��ϱ� 

//void Push_Front();

void OutputStudent(const PSTUDENT pStudent);

void Output(PLIST pList);

void Search(PLIST pList);

void DeleteList(PLIST pList);

void SortList(PLIST pList);