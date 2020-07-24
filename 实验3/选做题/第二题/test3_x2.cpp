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
	cout<<"工号:"<<no<<endl;
	cout<<"姓名:"<<name<<endl;
	cout<<"应发工资:"<<deal<<endl;
	cout<<"税金:"<<tax<<endl;
	cout<<"实发工资:"<<fact<<endl; 
}
int main()
{
	int i;
	salary person[5]={
	  salary(001,"张三",1500,20),
	  salary(002,"李四",1600,20),
	  salary(003,"小黑",2000,35),
	  salary(004,"王五",3600,39),
	  salary(005,"阿q",4000,150)
	                 };
	for(i=0;i<5;i++)
	{
		person[i].count();
		person[i].output();
		cout<<endl;
	}
	return 0;
}
