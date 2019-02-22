#include <iostream>
using namespace std;
class Complex{
	private:
		int real;
		int imag;
	public:
//		Complex operator + (int a);//类中定义 运算符左侧只能是类对象 
		friend Complex operator + (Complex a,int b);//类外定义 同上 
		friend Complex operator + (int b,Complex a);//加号左侧为整型时  ,括号内即为运算符左右 
		Complex (int a=0,int b=0):real(a),imag(b){}
		friend ostream &operator << (ostream &out,Complex &a);
};
//Complex Complex::operator + (int a)
//{//  若为(int &a) 则不能计算 t1+3,3“没有”地址(只是这么说好理解)，只能定义一个整型变量来相加 
//	return Complex(real+a,imag);
//}
Complex operator + (Complex a,int b)
{				//等号  左       右
	return Complex(a.real+b,a.imag); 
}
Complex operator + (int b,Complex a) 
{				//等号  左       右
	return Complex(a.real+b,a.imag); 
}
///////////////////////////多种加号重载比较 
//Complex Complex::operator +(Complex a) //不会改变加号左侧的值 
//{
//	Complex c(0,0); //自己显式建立一个临时对象 来返回 
//	c.real=a.real+real;
//	c.imag=a.imag+imag;
//	return c;
//}

//Complex Complex::operator +(Complex a) //不会改变加号左侧的值 
//{
//	return Complex(a.real+real,a.imag+imag);  //返回一个临时建立的对象 
//} 

//Complex Complex::operator +(Complex a) //会改变加号左侧的值 
//{
//	real+=a.real;
//	imag+=a.imag;
//	return *this;
//}
//////////////////////////////////////// 
ostream &operator << (ostream &out,Complex &a)//重载输入输出  要记得用引用形式 
{
	out << a.real<<" + "<<a.imag<<"i";
	return out;
}

int main()
{
	Complex t1(12,2),t2;
//	int a=3;
//	t2=3+t1;  //类内定义时编译失败  类内定义局限性 
	t2=t1+3; 
	cout <<t2<<endl;
	t2=3+t2;
	cout <<t2<<endl; 
	return  0;
 } 
