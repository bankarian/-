#include <iostream>  /*�������ص�+�ſ���ʵ�ֽ����ɣ� ��������+��߱����������*/ 
using namespace std;/*ת�����캯��  ����ת������ һ�㲻��ͬһ������ʹ�� �׳��ֶ�����*/ 
class Complex{   //ת�����죺�ѷ��������ת��Ϊ  ����� 
	private:		//����ת�������� ����Ķ��� ת��Ϊ �������ͨ���� 
		int real;
		int imag;
	public:
		Complex (int a){//ת�����캯��  ��ͨ���캯����������Ĭ�ϲ���  �r(�s�n�t���q 
			real=a;
			imag=0;//����������Ȼֻ���������/���/��Ч 
		}
		Complex (int a,int b):real(a),imag(b){}  //������ת������ ��������Ĭ�ϲ�����ʼ�� 
		friend Complex operator + (Complex a,Complex b);
		friend ostream &operator << (ostream &out,Complex &a);
};
Complex operator + (Complex a,Complex b)//�������� ע����Complex+Complex���ͣ��� int�ᱻת������Ϊ����� 
{			//���ʣ��Ӻ���      �Ӻ��� 
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
	t2=t1+3;    //3���Զ�����ת�����캯�����������ı߶��� 
	cout <<"t2=t1+3 // t2 = "<<t2<<endl;
	cout <<"ʽ��3������ΪComplex����"<<endl
	<<"���ԼӺŵ�����Ӧ��Complex+Complex����**�˷�����ʵ�ּӷ�������**"<<endl; 
	t2=3+t1;
	cout <<"t2=3+t1 // t2 = "<<t2<<endl;
	return 0;
}
