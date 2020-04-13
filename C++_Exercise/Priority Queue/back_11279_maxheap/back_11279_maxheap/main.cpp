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
	Character(string name, int hp, int damage) : //�ʱ�ȭ(�̴ϼȶ�����)
		name(name),                              //name,hp,damage���� 0�̳� NULL���� ��
		ragePoint(0),							 //ragepoint�� 0���� �����Ǿ� �����Ƿ� 0�� �� �ʱ�ȭ
		hp(hp),
		damage(damage)
		{}
	Character(const Character& other)  //�̶�, other : ��������ڶ�� ��.
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
		cout << "��ü �޸� ������" << endl;
	}

};




int main(void) {

	Character character1("������", 10, 5);
	character1.pointUp();
	Character character2(character1); //character1�� ������ character2�� ����(��������)
	character2.pointUp();
	character1.show();
	character2.show();
	
	return 0;

}