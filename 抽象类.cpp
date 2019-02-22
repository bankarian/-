#include <iostream>
#define pi 3.1415926
using namespace std;
class Shape{//������� 
	public:
		virtual float area() const=0;//���麯��
		virtual void name() =0;
};
class Circle:public Shape//Բ 
{
	protected:
		float r;
	public:
		Circle(float a=2.0):r(a){}
		~Circle(){}
		virtual void name()
		{
			cout <<"Circle here"<<endl;
		}
		virtual float area() const  //���麯��Ϊconst ���ͣ���������е�ҲӦҪconst 
		{							//������ ����() ���� ��Ҫ��ͬ 
			return (pi*r*r);
		}
};
class Square:public Shape//������ 
{
	protected:
		float len;
	public:
		Square(float a=2.0):len(a){}
		~Square(){}
		virtual void name()
		{
			cout <<"Square here"<<endl;
		}
		virtual float area() const
		{
			return (len*len);
		}
};
class cube:public Square//������
{
	protected:
		float height;
	public:
		cube(float a=2.0,float b=2.0):Square(a),height(b){}
		virtual void name()
		{
			cout <<"Cube here"<<endl;
		}
		float volumn()
		{
			return (height*len*len);
		}
 } ;
int main()
{
	Shape *p; 
	Circle cc(4.0);
	Square ss(3.0);
	cube hh(3.0,5.0);
	p=&cc;
	p->name();
	cout << p->area()<<endl;
	p=&ss;
	p->name();
	cout << p->area();
	cout <<endl;
	return 0;
 } 
