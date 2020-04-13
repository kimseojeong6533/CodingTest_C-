#include <iostream>
using namespace std;

/*
상속 : 클래스는 클래스간에 부모,자식관계를 형성할 수 있음. 자식	클래스는 부모클래스의 멤버변수들을 사용가능하다
		단, 부모클래스에서 public이나 protected로 되어 있는 멤버들은 사용가능, private으로 되어 있는 멤버들은 사용불가

상속의 형태 :  public, private 상속이 있다. 

다형성 : 상속관계에 있는 두 클래스간에 서로 형변환이 가능한 성질을 말한다.

가상함수 :  함수 오버라이딩 이라고도 부른다. 함수를 재정의하는 기능이다. 멤버함수 앞에 virtual키워드를 넣으면 해당함수
			는 가상함수가 된다 , 만약 CParent클래스에 virtual Output()함수가 있다면 자식클래스에서는 이 가상함수를 
			재정의 할 수 있다. 재정의는 함수이름과 인자가 완전히 똑같아야 한다. 

			가상함수를 가지고 있는 클래스는 내부적으로 가상함수테이블이라는 것을 생성한다. 가상함수 테이블은 가상함수
			의 메모리 주소를 저장하는 테이블이다. 만약, CParent의 Output이 가상함수이고 CChild클래스에 Output을 재정의
			한다면, 그런 뒤, CChild객체를 생성하면 가상함수 테이블에는 CChild클래스의 Output주소가 올라가게 된다. 
			만약, CParent객체를 생성한다면 CParent의 Output함수주소가 올라가게 된다. 그래서 Output함수, 즉, 가상함수를
			호출하게 되면 먼저, 가상함수 테이블을 참조해서 메모리주소를 확인한다. 가상함수 테이블에 CChild의 Output함수
			주소가 들어있다면 그 주소의 함수를 호출해주는 개념이다. 
			**부모클래스의 소멸자는 항상 가상함수로 만들어 주자.


cf) 함수오버로딩 : 같은함수명이더라도 입자타입과 개수로 함수를 선별하여 값을 대입해주는 것.
*/

class CParent
{
public:
	CParent()
	{
		m_iB = 1000;
		m_iC = 2000;
		cout << "CParent 생성자" << endl;
	}
	virtual ~CParent() 
	{
		cout << "CParent 소멸자" << endl;
	}
public:
	int		m_iA;

protected:
	int		m_iB;
private:
	int		m_iC;

public:
	virtual void Output()
	{
		//cout << "A : " << m_iA << "\tB : " << m_iB << "\tC : " << m_iC << endl;
		cout << "Parent Output 출력" << endl;
	}
	//순수가상함수 : 함수뒤에 = 0 을 붙여주면, 해당 가상함수는 순수가상함수가 된다. 
	//순수가상함수는 구현부분이 존재하지 않는다.(구현은 자식클래스에서 할 수 있음.)
	//순수가상함수를 가지고 있는 클래스 : 추상클래스  ->아래부분으로인해서 CParent클래스는 추상클래스가 되었음
	//추상클래스는 인스턴스(객체)생성이 불가능하다.
	//순수가상함수는 자식에서 반드시 재정의 해야한다. 왜냐하면 부모의 순수가상함수는 정의부분이 때문에
	//반드시 자식에서 재정의할 목적으로 만든 함수이기 때문이다. (만들지 않으면, 외부에서 자식클래스의 객체가 생성되지 않음	)
	virtual void OutputPure() = 0;
	
};

class CChild : public CParent  //Child클래스가 Parent클래스(public)를 상속받음
{
public:
	CChild() 
	{
		m_iB = 200;  //m_iB는 protected이므로 자식클래스가 접근할 수 있음
		//m_iC = 300;  //m_iC는 private이기 때문에 자식클래스가 접근할 수 없음 
		cout << "CChild 생성자" << endl;
	}
	virtual ~CChild()
	{
		cout << "CChild 소멸자" << endl;
	}

protected:
	int		m_iD;

public:
	void ChildOutput()
	{
		cout << "Child Output" << endl;
	}
	virtual void Output()
	{
		cout << "Child Output출력" << endl;
	}
	virtual void OutputPure()  //순수가상함수 재정의
	{

	}
};

class CChild1 : private CParent  //Child클래스가 Parent클래스(private)를 상속받음
{
public:
	CChild1()
	{
		cout << "CChild1 생성자" << endl;
	}
	~CChild1()
	{
		cout << "CChild1 소멸자" << endl;
	}
	virtual void OutputPure()
	{}
private:
	int		m_iD;
};

class CChildChild : public CChild  //ChildChild클래스가 Child클래스를 상속받음
{
public:
	CChildChild()
	{
		m_iD = 500;
		cout << "CChildChild 생성자" << endl;
	}
	~CChildChild()
	{
		cout << "CChildChild 소멸자" << endl;
	}

private:
	int		m_iE;

};

int main(void)
{
	//CParent		parent;
	//CChild		child;
	//CChild1		child1;
	//CChildChild	childchild;

	//parent.m_iA = 100;
	
	//child.m_iA = 200;
	
	//child1.m_iA = 300; //클래스외부에서 접근할때, child1의 경우, parent클래스를 private으로 상속받았기 때문에 m_iA가 public멤버변수라도 접근불가
	                   //다만, child1클래스의 내부에서는 접근가능함. 
	//parent.Output();
	//child1.Output(); //클래스외부에서 부모클래스 접근불가 (CChild1클래스는 CParent클래스를 private으로 상속받고 있기
	                   //때문에 CParent에서 public으로 되어 있는 멤버들도 외부에서는 접근불가

	//CParent cparent;  //순수가상함수 때문에 CParent클래스의 객체생성이 불가함,포인터변수는 가능
	CParent* cparent2;
								      //CChild클래스는 CParent클래스를 상속받고 있다. 
	CParent* pParent = new CChild;    //new CChild는 CChild객체하나를 생성하고 그 메모리주소를 반환함. 
	//CParent* pParent1 = new CChild1;  //왼쪽은 CChild1클래스가 private으로 Parent클래스를 상속받으므로 메인함수에서 접근불가
									  //따라서 메인함수에서 생성한 CParent클래스포인터가 CChild1객체의 메모리 주소를 담을 수 없게 됨.
	
	CParent* pParent2 = new CChildChild;   //왼쪽에서는 CParent* 타입 변수에 이 반환된 주소를 대입해주고 있음. 
								           //부모포인터타입에 CChild 객체의 메모리주소를 넣을 수 있는 이유는 상속관계에 있기 때문
				                           //자식 메모리주소를 부모포인터타입으로 형변환 한 것. 이것을 업캐스팅이라 함.(자식->부모타입)  
                                           //부모->자식타입으로 형변환 : 다운캐스팅 
	
	//아래 두 클래스는 모두 CParent클래스를 상속받고 있다. 
	//그러므로 pParent를 두타입 모두 다운캐스팅 가능하다. 
	/*그런데  pParent는 CChild로 할당한 객체이다. 이 객체를 CChild1타입으로 다운캐스팅하게 되면 문제가 발생할 수 있다.
	  왜냐하면 애초에 생성한 객체가 아닌 다른 타입으로 변환됐기 때문이다. 
	*/
	CChild* pChild = (CChild*)pParent; //자식 -> 부모타입으로 형변환
	CChild1* pChild1 = (CChild1*)pParent;

	((CChild*)pParent)->ChildOutput();  //pParent를 CChild클래스로 형변환하지 않으면 pParent의 자식클래스인 CChild에 있는
										//ChildOutput()함수를 사용할 수 없다. 왜냐하면, pParent는 CParent클래스의 포인터타입이기 때문에
										//그래서 부모클래스의 포인터변수는 반드시 자식클래스포인터타입으로 형변환한 뒤에 자식클래스내 함수를 사용해야한다.

	pParent->CParent::Output();  //부모클래스의 Output함수(가상함수) 호출, 자식클래스포인터주소가 가상함수테이블에 작성되지만, 명시적으로 써주면 부모클래스의 가상함수 사용가능 
	pParent->Output();  //자식클래스의 Output함수 호출, 
	delete pParent; //delete pParent를 하게되면, 부모클래스생성자->자식클래스생성자->부모클래스의 소멸자가 순서대로 호출된다.
					//자식클래스의 소멸자가 호출되지 않는 이유는, pParent가 근본적으로 CParent클래스의 포인터타입
					//이기 때문이다. 

	CParent* pParentArr[2] = {};   //부모클래스의 포인터배열로 자식클래스, 자식의자식클래스 등 여러개의 클래스를 관리할 수 있음. 
	pParentArr[0] = new CChild;   
	pParentArr[1] = new CChildChild;



	return 0;
}

/*
상속관계에서의 생성자 호출순서 : 부모생성자내용 -> 자식생성자내용 
상속관계에서의 소멸자 호출순서 : 자식소멸자내용 -> 부모소멸자내용
*/