#include <iostream>
using namespace std;

int main() {

	const int iAttack = 0x00000001;   //상수를 나타내고 싶음 const를 덧붙일 것, 0x00000001(16진수)=1(2진수) 
	const int iArmor = 0x00000002;  //0x00000002 = 10
	const int iHP = 0x00000004; //100
	const int iMP = 0x00000008; //1000
	const int iCritical = 0x00000010; //10000

	//1 | 100 = 101 -> 101 | 10000 = 10101가 iBuf에 들어감 
	int iBuf = iAttack | iHP | iCritical;
	
	cout << "iBuf = " << (iBuf & iAttack) << endl;
	cout << "iArmor = " << (iBuf & iArmor) << endl;
	cout << "iHP = " << (iBuf & iHP) << endl;
	cout << "iMP = " << (iBuf & iMP) << endl;
	cout << "iCritical = " << (iBuf & iCritical) << endl;


	/*쉬프트 연산자 : <<, >> (값대값을 연산하여 값으로 나오게됨), 이진수단위의 연산을 수행함
	
	*/

	
	
	return 0;
}