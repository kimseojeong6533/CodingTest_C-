#include <iostream>
#include <functional>

using namespace std;

int Sum(int a, int b) {
	return a + b;
}

int OutSum(int a, int b) {
	cout << a - b << endl;
	return a - b;
}

void Output() {
	cout << "Output Function" << endl;
}

class CHanzo
{
public:
	CHanzo() 
	{
		m_iTest = 10;
	};
	
	~CHanzo() 
	{
	
	};

public:
	int m_iTest;

public:
	void Output() 
	{
		cout << "Hanzo" << endl;
		cout << "Test : " << this->m_iTest << endl;
	}

	void Sumand(int a, int b)
	{
		cout << "Sumand" << endl;
		cout << a + b << endl;
		
		
	}


};

typedef struct _tagPoint
{
	int x;
	int y;
	
	//C++에서는 구조체안에서 생성자를 만들 수 있음
	_tagPoint() : //구조체 생성자 초기화(이니셜라이저이용)
		x(0),
		y(0)    //_tagPoint만 호출되면 x,y의 값은 0,0으로 대입됨.
	{
	}

	_tagPoint(int _x,int _y) :  //이니셜라이저를 이용한 생성자초기화
		x(_x),                  //x에 _x를 대입하라는 뜻 
		y(_y)				    //y에 _y를 대입하라는 뜻
								//_tagPoint(10,20)이면,x에 10, y에 20이라는 값이 들어감.
	{
	}

	_tagPoint(const _tagPoint& pt)
	{
		*this = pt;  //this는 자기자신의 포인터 (자기자신을 역참조하여 모든데이터를 복사하게 함.)
	}

	_tagPoint operator + (const _tagPoint& pt)
	{
		_tagPoint result;
		result.x = x + pt.x; //메인함수내의 pt3 = pt1 + pt2;에서 pt1의 x가 x, pt2의 x가 pt.x로 들어가고 result.x는 pt3의 x값으로 들어가게 됨
		result.y = y + pt.y;
		return result;
	}

	_tagPoint operator + (int a)
	{
		_tagPoint pt;
		pt.x = x + a;
		pt.y = y + a;
		return pt;
	}
	void operator << (const _tagPoint& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	void operator >> (_tagPoint& pt)
	{
		pt.x = x;
		pt.y = y;
	}
	
}POINT, *PPOINT;



int main(void) {

/*
함수포인터 : 함수의 메모리주소를 저장하기위한 포인터변수를 선언할 수 있다. 

전역함수의 경우, 함수명이 곧 함수의 메모리주소이다. 
함수포인터 선언방법 : 반환타입(*포인터변수명)(인자타입);의 형태
*/

	int(*pFunc)(int, int)=Sum; //함수포인터 pFunc가 (전역함수)Sum함수를 가르키도록 설정
	cout << pFunc(10, 20) << endl;
	pFunc = OutSum;            //함수포인터 pFunc가 OutSum함수를 가르키도록 설정
	cout << pFunc(10,20) << endl;
	//pFunc = Output; //오류(반환타입과 인자가 다르므로 오류남)
	void(*pFunc_Output)() = Output;  //pFunc_Output이라는 새로운 함수포인터를 선언하여 Output함수를 가르키도록 설정
	pFunc_Output(); //함수포인터명+()까지 붙여줘야 함.


	CHanzo hanzo1, hanzo2;
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	/*
	this 포인터 :  클래스안에서 this를 사용할 경우, 해당 객체의 메모리 주소가 된다. 즉, 자기자신의 포인터이다. 	
	*/
	//멤버함수를 호출할 때 this를 호출자로 세팅한다. 
	hanzo1.Output();
	hanzo2.Output();

	//멤버함수포인터선언시, 포인터변수 이름앞에 '클래스명 ::' 을 붙여줌. (::은 범위지정연산자라고도 함 또는 scope연산자)
	void(CHanzo::*pFunc2)(int,int)= &CHanzo::Sumand;    
	//(*pFunc2)  -> 에러
	(hanzo1.*pFunc2)(4,5);    //전역함수포인터와 클래스멤버함수포인터의 형태가 다르고 쓸때도 형태가 달라 불편함
	                          // -> C++11에서 functional이라는 기능을 통해 전역함수, 멤버함수 동일하게 함수포인터를 이용
	                          //하여 사용할 수 있도록 하였음. -> #include <functional>추가 필요


	/*
	function기능은 C++11부터 지원해주는 기능, 이 기능은 함수포인터를 전역,멤버 가리지않고 쉽게 주소를 저장해서
	호출해줄수 있도록 만들어주는 기능.
	선언방법 :  function<리턴타입(인자타입)> 변수명;
	*/

	function<void()>	func;
	function<void()>	func1;

	//bind함수를 이용해서 함수를 묶어줌.  함수포인터명 = bind(함수명,인자리스트);
	func = bind(Output);  //func에는 전역함수Output이 들어감(인자가 없으므로 없음)
	func1 = bind(&CHanzo::Output, &hanzo1);  //func1에는 CHanzo 클래스내의 Output함수가 들어감 


	cout << "==============Functional=============" << endl;
	func();
	func1();

	cout << "=========placeholders이용========" << endl;
	function<int(int, int)> func3;
	//함수에 인자가 있을 경우, (placeholders::_1, _2)를 이용해서 인자의 순서를 조정할 수 있다. (_1,_2)->10-20 / (_2,_1) -> 20-10
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);  
	func3(10, 20);
	cout << endl;
	cout << "===============Point=============" << endl;
	POINT pt1(10,20), pt2(30,40), pt3;

	pt3 = pt1 + pt2;  //원래 구조체끼리의 연산은 불가함 but, Operator를 사용하면 가능
	                  //+연산자가 operator로 재정의 되어 있으므로 +연산이 가능하게된다.
	                  //pt1의 +연산자 함수를 호출해주면서 pt2를 인자로 넘겨준다.

	pt3 << pt2;
	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;
	pt1 << pt3;
	cout << "x : " << pt1.x << "\ty : " << pt1.y << endl;
	pt3 = pt3 + 1000;
	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;

	return 0;
}