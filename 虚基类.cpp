#include <iostream>
#include <string>
using namespace std;
class person{
	protected:
		string name;
		int age;
	public:
		person(string a,int b):name(a),age(b){}		
};
class graduate: virtual public person//��̳� : �����������ֻ����һ����������� 
{
	protected:
		int score;
	public:
		graduate(string a,int b,int c):person(a,b),score(c){}//�������ĳ�ʼֻ����ʽ��������ִ��,����Ҫд 
};
class teacher:virtual public person
{
	protected:
		int wage;
	public:
		teacher(string a,int b,int c):person(a,b),wage(c){}//ͬ�� 
};
class one:public teacher,public graduate//���������� 
{
	protected:
		int mind;
	public: //����ֱ�ӻ����ʼ  ��һ��һ��Ҫ**���������г�ʼ��** 
			//C++ֻ��*����*������������Ĺ��캯�����ã�������������ֹ����γ�ʼ 
		one(string a,int b,int c,int d,int e):person(a,b),teacher(a,b,c),graduate(a,b,d),mind(e){}
		void show()
		{
			cout <<"(����)name : "<<name<<endl;//��̳�  ֻ������һ�����������ݣ��޶����� 
			cout <<"(����)age : "<<age<<endl;
			cout <<"(teacher)wage : "<<wage<<endl;  //�ø����teacher���� 
			cout <<"(graduate)score : "<<score<<endl; //graduate������ 
			cout <<"(one)mind : "<<mind<<endl;
		}
};

int main()
{
	one a("hellokitty",20,100,10000,3);
	a.show();
	return 0;
}
