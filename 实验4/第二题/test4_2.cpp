#include<iostream>
#include<string>
#define N 40
using namespace std;
class Person{
	public:
		void set_Person()
		{
			cout<<"��������"<<endl;
			cin>>num; 
			cout<<"����������"<<endl;
			cin>>name; 
			cout<<"�������Ա�"<<endl;
			cin>>sex; 
			cout<<"����������"<<endl;
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
			cout<<"������ѧ����ϵ��"<<endl;
			cin>>depart;
			cout<<"������ѧ���ĳɼ�"<<endl;
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
			cout<<"�������ʦ��ְ��"<<endl;
			cin>>job;
			cout<<"�������ʦ�Ĳ���"<<endl;
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
	cout<<"  ���  "<<num;
	cout<<"  ����  "<<name;
	cout<<"  �Ա�  "<<sex;
	cout<<"  ����  "<<year; 
}
void Student::print_St(){
	print_Per();
	cout<<"  ϵ��  "<<depart;
	cout<<"  �ɼ�  "<<score;
	cout<<endl; 
	
}
void Teacher::print_Te()
{
	print_Per();
	cout<<"  ְ��  "<<job;
	cout<<"  ����  "<<section;
	cout<<endl;
}
int main()
{
	int m,n;
	int i;
	cout<<"������ѧ��������";
	cin>>m; 
	Student ss[N];
	for(i=0;i<m;i++)
	{
		ss[i].set_Student();
	}
	cout<<"�������ʦ������";
	cin>>n;
	Teacher tt[N];
	for(i=0;i<n;i++)
	{
		tt[i].set_Teacher();
	}
	cout<<"ѧ���ࣺ"<<endl;
	for(i=0;i<m;i++)
	{
		ss[i].print_St();
	}
	cout<<"��ʦ�ࣺ"<<endl; 
	for(i=0;i<n;i++)
	{
		tt[i].print_Te();
	}
	return 0;
	
	
	
	
	
	
	
}
