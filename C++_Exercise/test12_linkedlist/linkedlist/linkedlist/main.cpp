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
��ũ�帮��Ʈ : �ڷᱸ���� �� ����, �ڷᱸ���� �����͸� �����ϴ� ����� �ϳ�, 
�����͸���� ������Ѽ� ������ �� �ִ� ������ ������, �����͸� �����ϱ����� ����� ���� ����. 
�� ����� Ư¡�� ������带 �� �� �ְ� �Ѵ�. (���� ���� ��������� �޸��ּҸ� ������)
����Ʈ�� ���������� �Ǿ� �־ �迭ó�� Ư����ҿ� �ٷ� ������ �Ұ���. -> ������ �տ������� ���ʴ�� Ÿ�� ������
��带 ���� �߰��� ���� ��带 �����ϰ� ������ ��忡 ���Ḹ ���ָ� �Ǳ⶧����, ������ ������ ����. 
*/

typedef struct _tagNode{   //_tagNode��� �̸��� ���� ��屸��ü�� ����, ���� '������'�� '�������'�� �����Ǿ� ����, 
						   //���⿡�� �����ʹ� tStudent��� ����ü�̰�, �������� pnext��� tag_nodeŸ���� ��� ������ ������
	STUDENT tStudent;
	_tagNode* pNext;
}NODE, *PNODE;   //_tagNode����ü�� ��Ī�� NODE��� ����, _tagNode����ü�� �����ͺ��� ��Ī�� PNODE�� ����

typedef struct _tagList {  //����Ʈ����ü�� ����
	PNODE pBegin;     //��屸��ü�� �����ͺ�����Ī�� PNODE�� �̿��Ͽ� pBegin,pEnd�̶�� ��庯���� ����
	PNODE pEnd;       
	int iSize;

}LIST, *PLIST;   //_tagList��� ����ü�� ��Ī�� LIST, �� �����ͺ����� ��Ī�� PLIST�� ����.


void InitList(PLIST pList) { //����Ʈ����ü �ʱ�ȭ�ϴ� �Լ�

	pList->pBegin = NULL; //�����ʹ� �������̸� �ʱ�ȭ�Ҷ� null�� �ʱ�ȭ�ϴ� ���� ����(�ʱ�ȭ���� �������, �����Ⱚ
	pList->pEnd = NULL;					  //�� ���� �Ǵµ� �� �����Ⱚ�� TRUE�� ��Ÿ���� ��. 
	pList->iSize = 0;

}

int Inputint() {        //���ڸ� �Է��ϴ� �Լ�
	int iInput;
	cin >> iInput;
	if (cin.fail()) { //�Է½��н�
		cin.clear();  //cin�� �Է¹��۸� ������ 
		cin.ignore(1024, '\n');
		return -1;
	}
	return iInput;
}

int OutputMenu() {
	system("cls");
	cout << "1. �л��߰�" << endl;
	cout << "2. �л�����" << endl;
	cout << "3. �л�Ž��" << endl;
	cout << "4. �л����" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : " << endl;
	int iInput;
	iInput=Inputint();  //�޴���ȣ�� �Է�(���ڸ� �Է��ϴ� �Լ��� Inputint()�̿�)
	if (iInput <= 0 || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}

void InputString(char* pString, int iSize) {  //�л������� �Է��ϴ� �Լ�
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1); 
}


void Insert(PLIST pList) {  //�л������� �߰�(����)�ϴ� �Լ�(Menu 1��)
	STUDENT tStudent = {};
	system("cls");
	cout << "============�л��߰�============="<<endl;
	cout << "�й� : ";
	tStudent.inumber = Inputint();
	cout << "�̸� : ";
	InputString(tStudent.strname, NAME_SIZE);
	cout << "���� : ";
	tStudent.ikor = Inputint();
	cout << "���� : ";
	tStudent.ieng = Inputint();
	cout << "���� : ";
	tStudent.imath = Inputint();
	
	tStudent.itotal = tStudent.ikor + tStudent.ieng + tStudent.imath;
	tStudent.favg = (tStudent.itotal / 3.f);

	//�߰��� ����Ʈ��带 ������
	//���� �߰��ϴ� ���� ����Ʈ�� ���� ������ ����̹Ƿ�, ������尡 �������� ����
	//����, �����Ҵ����� ������ ����� ���� ���(pNext)�� ����Ű�� ������ NULL�� �ʱ�ȭ���ְ�
	//������ ����� �����ͺ����� tStudent���� ��� �Է��� tStudent�����͵��� �־��ش�
	PNODE pNode = new NODE;
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL) {
		pList->pBegin = pNode;
	}
	else {
		pList->pEnd->pNext = pNode;  //����, ����Ʈ�� ������� ������带 ������ ���� �������ش�.
	}
	pList->pEnd = pNode; //����, ����Ʈ�� ����带 ��� ������ ���� ��������.
	++pList->iSize;
	
}

void ClearList(PLIST pList) {  //����Ʈ�� �޸����� 
	PNODE pNode = pList->pBegin; //pbegin�� ����Ű�� ��带 pNode������ ����.
	while (pNode!=NULL) {
		PNODE pNext = pNode->pNext; //1. pBegin�� ����Ű�� ����� ���� ��带 pNext�� ����
		delete pNode;               //2. pBegin�� ����Ű�� ��带 �޸�����
		pNode = pNext;              //3. pNode�� 1.���� �����ߴ� ��带 ����
		                            //4. 1~3.�ݺ�(pNode�� NULL�� �ɶ�����)
	}
	pList->pBegin = NULL;  //����Ʈ�� ��� ��尡 �޸������Ǹ�, ����Ʈ�� pBegin, pEnd���� Null��, iSize���� 0���� ��������.
	pList->pEnd = NULL;
	pList->iSize = 0;
}

void OutputStudent(const PSTUDENT pStudent) {  //�����ͷ� ���ڸ� �Ѱܹ޴� ���� �� ȿ������(�����ʹ� ������ 4byte�̹Ƿ�)
	cout << "�й� : ";                         //���� �����ϸ� �ȵǴϱ� const�� �������ش�.
	cout << pStudent->inumber << endl;
	cout << "�̸� : ";
	cout << pStudent->strname << endl;
	cout << "���� : ";
	cout << pStudent->ikor << endl;
	cout << "���� : ";
	cout << pStudent->ieng << endl;
	cout << "���� : ";
	cout << pStudent->imath << endl;
	cout << "���� : ";
	cout << pStudent->itotal << endl;
	cout << "��� : ";
	cout << pStudent->favg << endl;
}


void Output(PLIST pList) {
	int i = 0;
	PNODE pNode = pList->pBegin;
	system("cls");
	cout << "============�л����=============" << endl;
	while (pNode != NULL) {
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;  //������带 pNode�� �����Ͽ� ����Ʈ��� ����� �� �ֵ��� ����.
	}
	cout << "�л��� : " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList) {
	system("cls");
	cout << "============�л�Ž��=============" << endl;
	cout << "Ž���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};  
	InputString(strName, NAME_SIZE); //strName�̶�� ���������� Ž���� �̸��� ����
	PNODE pNode = pList->pBegin; //����ü�� ù��° ������ Ž������
	while (pNode != NULL) {  
		if (strcmp(pNode->tStudent.strname, strName)==0) { //strcmp�� ����� strname������ Ž���� �̸��� ���� ���������� strName�� ��
			OutputStudent(&pNode->tStudent); //Ž�������ϸ� �ش� ����� Student����ü�� �����͵��� �����.
			system("pause");
			return;
		}
		pNode = pNode->pNext; //������带 �˻�

	}
	cout << "Ž���� �̸��� �����ϴ�" << endl; //while���� ���������� Ž���� �̸��� ���ٴ� �ǹ��̹Ƿ� �������.
	system("pause");


}

void Delete(PLIST pList) {
	system("cls");
	cout << "============�л�����=============" << endl;
	cout << "������ �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE); //strName�̶�� ���������� Ž���� �̸��� ����

	PNODE pNode = pList->pBegin;  //���� ����Ʈ�� ù��° ������ Ž������ 
	PNODE pPrev = NULL;    //���� ��尡 ����Ʈ�� ù��° ����̹Ƿ�, ������带 �ǹ��ϴ� pPrev������ NULL���� ��
	while (pNode != NULL) { //����Ʈ�� ��� ������ �ݺ�
		if (strcmp(pNode->tStudent.strname, strName) == 0) { //�������̸��� ã����
			PNODE pNext = pNode->pNext; //pNext��� PNODE�������� ���� ����� ������带 �־���.
			if (pPrev == NULL) {  //����, ������ �̸��� ��尡 ù��° ��忩�� pPrev���� NULL�̶��
				delete pNode;   //ã�� �̸��� ��带 ����
				pList->pBegin = pNext;  //����Ʈ�� pBegin���� pNext��� ��������.
				if (pNext == NULL) { //������尡 ���� ���,(������ ����Ʈ�� ��尡 �ϳ��� �ִµ� �� �ϳ��� ��带 ������ ���)
					pList->pEnd = NULL;  //pEnd���� NULL�� ��������.
				}
			}
			else {  //������尡 ���� ��� (��������� ������ �������� �������� ��������)
				delete pNode;
				pPrev->pNext = pNext;
				if (pNext==NULL) {//������ ��尡 ����Ʈ�� pEnd�� ���
					pList->pEnd = pPrev;
				}
			}
			cout << strName << "�л� �����Ϸ�!" << endl;
			--pList->iSize;
			system("pause");
			return;
		}
		pPrev = pNode;
		pNode = pNode->pNext;  //pPrev�� ���� ��尡, ������� ������尡 ���� ��� �ݺ�
		
	}
	cout << "������ �л��� ã�� �� �����ϴ�" << endl;
	system("pause");

}

int main(void) {

	LIST tList;
	InitList(&tList); //����Ʈ �ʱ�ȭ 
	while (true) {
		int iMenu = OutputMenu(); //�Է��� �޴����� ����ִ� OutputMenu()���� iMenu������ �־���
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