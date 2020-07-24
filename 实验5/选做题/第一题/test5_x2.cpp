//工资管理程序设计
#include<iostream>
using namespace std;
class people{
	protected: 
		float sa_h;//每小时工资额
		float t;//每月工作时数
		int year;// 工龄
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
			cout<<"该工人月工资为："<<sa_h*t+year*35<<endl;
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
			cout<<"该销售员月工资为："<<sa_h*t+year*35+sales*0.01<<endl;
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
			cout<<"该名管理人员月工资为："<<base_sa+year*35<<endl; 
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
