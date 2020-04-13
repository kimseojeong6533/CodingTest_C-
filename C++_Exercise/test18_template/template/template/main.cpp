#include <iostream>
#include <string>
using namespace std;

/*
템플릿 : 컴파일 단계에서 타입을 결정짓는 기능이다. 타입이 다양하게 바뀔 수 있다.
template <typename 원하는이름>의 형태로 사용가능
template <class 원하는이름>의 형태로 사용가능

ex) template<typename T>
void Output()
{
	cout << typeid(T).name() << endl;
}
위처럼 함수를 만들고  호출시
Output<int>(); or Output<float>(); 이렇게 해주면 int, float타입이 정해진다. 상황에 따라 넣어주는 타입으로
타입이 가변적으로 바뀌는 것이다. 가변타입은 여러개를 지정해줄 수 있다.
ex)
template<typename T,typename T1>
void Output() {}


*/

template <typename T>
void OutputType()
{
	cout << "======= OutputType =======" << endl;
	cout << typeid(T).name() << endl;
}

template <typename T>
void Outputdata(T data)
{
	cout << "======= OutputData =======" << endl;
	cout << typeid(T).name() << endl;  //변수타입(int,float,char,char const *등)이 출력
	cout << data << endl;              //값이 출력
}

typedef struct _tagStudent {

}STUDENT, *PSTUDENT;

class CCar
{
public:
	CCar()
	{}
	~CCar()
	{}

private:

};

enum TEST
{

};

class CTemplate
{
public:
	CTemplate() {}
	~CTemplate() {}

public:
	template <class T, class T1>
	void Output(T a, T1 b)
	{
		cout << a << endl;
		cout << b << endl;

	}

};

template<typename T>
class CTemplate1
{
public:
	CTemplate1()
	{
		cout << "Template1 class Type : " << typeid(T).name() << endl;
	}
	~CTemplate1() {}

private:
	T	m_Data;

public:
	void Output()
	{
		cout << typeid(T).name() << endl;
		cout << m_Data << endl;
	}


};




int main(void) {

	OutputType<int>();
	OutputType<float>();
	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<TEST>();

	Outputdata(10);
	Outputdata(3.1);   //float라고 명시하지 않았으므로 double형으로 출력됨.
	Outputdata(382.383f);
	Outputdata('a');
	Outputdata("ㅋㅋㅋㅋ");

	CTemplate tem;
	tem.Output(10, 3.14f);

	CTemplate1<int> tem1;

	tem1.Output();
	CTemplate1<CTemplate> tem2;

	system("pause");
	return 0;
}