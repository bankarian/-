#include  <iostream> 
using  namespace  std; 
class  Car 
{ 
    public: 
        Car(){} 
        virtual void run()const =0; //���麯������ 
                   
}; 
class Byd:public Car  //������Ķ��� 
{
	public:
		Byd(){}
		virtual void run() const{//��������е�run��const ���ͣ�����Ҫ����һ�� 
			cout <<"running Byd car so easy"<<endl;
		}
};
class Telsa:public Car
{
	public:
		Telsa(){}
		virtual void run() const{//ͬ�� 
			cout <<"running Telsa car so easy"<<endl;
		}
	
};
class  Driver 
{ 
    public: 
        Driver(){} 
        virtual void  drive(Car* c)         
        { //drive���������Ե����������͵�Car�����run���� 
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
        Car* car[n];      //����ָ������ 
        for(int  i=0;i<n;i++) 
        { 
            switch(a[i])         
            { //�����������ж�̬������Ӧ�����������
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
        //����Driver���drive����,ģ��person��ʻ��ͬ�ĳ� 
                person.drive(car[i]);
        } 
        return  0; 
}
