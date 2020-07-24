//���ʹ���������
#include<iostream>
using namespace std;
class people{
	protected: 
		float sa_h;//ÿСʱ���ʶ�
		float t;//ÿ�¹���ʱ��
		int year;// ����
	public:
	people(float a,float b,int c)
	{
		sa_h=a;
		t=b;
		year=c;
	} 
	virtual void getSalary()=0;
		 
}; 
class worker:public people{
	public:
		worker(float a,float b,int c):people(a,b,c)
		{
			
		}
		void getSalary()
		{
			cout<<"�ù����¹���Ϊ��"<<sa_h*t+year*35<<endl;
		} 
};
class salesman:public people{
	private:
		float sales;
	public:
		salesman(float a,float b,int c,float d):people(a,b,c)
		{
			sales=d;
		}
		void getSalary()
		{
			cout<<"������Ա�¹���Ϊ��"<<sa_h*t+year*35+sales*0.01<<endl;
		}
	
};
class manager:public people{
	private:
		float base_sa;
	public:
		manager(float a,float b,int c,float d):people(a,b,c)
		{
			base_sa=d;
		}
		void getSalary(){
			cout<<"����������Ա�¹���Ϊ��"<<base_sa+year*35<<endl; 
		}
};
int main()
{
	people *p;
	
	worker w(10,240,3);
	p=&w;
	p->getSalary();
	salesman s(15,240,2.5,1000);
	p=&s;
	p->getSalary();
	manager m(0,0,5,4000);
	p=&m;
	p->getSalary();
	return 0;
}
