//test3_x2.cpp
#include<iostream>
#include<string>
using namespace std;
class salary{
	public:
		salary(long no1,string name1,int deal1,int tax1);
		
		void count();
		void output();
		~salary(){
		}
	private:
		long no;
		string name;
		int deal,tax,fact;
}; 
salary::salary(long no1,string name1,int deal1,int tax1)
{
	no=no1;
	name=name1;
	deal=deal1;
	tax=tax1;
}
void salary::count()
{
	fact=deal-tax;
}
void salary::output()
{
	cout<<"����:"<<no<<endl;
	cout<<"����:"<<name<<endl;
	cout<<"Ӧ������:"<<deal<<endl;
	cout<<"˰��:"<<tax<<endl;
	cout<<"ʵ������:"<<fact<<endl; 
}
int main()
{
	int i;
	salary person[5]={
	  salary(001,"����",1500,20),
	  salary(002,"����",1600,20),
	  salary(003,"С��",2000,35),
	  salary(004,"����",3600,39),
	  salary(005,"��q",4000,150)
	                 };
	for(i=0;i<5;i++)
	{
		person[i].count();
		person[i].output();
		cout<<endl;
	}
	return 0;
}
