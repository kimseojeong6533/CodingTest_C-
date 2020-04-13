#include <iostream>
using namespace std;

int main() {

	const int iAttack = 0x00000001;   //����� ��Ÿ���� ���� const�� ������ ��, 0x00000001(16����)=1(2����) 
	const int iArmor = 0x00000002;  //0x00000002 = 10
	const int iHP = 0x00000004; //100
	const int iMP = 0x00000008; //1000
	const int iCritical = 0x00000010; //10000

	//1 | 100 = 101 -> 101 | 10000 = 10101�� iBuf�� �� 
	int iBuf = iAttack | iHP | iCritical;
	
	cout << "iBuf = " << (iBuf & iAttack) << endl;
	cout << "iArmor = " << (iBuf & iArmor) << endl;
	cout << "iHP = " << (iBuf & iHP) << endl;
	cout << "iMP = " << (iBuf & iMP) << endl;
	cout << "iCritical = " << (iBuf & iCritical) << endl;


	/*����Ʈ ������ : <<, >> (���밪�� �����Ͽ� ������ �����Ե�), ������������ ������ ������
	
	*/

	
	
	return 0;
}