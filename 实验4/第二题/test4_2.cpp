#include<iostream>
#include<string>
#define N 40
using namespace std;
class Person{
	public:
		void set_Person()
		{
			cout<<"请输入编号"<<endl;
			cin>>num; 
			cout<<"请输入姓名"<<endl;
			cin>>name; 
			cout<<"请输入性别"<<endl;
			cin>>sex; 
			cout<<"请输入年龄"<<endl;
			cin>>year; 
		}
		void print_Per();
	private:
		long num;
		string name;
		string sex;
		int year;
		
};
class Student:public Person{
	public:
		void set_Student(){
			set_Person();
			cout<<"请输入学生的系别"<<endl;
			cin>>depart;
			cout<<"请输入学生的成绩"<<endl;
			cin>>score; 
			cout<<endl;
		}
		void print_St();
	private:
		string depart;
		float score;
};
class Teacher:public Person{
	public:
		void set_Teacher(){
			
			set_Person();
			cout<<"请输入教师的职称"<<endl;
			cin>>job;
			cout<<"请输入教师的部门"<<endl;
			cin>>section; 
			cout<<endl;
		}
		void print_Te();
	private:
		string job;
		string section;
};
void Person::print_Per()
{
	cout<<"  编号  "<<num;
	cout<<"  姓名  "<<name;
	cout<<"  性别  "<<sex;
	cout<<"  年龄  "<<year; 
}
void Student::print_St(){
	print_Per();
	cout<<"  系别  "<<depart;
	cout<<"  成绩  "<<score;
	cout<<endl; 
	
}
void Teacher::print_Te()
{
	print_Per();
	cout<<"  职称  "<<job;
	cout<<"  部门  "<<section;
	cout<<endl;
}
int main()
{
	int m,n;
	int i;
	cout<<"请输入学生人数：";
	cin>>m; 
	Student ss[N];
	for(i=0;i<m;i++)
	{
		ss[i].set_Student();
	}
	cout<<"请输入教师人数：";
	cin>>n;
	Teacher tt[N];
	for(i=0;i<n;i++)
	{
		tt[i].set_Teacher();
	}
	cout<<"学生类："<<endl;
	for(i=0;i<m;i++)
	{
		ss[i].print_St();
	}
	cout<<"教师类："<<endl; 
	for(i=0;i<n;i++)
	{
		tt[i].print_Te();
	}
	return 0;
	
	
	
	
	
	
	
}
