#include <iostream>
#include "List.h"  //����ڰ� ���� ��������� ���Խ�ų������  ū����ǥ("")���
#define NAME_SIZE 32

using namespace std;
//main.cpp���Ͽ��� �����Լ��� �־����
int main() {
	LIST tList;
	InitList(&tList);
	while (1) {
		int iMenu = OutputMenu(); //�Է��� �޴����� ����ִ� OutputMenu()���� iMenu������ �־���
		if (iMenu == MM_EXIT)
			break;
		switch (iMenu) {

		case MM_INSERT:
			Push_Back(&tList);
			break;

		case MM_DELETE:
			DeleteList(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);  //������ or ������ ����� �����ϵ��� �Ѵ�.
			break;
		case MM_SORT:
			SortList(&tList);  //������ or ������ ����� �����ϵ��� �Ѵ�.
			break;
		}
	}
	DestroyList(&tList);  //���α׷������� �޸�����

	return 0;
}