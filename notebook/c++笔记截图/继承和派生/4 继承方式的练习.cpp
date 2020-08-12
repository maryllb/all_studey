#include	 <iostream>
using namespace	std;


class	A
{
private:
	int	a;
protected:
	int	b;
public:
	int	c;
	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	void	set(int	a, int	b, int	c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

class	B : public	A
{
public:
	void	print()
	{
		//cout << "a	=	" << a;				 //a�Ǹ����˽�г�Ա���ʲ���
		cout << "b	=	" << b;				 //b ��ʱ�Ǳ�����Ա������ڲ����Է���
		cout << "c	=	"<<c << endl;			//c ��ʱ�ǹ��г�Ա������ڲ����Է���
	}
};

class	C : protected	A
{
public:
	void	print()
	{
		//cout << "a	=	" << a;				 //a�Ǹ����˽�г�Ա���ʲ���
		cout << "b	=	" << b;				 //b ����������protectedȨ�ޣ�����ڲ����Է��ʡ�
		cout << "c	=	" <<c << endl;	 //c �����protected��Ա������ڲ����Է��ʡ�
	}
};

class	D : private	A
{
public:
	void	print()
	{
		//cout << "a	=	" << a;					//a�Ǹ����˽�г�Ա���ʲ���
		cout << "b	=	" << b << endl;		 //b ��ʱ��private��Ա������ڲ����Է��ʡ�
		cout << "c	=	" << c << endl;		 //c ��ʱ��private��Ա������ڲ����Է��ʡ�
	}
};

int	main(void)
{
	A	aa;
	B	bb;
	C	cc;
	D	dd;
	aa.c = 100;					 //c �ǹ��� ������ⲿ���Է��ʡ�
	bb.c = 100;					 //Bpublic �̳���A ������Ȩ�޲��䣬c �ǹ��У� ����ⲿ���Է���
	//cc.c = 100;					 //C protected �̳���A�� c �ڴ�������protected��Ա������ⲿ���ܷ��ʡ�
	//dd.c = 100;					 //D private �̳���A�� c�ڴ�����private��Ա������ⲿ���ܷ��ʡ�
	aa.set(1, 2, 3);			//�ܷ����???
	bb.set(10, 20, 30);			//�ܷ����???
	//cc.set(40, 50, 60);			//�ܷ����???
	//dd.set(70, 80, 90);			//�ܷ����???

	bb.print();					 //print �Ƕ�����B�� public��Ա������������ⲿ���Է��ʡ�
	cc.print();					 //print �Ƕ�����C�� public��Ա������������ⲿ���Է��ʡ�
	dd.print();					 //print �Ƕ�����D�� public��Ա������������ⲿ���Է��ʡ�

	return 0;
}