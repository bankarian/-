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
class graduate: virtual public person//虚继承 : 多个派生对象只保留一个基类的数据 
{
	protected:
		int score;
	public:
		graduate(string a,int b,int c):person(a,b),score(c){}//对虚基类的初始只是形式，并不会执行,但仍要写 
};
class teacher:virtual public person
{
	protected:
		int wage;
	public:
		teacher(string a,int b,int c):person(a,b),wage(c){}//同上 
};
class one:public teacher,public graduate//最后的派生类 
{
	protected:
		int mind;
	public: //对其直接基类初始  且一定一定要**对虚基类进行初始化** 
			//C++只对*最后的*派生类对虚基类的构造函数调用，忽略其他，防止被多次初始 
		one(string a,int b,int c,int d,int e):person(a,b),teacher(a,b,c),graduate(a,b,d),mind(e){}
		void show()
		{
			cout <<"(基类)name : "<<name<<endl;//虚继承  只保留了一份虚基类的数据，无二义性 
			cout <<"(基类)age : "<<age<<endl;
			cout <<"(teacher)wage : "<<wage<<endl;  //该个体的teacher属性 
			cout <<"(graduate)score : "<<score<<endl; //graduate的属性 
			cout <<"(one)mind : "<<mind<<endl;
		}
};

int main()
{
	one a("hellokitty",20,100,10000,3);
	a.show();
	return 0;
}
