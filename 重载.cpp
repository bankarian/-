#include <iostream>
using namespace std;
class Complex{
	private:
		int real;
		int imag;
	public:
//		Complex operator + (int a);//���ж��� ��������ֻ��������� 
		friend Complex operator + (Complex a,int b);//���ⶨ�� ͬ�� 
		friend Complex operator + (int b,Complex a);//�Ӻ����Ϊ����ʱ  ,�����ڼ�Ϊ��������� 
		Complex (int a=0,int b=0):real(a),imag(b){}
		friend ostream &operator << (ostream &out,Complex &a);
};
//Complex Complex::operator + (int a)
//{//  ��Ϊ(int &a) ���ܼ��� t1+3,3��û�С���ַ(ֻ����ô˵�����)��ֻ�ܶ���һ�����ͱ�������� 
//	return Complex(real+a,imag);
//}
Complex operator + (Complex a,int b)
{				//�Ⱥ�  ��       ��
	return Complex(a.real+b,a.imag); 
}
Complex operator + (int b,Complex a) 
{				//�Ⱥ�  ��       ��
	return Complex(a.real+b,a.imag); 
}
///////////////////////////���ּӺ����رȽ� 
//Complex Complex::operator +(Complex a) //����ı�Ӻ�����ֵ 
//{
//	Complex c(0,0); //�Լ���ʽ����һ����ʱ���� ������ 
//	c.real=a.real+real;
//	c.imag=a.imag+imag;
//	return c;
//}

//Complex Complex::operator +(Complex a) //����ı�Ӻ�����ֵ 
//{
//	return Complex(a.real+real,a.imag+imag);  //����һ����ʱ�����Ķ��� 
//} 

//Complex Complex::operator +(Complex a) //��ı�Ӻ�����ֵ 
//{
//	real+=a.real;
//	imag+=a.imag;
//	return *this;
//}
//////////////////////////////////////// 
ostream &operator << (ostream &out,Complex &a)//�����������  Ҫ�ǵ���������ʽ 
{
	out << a.real<<" + "<<a.imag<<"i";
	return out;
}

int main()
{
	Complex t1(12,2),t2;
//	int a=3;
//	t2=3+t1;  //���ڶ���ʱ����ʧ��  ���ڶ�������� 
	t2=t1+3; 
	cout <<t2<<endl;
	t2=3+t2;
	cout <<t2<<endl; 
	return  0;
 } 
