#include <iostream>
#include <string>
using namespace std;

/*
���ø� : ������ �ܰ迡�� Ÿ���� �������� ����̴�. Ÿ���� �پ��ϰ� �ٲ� �� �ִ�.
template <typename ���ϴ��̸�>�� ���·� ��밡��
template <class ���ϴ��̸�>�� ���·� ��밡��

ex) template<typename T>
void Output()
{
	cout << typeid(T).name() << endl;
}
��ó�� �Լ��� �����  ȣ���
Output<int>(); or Output<float>(); �̷��� ���ָ� int, floatŸ���� ��������. ��Ȳ�� ���� �־��ִ� Ÿ������
Ÿ���� ���������� �ٲ�� ���̴�. ����Ÿ���� �������� �������� �� �ִ�.
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
	cout << typeid(T).name() << endl;  //����Ÿ��(int,float,char,char const *��)�� ���
	cout << data << endl;              //���� ���
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
	Outputdata(3.1);   //float��� ������� �ʾ����Ƿ� double������ ��µ�.
	Outputdata(382.383f);
	Outputdata('a');
	Outputdata("��������");

	CTemplate tem;
	tem.Output(10, 3.14f);

	CTemplate1<int> tem1;

	tem1.Output();
	CTemplate1<CTemplate> tem2;

	system("pause");
	return 0;
}