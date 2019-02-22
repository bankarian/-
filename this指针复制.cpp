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
	A *temp(this);//指向相同 
	a+=10;
	return *temp; //复制后内容随着改变 
}
A A::func2()
{//重载后置运算符时可用此种方法~ 
	A temp(*this);//存储此时的this中的内容
	a+=10;
	return temp; //temp内容不会改变 
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
