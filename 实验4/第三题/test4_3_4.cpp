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
	cout<<"MyArray类对象已创建."<<endl; 
}	
MyArray::~MyArray()
{
	delete[] alist;
	cout<<"MyArray类对象被撤销."<<endl;
}
void MyArray::Display(string str)
{
	int i;
	int* p=alist;
	cout<<str<<length<<"个整数：";
	for(i=0;i<length;i++,p++)
	   cout<<*p<<"";
	cout<<endl; 
	
}
void MyArray::Input() 
{
	cout<<"请从键盘输入"<<length<<"个整数：";
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
	cout<<"AverArray类对象已创建."<<endl;
	
}
AverArray::~AverArray()
{
	cout<<"AverArray类对象被撤销."<<endl;
	
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
	s.Display("显示输入的");
	cout<<"输入整数的平均值："<<s.Aver()<<endl;
	return 0; 
}	

