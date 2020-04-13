#include <iostream>
#include "List.h"  //사용자가 만든 헤더파일을 포함시킬때에는  큰따옴표("")사용
#define NAME_SIZE 32

using namespace std;
//main.cpp파일에는 메인함수만 있어야함
int main() {
	LIST tList;
	InitList(&tList);
	while (1) {
		int iMenu = OutputMenu(); //입력한 메뉴값이 들어있는 OutputMenu()값을 iMenu변수에 넣어줌
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
			Output(&tList);  //정방향 or 역방향 출력을 선택하도록 한다.
			break;
		case MM_SORT:
			SortList(&tList);  //정방향 or 역방향 출력을 선택하도록 한다.
			break;
		}
	}
	DestroyList(&tList);  //프로그램종료후 메모리해제

	return 0;
}