#include "List.h"
#include <algorithm>
using namespace std;
//�Լ��� �����ϴ� List.cpp����



static int Inputint() {        //���ڸ� �Է��ϴ� �Լ�
	int iInput;
	cin >> iInput;
	if (cin.fail()) { //�Է½��н�
		cin.clear();  //cin�� �Է¹��۸� ������ 
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void InputString(char* pString, int iSize) {  //�л������� �Է��ϴ� �Լ�
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

int OutputMenu() {
	system("cls");
	cout << "1. �л��߰�" << endl;
	cout << "2. �л�����" << endl;
	cout << "3. �л�Ž��" << endl;
	cout << "4. �л����" << endl;
	cout << "5. �л�����" << endl;
	cout << "6. ����" << endl;
	cout << "�޴��� �����ϼ��� : " << endl;
	int iInput;
	iInput = Inputint();  //�޴���ȣ�� �Է�(���ڸ� �Է��ϴ� �Լ��� Inputint()�̿�)
	if (iInput <= 0 || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}
void InitList(PLIST pList) { //����Ʈ�� �ʱ�ȭ�ϴ� �Լ�
	pList->iSize = 0;
	pList->pBegin = new NODE;  //��屸��ü�� �����Ҵ縸 �س��´�(�����Ͱ� ���� ����̹Ƿ�)
	pList->pEnd = new NODE;	   //��屸��ü�� �����Ҵ縸 �س��´�(�����Ͱ� ���� ����̹Ƿ�)
	pList->pBegin->pNext = pList->pEnd;  //pBegin�� pEnd�� ���� ����Ű���� ���ش�.
	pList->pEnd->pPrev = pList->pBegin;
	pList->pEnd->pNext = NULL;  //pEnd�� �������� �����Ƿ� NULLó��
	pList->pBegin->pPrev = NULL; //pBegin�� �������� �����Ƿ� NULLó��
}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	while (pNode != NULL) {
		PNODE pNext = pNode->pNext; //pNext������ ���� ����� ���� ��带 ��������
		delete pNode;  //���� ����� �޸�����
		pNode = pNext;  //pNode�� ������尡 ���ִ� pNext������ ��������.
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
	cout << "============�л��߰�=============" << endl;
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

	PNODE pNode = new NODE;  //���Ӱ� �߰��� ������
	pNode->tStudent = tStudent;  //���Ӱ� �߰��� ����� ������(�л�����)���� ��� �Է��� �л������� ��
	PNODE pPrev= pList->pEnd->pPrev;  //pPrev��庯���� ���� End����� �������� �����Ѵ�.
	
	pPrev->pNext = pNode;  //pPrev������ �������� ���Ӱ� �߰��� ���� �����Ѵ�.
	pNode->pPrev = pPrev;  //���Ӱ� �߰��� ����� �������� ���� pPrev��庯��(���� end����� �������)�� �����Ѵ�

	pNode->pNext = pList->pEnd; //���Ӱ� �߰��� ����� ������带 pEnd�� �����Ѵ�
	pList->pEnd->pPrev = pNode;  //end����� ������带 ���Ӱ� �߰��� ���� �����Ѵ�

	++pList->iSize;  //����Ʈ���� ����

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

void Output(PLIST pList)
{
	int iMenu;
	while (1)
	{
		system("cls");
		cout << "============�л����=============" << endl;
		cout << "�޴��� �����ϼ��� : 1. ���������    2. ���������" << endl;
		iMenu = Inputint();  //�����Է��Լ� �̿�

		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)  //1 �Ǵ� 2�� �Է��Ҷ����� ��� �޴��� ����
			break;
	}

	PNODE pNode = NULL;
	switch (iMenu)
	{
		case OT_OUPUT:  //���������
			pNode = pList->pBegin->pNext;  //begin�� ���������� 
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
	cout << "�л��� : " << pList->iSize << endl;
	system("pause");
	
}

void Search(PLIST pList)
{
	system("cls");
	cout << "============�л����=============" << endl;
	cout << "Ž���� �̸��� �Է��ϼ��� : ";
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
	cout << "Ž���� �̸��� ����Ʈ�� �����ϴ�" << endl;
	system("pause");
	return;
}

void DeleteList(PLIST pList)  //Ư����带 �����ϴ� �Լ�
{
	system("cls");
	cout << "============�л�����=============" << endl;
	cout << "������ �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd) 
	{
		if (strcmp(pNode->tStudent.strname, strName) == 0) {
		
			pNode->pPrev->pNext = pNode->pNext;  //�������� ��������� ������ �������� �������� ����
			pNode->pNext->pPrev = pNode->pPrev;  //�������� ��������� ������ �������� �������� ����
			delete pNode;
			--pList->iSize;
			cout << strName << "�л� �����Ϸ�!" << endl;
			system("pause");
			return;
		}
		cout << "������ �л��̸��� ã�� ���߽��ϴ�" << endl;
		system("pause");
		return;
	}


}


void SortList(PLIST pList)
{
	int iSortmenu;
	while (true) {
		system("cls");
		cout << "============�л�����=============" << endl;
		cout << "�޴��� �����ϼ��� : 1. �й�������    2. ��ռ�����" << endl;
		iSortmenu = Inputint();  //�����Է��Լ� �̿�

		if (iSortmenu >= ST_NUMBER && iSortmenu <= ST_AVG)  //1 �Ǵ� 2�� �Է��Ҷ����� ��� �޴��� ����
			break;
	}

	PNODE pFirst = pList->pBegin->pNext;
	
	//���������� �̿�(�й��� �������� ����, i=pFirst, j=pSecond)
	while (pFirst != pList->pEnd->pPrev) //pFirst������ ����Ʈ�� End����� ������尡 �ƴҵ��� �ݺ� 
	{
		PNODE pSecond = pFirst->pNext;   //pSecond������ �׻� pFirst�� ������带 ����Ű���� ����
		while (pSecond != pList->pEnd)   //pSecond��尡 ����Ʈ�� end������ �ݺ�(= End��尡 �ƴҵ��ȱ��� �ݺ�)
		{
			bool bSwap = false;
			switch (iSortmenu)
			{
			case ST_NUMBER:
				if (pFirst->tStudent.inumber > pSecond->tStudent.inumber) //���������� �ƴϸ� bSwap������ true��
				{
					bSwap = true;
				}
				break;

			case ST_AVG:
				if (pFirst->tStudent.favg > pSecond->tStudent.favg)  //���������� �ƴϸ� bSwap������ true��
				{
					bSwap = true;
				}
				break;
			}
			//bool���� bSwap�� true�ϰ��, �� ��带 �ٲ�
			if (bSwap) 
			{

				//First����� �������� ������带 �������ش�.
				PNODE pFirstPrev = pFirst->pPrev; //
				PNODE pFirstNext = pFirst->pNext;

				//Second����� �������� ������带 �������ش�.
				PNODE pSecondPrev = pSecond->pPrev; //
				PNODE pSecondNext = pSecond->pNext;

				


				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;

				//�ٲٷ��� �γ�尡 �پ� ���� ���� ���
				if (pSecond != pFirstNext)
				{
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;  

				}
				else  //�ٲٷ��� �γ�尡 �پ� �ִ� ���
				{
					pSecond->pNext = pFirst;
					pFirst->pPrev = pSecond;
					
				}

				pSecondNext->pPrev = pFirst;  
				pFirst->pNext = pSecondNext;

				//��屳ȯ
				PNODE pTemp = pFirst;  
				pFirst = pSecond;
				pSecond = pTemp;
				
			}
			pSecond = pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}
	cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
	system("pause");
	return;	
}
