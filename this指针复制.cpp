#include <iostream>
using namespace std;
class A{
	public:
		int a;
		A func1();
		A func2();
		A(int n=3):a(n){}
}; 
A A::func1()
{
	A *temp(this);//ָ����ͬ 
	a+=10;
	return *temp; //���ƺ��������Ÿı� 
}
A A::func2()
{//���غ��������ʱ���ô��ַ���~ 
	A temp(*this);//�洢��ʱ��this�е�����
	a+=10;
	return temp; //temp���ݲ���ı� 
}

int main()
{
	A k,b;
	k=b.func1();
	cout <<"func1 before "<<k.a<<endl
		<<"func1 later "<<b.a<<endl<<endl;
	A x,y;
	x=y.func2();
	cout <<"func2 before "<<x.a<<endl
		<<"func2 later "<<y.a<<endl;
}
