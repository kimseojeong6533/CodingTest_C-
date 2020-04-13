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
	
	//C++������ ����ü�ȿ��� �����ڸ� ���� �� ����
	_tagPoint() : //����ü ������ �ʱ�ȭ(�̴ϼȶ������̿�)
		x(0),
		y(0)    //_tagPoint�� ȣ��Ǹ� x,y�� ���� 0,0���� ���Ե�.
	{
	}

	_tagPoint(int _x,int _y) :  //�̴ϼȶ������� �̿��� �������ʱ�ȭ
		x(_x),                  //x�� _x�� �����϶�� �� 
		y(_y)				    //y�� _y�� �����϶�� ��
								//_tagPoint(10,20)�̸�,x�� 10, y�� 20�̶�� ���� ��.
	{
	}

	_tagPoint(const _tagPoint& pt)
	{
		*this = pt;  //this�� �ڱ��ڽ��� ������ (�ڱ��ڽ��� �������Ͽ� ��絥���͸� �����ϰ� ��.)
	}

	_tagPoint operator + (const _tagPoint& pt)
	{
		_tagPoint result;
		result.x = x + pt.x; //�����Լ����� pt3 = pt1 + pt2;���� pt1�� x�� x, pt2�� x�� pt.x�� ���� result.x�� pt3�� x������ ���� ��
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
�Լ������� : �Լ��� �޸��ּҸ� �����ϱ����� �����ͺ����� ������ �� �ִ�. 

�����Լ��� ���, �Լ����� �� �Լ��� �޸��ּ��̴�. 
�Լ������� ������ : ��ȯŸ��(*�����ͺ�����)(����Ÿ��);�� ����
*/

	int(*pFunc)(int, int)=Sum; //�Լ������� pFunc�� (�����Լ�)Sum�Լ��� ����Ű���� ����
	cout << pFunc(10, 20) << endl;
	pFunc = OutSum;            //�Լ������� pFunc�� OutSum�Լ��� ����Ű���� ����
	cout << pFunc(10,20) << endl;
	//pFunc = Output; //����(��ȯŸ�԰� ���ڰ� �ٸ��Ƿ� ������)
	void(*pFunc_Output)() = Output;  //pFunc_Output�̶�� ���ο� �Լ������͸� �����Ͽ� Output�Լ��� ����Ű���� ����
	pFunc_Output(); //�Լ������͸�+()���� �ٿ���� ��.


	CHanzo hanzo1, hanzo2;
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	/*
	this ������ :  Ŭ�����ȿ��� this�� ����� ���, �ش� ��ü�� �޸� �ּҰ� �ȴ�. ��, �ڱ��ڽ��� �������̴�. 	
	*/
	//����Լ��� ȣ���� �� this�� ȣ���ڷ� �����Ѵ�. 
	hanzo1.Output();
	hanzo2.Output();

	//����Լ������ͼ����, �����ͺ��� �̸��տ� 'Ŭ������ ::' �� �ٿ���. (::�� �������������ڶ�� �� �Ǵ� scope������)
	void(CHanzo::*pFunc2)(int,int)= &CHanzo::Sumand;    
	//(*pFunc2)  -> ����
	(hanzo1.*pFunc2)(4,5);    //�����Լ������Ϳ� Ŭ��������Լ��������� ���°� �ٸ��� ������ ���°� �޶� ������
	                          // -> C++11���� functional�̶�� ����� ���� �����Լ�, ����Լ� �����ϰ� �Լ������͸� �̿�
	                          //�Ͽ� ����� �� �ֵ��� �Ͽ���. -> #include <functional>�߰� �ʿ�


	/*
	function����� C++11���� �������ִ� ���, �� ����� �Լ������͸� ����,��� �������ʰ� ���� �ּҸ� �����ؼ�
	ȣ�����ټ� �ֵ��� ������ִ� ���.
	������ :  function<����Ÿ��(����Ÿ��)> ������;
	*/

	function<void()>	func;
	function<void()>	func1;

	//bind�Լ��� �̿��ؼ� �Լ��� ������.  �Լ������͸� = bind(�Լ���,���ڸ���Ʈ);
	func = bind(Output);  //func���� �����Լ�Output�� ��(���ڰ� �����Ƿ� ����)
	func1 = bind(&CHanzo::Output, &hanzo1);  //func1���� CHanzo Ŭ�������� Output�Լ��� �� 


	cout << "==============Functional=============" << endl;
	func();
	func1();

	cout << "=========placeholders�̿�========" << endl;
	function<int(int, int)> func3;
	//�Լ��� ���ڰ� ���� ���, (placeholders::_1, _2)�� �̿��ؼ� ������ ������ ������ �� �ִ�. (_1,_2)->10-20 / (_2,_1) -> 20-10
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);  
	func3(10, 20);
	cout << endl;
	cout << "===============Point=============" << endl;
	POINT pt1(10,20), pt2(30,40), pt3;

	pt3 = pt1 + pt2;  //���� ����ü������ ������ �Ұ��� but, Operator�� ����ϸ� ����
	                  //+�����ڰ� operator�� ������ �Ǿ� �����Ƿ� +������ �����ϰԵȴ�.
	                  //pt1�� +������ �Լ��� ȣ�����ָ鼭 pt2�� ���ڷ� �Ѱ��ش�.

	pt3 << pt2;
	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;
	pt1 << pt3;
	cout << "x : " << pt1.x << "\ty : " << pt1.y << endl;
	pt3 = pt3 + 1000;
	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;

	return 0;
}