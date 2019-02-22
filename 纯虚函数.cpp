#include  <iostream> 
using  namespace  std; 
class  Car 
{ 
    public: 
        Car(){} 
        virtual void run()const =0; //纯虚函数定义 
                   
}; 
class Byd:public Car  //派生类的定义 
{
	public:
		Byd(){}
		virtual void run() const{//抽象基类中的run是const 类型，类型要保持一致 
			cout <<"running Byd car so easy"<<endl;
		}
};
class Telsa:public Car
{
	public:
		Telsa(){}
		virtual void run() const{//同上 
			cout <<"running Telsa car so easy"<<endl;
		}
	
};
class  Driver 
{ 
    public: 
        Driver(){} 
        virtual void  drive(Car* c)         
        { //drive函数，可以调用任意类型的Car对象的run函数 
			c->run();   
        } 
}; 
int  main() 
{ 
        int  n; 
        cin  >>  n; 
        int  a[n]; 
        for(int  i=0;i<n;i++) 
            cin >>  a[i]; 
        Car* car[n];      //基类指针数组 
        for(int  i=0;i<n;i++) 
        { 
            switch(a[i])         
            { //根据输入序列动态生成相应的派生类对象
				case 1:{
					Byd JD;
					car[i]=&JD;
					break;
				}
				case 2:{
					Telsa BENZ;
					car[i]=&BENZ;
					break;
				}
            } 
        } 
                cout  <<  "***"  <<  endl; 
        Driver  person; 
        for(int  i=0;i<n;i++)         
        { 
        //调用Driver类的drive函数,模拟person驾驶不同的车 
                person.drive(car[i]);
        } 
        return  0; 
}
