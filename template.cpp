#include <iostream>
using namespace std;
template <class numtype>  //�޷ֺ�
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
	HH <int> a(4,7);  //����ʵ�� 
	cout <<a.max()<<" is the bigger one."<<endl;
	HH <float> b(8.12,8.13); //����ʵ��  ����÷���ͨ 
	cout <<b.max()<<" is the bigger one."<<endl;
	return 0;
}
