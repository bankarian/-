#include <iostream>  /*类外重载的+才可能实现交换律； 类中重载+左边必须是类对象*/ 
using namespace std;/*转换构造函数  类型转换函数 一般不在同一程序中使用 易出现二义性*/ 
class Complex{   //转换构造：把非类的数据转换为  类对象 
	private:		//类型转换函数： 把类的对象 转换为 非类的普通数据 
		int real;
		int imag;
	public:
		Complex (int a){//转换构造函数  普通构造函数不能再有默认参数  ╮(╯﹏╰）╭ 
			real=a;
			imag=0;//构造重载仍然只能在运算符/左侧/生效 
		}
		Complex (int a,int b):real(a),imag(b){}  //声明了转换构造 不能再有默认参数初始。 
		friend Complex operator + (Complex a,Complex b);
		friend ostream &operator << (ostream &out,Complex &a);
};
Complex operator + (Complex a,Complex b)//类外重载 注意是Complex+Complex类型！！ int会被转换构造为类对象 
{			//本质：加号左      加号右 
	return Complex(a.real+b.real,a.imag+b.imag);
}
ostream &operator << (ostream &out,Complex &a)
{
	out << a.real<<" + "<<a.imag<<"i";
	return out;
}
int main()
{
	Complex t1(4,4),t2(0,0);
//	int num=3;
	t2=t1+3;    //3会自动触发转换构造函数，无论在哪边都可 
	cout <<"t2=t1+3 // t2 = "<<t2<<endl;
	cout <<"式中3被构造为Complex对象"<<endl
	<<"所以加号的重载应是Complex+Complex类型**此法可以实现加法交换律**"<<endl; 
	t2=3+t1;
	cout <<"t2=3+t1 // t2 = "<<t2<<endl;
	return 0;
}
