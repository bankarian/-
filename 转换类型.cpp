#include <iostream>  //ע��ת�����캯��  ����ת������ ��Ҫ������ͬһ���򣡣���**����** 
using namespace std;
class Complex{
	private:
		int real;
		int imag;
	public:
//		Complex (int a){//ת�����캯��  ��ͨ���캯����������Ĭ�ϲ���  �r(�s�n�t���q 
//			real=a;
//			imag=0;//����������Ȼֻ���������/���/��Ч 
//		}
		
		//ϣ�������Ա���سɵ�����   ���غ�ȿ��������غ�����ͣ�Ҳ����ԭ���� 
		operator int (){return real;} //����ת������  /*������ �޲��� ֻ����Ϊ��Ա������ת�������*/ 
		Complex operator + (Complex a);
		Complex (int a,int b):real(a),imag(b){}
		friend ostream &operator << (ostream &out,Complex &a);
};
ostream &operator << (ostream &out,Complex &a)
{
	out << a.real<<" + "<<a.imag<<"i";
	return out;
}

Complex Complex::operator +(Complex a) //��ı�Ӻ�����ֵ 
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
	num=3+t1;  cout<<"����ת����������ʽ�Զ����ã�"<<endl; 
	cout <<"3 + t1(Complex)= num(int) = "<<num<<"  //t1������ "<<endl;  
	num=t1+3;
	cout <<"t1 + 3 = num = "<<num<<"   //Complex ���Ϳ��ڼӺ���һ��"<<endl; 
	cout <<"t1 :"<<t1<<"   // t1 ԭ����������Դ��ڣ�˫�����"<<endl; 
	num=t1+t3;  //��ʵ�ֶ��ת�� 
	cout <<"num=t1+t3 // num:"<<num<<"  //t1 t3 ��������"<<endl;
	return 0;
 } 
