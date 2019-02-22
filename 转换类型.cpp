#include <iostream>  //注意转换构造函数  类型转换函数 不要出现在同一程序！！！**二义** 
using namespace std;
class Complex{
	private:
		int real;
		int imag;
	public:
//		Complex (int a){//转换构造函数  普通构造函数不能再有默认参数  ╮(╯﹏╰）╭ 
//			real=a;
//			imag=0;//构造重载仍然只能在运算符/左侧/生效 
//		}
		
		//希望将类成员重载成的类型   重载后既可以作重载后的类型，也可以原类型 
		operator int (){return real;} //类型转换函数  /*无类型 无参数 只能作为成员函数，转换类对象*/ 
		Complex operator + (Complex a);
		Complex (int a,int b):real(a),imag(b){}
		friend ostream &operator << (ostream &out,Complex &a);
};
ostream &operator << (ostream &out,Complex &a)
{
	out << a.real<<" + "<<a.imag<<"i";
	return out;
}

Complex Complex::operator +(Complex a) //会改变加号左侧的值 
{
	real+=a.real;
	imag+=a.imag;
	return *this;
}
int main()
{
	Complex t1(2,2),t2(0,0),t3(3,3);
	cout<<"initial "<<endl<<"t1: "<<t1<<endl
		<<"t2: "<<t2<<endl
		<<"t3: "<<t3<<endl<<endl;
//	t2=t1+3;
//	cout<<"t2=t1+3   "<<"t2: "<<t2<<endl;
//	t2=t1+t3;
//	cout <<"t2=t1+t3  "<<"t2: "<<t2<<"  t1: "<<t1<<endl;

	int num;
	num=3+t1;  cout<<"类型转换函数被隐式自动调用："<<endl; 
	cout <<"3 + t1(Complex)= num(int) = "<<num<<"  //t1被重载 "<<endl;  
	num=t1+3;
	cout <<"t1 + 3 = num = "<<num<<"   //Complex 类型可在加号任一侧"<<endl; 
	cout <<"t1 :"<<t1<<"   // t1 原有类的属性仍存在，双重身份"<<endl; 
	num=t1+t3;  //可实现多个转换 
	cout <<"num=t1+t3 // num:"<<num<<"  //t1 t3 都被重载"<<endl;
	return 0;
 } 
