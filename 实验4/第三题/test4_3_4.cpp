//test4_3_1.cpp
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class MyArray{
	public:
		MyArray(int leng);
		~MyArray();
		void Input();
		void Display(string);
	protected:
		int * alist;
		int length;
};
MyArray::MyArray(int leng)
{
	if(leng<=0)
	{
		cout<<"error length";
		exit(1);
		
	}
	alist=new int(leng);
	length=leng;
	if(alist==NULL)
	{
		cout<<"assign failure";
		exit(1);
	}
	cout<<"MyArray������Ѵ���."<<endl; 
}	
MyArray::~MyArray()
{
	delete[] alist;
	cout<<"MyArray����󱻳���."<<endl;
}
void MyArray::Display(string str)
{
	int i;
	int* p=alist;
	cout<<str<<length<<"��������";
	for(i=0;i<length;i++,p++)
	   cout<<*p<<"";
	cout<<endl; 
	
}
void MyArray::Input() 
{
	cout<<"��Ӽ�������"<<length<<"��������";
	int i;
	int *p=alist;
	for(i=0;i<length;i++,p++)
	   cin>>*p;
	    
}
class AverArray:public MyArray{
	public:
		AverArray(int leng);
		~AverArray();
		double Aver();
};
AverArray::AverArray(int leng):MyArray(leng)
{
	cout<<"AverArray������Ѵ���."<<endl;
	
}
AverArray::~AverArray()
{
	cout<<"AverArray����󱻳���."<<endl;
	
}
double AverArray::Aver()
{
	int i,result=0;
	int *p=alist;
	for(i=0;i<length;i++,p++)
	{
		result=result+*p;
	}
	return result/length;
}


int main()
{
	AverArray s(5);
	s.Input();
	s.Display("��ʾ�����");
	cout<<"����������ƽ��ֵ��"<<s.Aver()<<endl;
	return 0; 
}	

