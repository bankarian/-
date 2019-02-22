#include <iostream>
using namespace std;
template <class numtype>  //无分号
class HH{
	public:
		numtype max();
		HH(numtype n,numtype m):a(n),b(m){}
	private:
		numtype a,b;
}; 
template <class numtype>
numtype HH<numtype>::max()
{
	return (a>b)?a:b;
}
int main()
{
	HH <int> a(4,7);  //类型实化 
	cout <<a.max()<<" is the bigger one."<<endl;
	HH <float> b(8.12,8.13); //类型实化  后边用法普通 
	cout <<b.max()<<" is the bigger one."<<endl;
	return 0;
}
