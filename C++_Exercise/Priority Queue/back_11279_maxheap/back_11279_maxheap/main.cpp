#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;

public:
	Character(string name, int hp, int damage) : //초기화(이니셜라이저)
		name(name),                              //name,hp,damage에는 0이나 NULL값이 들어감
		ragePoint(0),							 //ragepoint는 0으로 설정되어 있으므로 0이 들어가 초기화
		hp(hp),
		damage(damage)
		{}
	Character(const Character& other)  //이때, other : 복사생성자라고 함.
	{
		name = other.name;                           
		ragePoint = other.ragePoint;
		hp = other.hp;
		damage = other.damage;
	}
	void pointUp() { 
		ragePoint++;
		if (ragePoint == 1)
			cout << "Pointup : +1" << endl;
		else
			cout << "Pointup : +2" << endl;
	}
	void show() {
		cout << name << "[" << ragePoint << "]" << hp << " " << damage << '\n';
		cout << "show" << endl;
	}
			
	~Character()
	{	
		cout << "객체 메모리 해제됨" << endl;
	}

};




int main(void) {

	Character character1("슬라임", 10, 5);
	character1.pointUp();
	Character character2(character1); //character1의 내용을 character2에 복사(깊은복사)
	character2.pointUp();
	character1.show();
	character2.show();
	
	return 0;

}