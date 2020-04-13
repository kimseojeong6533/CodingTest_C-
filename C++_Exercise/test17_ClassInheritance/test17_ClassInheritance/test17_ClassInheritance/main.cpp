#include <iostream>
using namespace std;

/*
��� : Ŭ������ Ŭ�������� �θ�,�ڽİ��踦 ������ �� ����. �ڽ�	Ŭ������ �θ�Ŭ������ ����������� ��밡���ϴ�
		��, �θ�Ŭ�������� public�̳� protected�� �Ǿ� �ִ� ������� ��밡��, private���� �Ǿ� �ִ� ������� ���Ұ�

����� ���� :  public, private ����� �ִ�. 

������ : ��Ӱ��迡 �ִ� �� Ŭ�������� ���� ����ȯ�� ������ ������ ���Ѵ�.

�����Լ� :  �Լ� �������̵� �̶�� �θ���. �Լ��� �������ϴ� ����̴�. ����Լ� �տ� virtualŰ���带 ������ �ش��Լ�
			�� �����Լ��� �ȴ� , ���� CParentŬ������ virtual Output()�Լ��� �ִٸ� �ڽ�Ŭ���������� �� �����Լ��� 
			������ �� �� �ִ�. �����Ǵ� �Լ��̸��� ���ڰ� ������ �Ȱ��ƾ� �Ѵ�. 

			�����Լ��� ������ �ִ� Ŭ������ ���������� �����Լ����̺��̶�� ���� �����Ѵ�. �����Լ� ���̺��� �����Լ�
			�� �޸� �ּҸ� �����ϴ� ���̺��̴�. ����, CParent�� Output�� �����Լ��̰� CChildŬ������ Output�� ������
			�Ѵٸ�, �׷� ��, CChild��ü�� �����ϸ� �����Լ� ���̺��� CChildŬ������ Output�ּҰ� �ö󰡰� �ȴ�. 
			����, CParent��ü�� �����Ѵٸ� CParent�� Output�Լ��ּҰ� �ö󰡰� �ȴ�. �׷��� Output�Լ�, ��, �����Լ���
			ȣ���ϰ� �Ǹ� ����, �����Լ� ���̺��� �����ؼ� �޸��ּҸ� Ȯ���Ѵ�. �����Լ� ���̺� CChild�� Output�Լ�
			�ּҰ� ����ִٸ� �� �ּ��� �Լ��� ȣ�����ִ� �����̴�. 
			**�θ�Ŭ������ �Ҹ��ڴ� �׻� �����Լ��� ����� ����.


cf) �Լ������ε� : �����Լ����̴��� ����Ÿ�԰� ������ �Լ��� �����Ͽ� ���� �������ִ� ��.
*/

class CParent
{
public:
	CParent()
	{
		m_iB = 1000;
		m_iC = 2000;
		cout << "CParent ������" << endl;
	}
	virtual ~CParent() 
	{
		cout << "CParent �Ҹ���" << endl;
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
		cout << "Parent Output ���" << endl;
	}
	//���������Լ� : �Լ��ڿ� = 0 �� �ٿ��ָ�, �ش� �����Լ��� ���������Լ��� �ȴ�. 
	//���������Լ��� �����κ��� �������� �ʴ´�.(������ �ڽ�Ŭ�������� �� �� ����.)
	//���������Լ��� ������ �ִ� Ŭ���� : �߻�Ŭ����  ->�Ʒ��κ��������ؼ� CParentŬ������ �߻�Ŭ������ �Ǿ���
	//�߻�Ŭ������ �ν��Ͻ�(��ü)������ �Ұ����ϴ�.
	//���������Լ��� �ڽĿ��� �ݵ�� ������ �ؾ��Ѵ�. �ֳ��ϸ� �θ��� ���������Լ��� ���Ǻκ��� ������
	//�ݵ�� �ڽĿ��� �������� �������� ���� �Լ��̱� �����̴�. (������ ������, �ܺο��� �ڽ�Ŭ������ ��ü�� �������� ����	)
	virtual void OutputPure() = 0;
	
};

class CChild : public CParent  //ChildŬ������ ParentŬ����(public)�� ��ӹ���
{
public:
	CChild() 
	{
		m_iB = 200;  //m_iB�� protected�̹Ƿ� �ڽ�Ŭ������ ������ �� ����
		//m_iC = 300;  //m_iC�� private�̱� ������ �ڽ�Ŭ������ ������ �� ���� 
		cout << "CChild ������" << endl;
	}
	virtual ~CChild()
	{
		cout << "CChild �Ҹ���" << endl;
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
		cout << "Child Output���" << endl;
	}
	virtual void OutputPure()  //���������Լ� ������
	{

	}
};

class CChild1 : private CParent  //ChildŬ������ ParentŬ����(private)�� ��ӹ���
{
public:
	CChild1()
	{
		cout << "CChild1 ������" << endl;
	}
	~CChild1()
	{
		cout << "CChild1 �Ҹ���" << endl;
	}
	virtual void OutputPure()
	{}
private:
	int		m_iD;
};

class CChildChild : public CChild  //ChildChildŬ������ ChildŬ������ ��ӹ���
{
public:
	CChildChild()
	{
		m_iD = 500;
		cout << "CChildChild ������" << endl;
	}
	~CChildChild()
	{
		cout << "CChildChild �Ҹ���" << endl;
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
	
	//child1.m_iA = 300; //Ŭ�����ܺο��� �����Ҷ�, child1�� ���, parentŬ������ private���� ��ӹ޾ұ� ������ m_iA�� public��������� ���ٺҰ�
	                   //�ٸ�, child1Ŭ������ ���ο����� ���ٰ�����. 
	//parent.Output();
	//child1.Output(); //Ŭ�����ܺο��� �θ�Ŭ���� ���ٺҰ� (CChild1Ŭ������ CParentŬ������ private���� ��ӹް� �ֱ�
	                   //������ CParent���� public���� �Ǿ� �ִ� ����鵵 �ܺο����� ���ٺҰ�

	//CParent cparent;  //���������Լ� ������ CParentŬ������ ��ü������ �Ұ���,�����ͺ����� ����
	CParent* cparent2;
								      //CChildŬ������ CParentŬ������ ��ӹް� �ִ�. 
	CParent* pParent = new CChild;    //new CChild�� CChild��ü�ϳ��� �����ϰ� �� �޸��ּҸ� ��ȯ��. 
	//CParent* pParent1 = new CChild1;  //������ CChild1Ŭ������ private���� ParentŬ������ ��ӹ����Ƿ� �����Լ����� ���ٺҰ�
									  //���� �����Լ����� ������ CParentŬ���������Ͱ� CChild1��ü�� �޸� �ּҸ� ���� �� ���� ��.
	
	CParent* pParent2 = new CChildChild;   //���ʿ����� CParent* Ÿ�� ������ �� ��ȯ�� �ּҸ� �������ְ� ����. 
								           //�θ�������Ÿ�Կ� CChild ��ü�� �޸��ּҸ� ���� �� �ִ� ������ ��Ӱ��迡 �ֱ� ����
				                           //�ڽ� �޸��ּҸ� �θ�������Ÿ������ ����ȯ �� ��. �̰��� ��ĳ�����̶� ��.(�ڽ�->�θ�Ÿ��)  
                                           //�θ�->�ڽ�Ÿ������ ����ȯ : �ٿ�ĳ���� 
	
	//�Ʒ� �� Ŭ������ ��� CParentŬ������ ��ӹް� �ִ�. 
	//�׷��Ƿ� pParent�� ��Ÿ�� ��� �ٿ�ĳ���� �����ϴ�. 
	/*�׷���  pParent�� CChild�� �Ҵ��� ��ü�̴�. �� ��ü�� CChild1Ÿ������ �ٿ�ĳ�����ϰ� �Ǹ� ������ �߻��� �� �ִ�.
	  �ֳ��ϸ� ���ʿ� ������ ��ü�� �ƴ� �ٸ� Ÿ������ ��ȯ�Ʊ� �����̴�. 
	*/
	CChild* pChild = (CChild*)pParent; //�ڽ� -> �θ�Ÿ������ ����ȯ
	CChild1* pChild1 = (CChild1*)pParent;

	((CChild*)pParent)->ChildOutput();  //pParent�� CChildŬ������ ����ȯ���� ������ pParent�� �ڽ�Ŭ������ CChild�� �ִ�
										//ChildOutput()�Լ��� ����� �� ����. �ֳ��ϸ�, pParent�� CParentŬ������ ������Ÿ���̱� ������
										//�׷��� �θ�Ŭ������ �����ͺ����� �ݵ�� �ڽ�Ŭ����������Ÿ������ ����ȯ�� �ڿ� �ڽ�Ŭ������ �Լ��� ����ؾ��Ѵ�.

	pParent->CParent::Output();  //�θ�Ŭ������ Output�Լ�(�����Լ�) ȣ��, �ڽ�Ŭ�����������ּҰ� �����Լ����̺� �ۼ�������, ��������� ���ָ� �θ�Ŭ������ �����Լ� ��밡�� 
	pParent->Output();  //�ڽ�Ŭ������ Output�Լ� ȣ��, 
	delete pParent; //delete pParent�� �ϰԵǸ�, �θ�Ŭ����������->�ڽ�Ŭ����������->�θ�Ŭ������ �Ҹ��ڰ� ������� ȣ��ȴ�.
					//�ڽ�Ŭ������ �Ҹ��ڰ� ȣ����� �ʴ� ������, pParent�� �ٺ������� CParentŬ������ ������Ÿ��
					//�̱� �����̴�. 

	CParent* pParentArr[2] = {};   //�θ�Ŭ������ �����͹迭�� �ڽ�Ŭ����, �ڽ����ڽ�Ŭ���� �� �������� Ŭ������ ������ �� ����. 
	pParentArr[0] = new CChild;   
	pParentArr[1] = new CChildChild;



	return 0;
}

/*
��Ӱ��迡���� ������ ȣ����� : �θ�����ڳ��� -> �ڽĻ����ڳ��� 
��Ӱ��迡���� �Ҹ��� ȣ����� : �ڽļҸ��ڳ��� -> �θ�Ҹ��ڳ���
*/