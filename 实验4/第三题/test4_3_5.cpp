//test4_3_5.cpp
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
//排序 
class SortArray:public virtual MyArray{
	public:
		void sort();
		SortArray(int leng):MyArray(leng)
		{
			cout<<"SortArray类对象已创建."<<endl;
		}
		virtual~SortArray();
};
SortArray::~SortArray()
{
	delete [] alist; 
	cout<<"SortArray类对象被撤销."<<endl;
}
void SortArray::sort()
{
	int i,j,term;
	int *p=alist;
	for(i=0;i<length;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(p[i]>p[j])
			{
				term=p[i];
				p[i]=p[j];
				p[j]=term;
			}
		}
	}
}
//倒置 
class ReArray:public virtual MyArray{
	public:
		void Reverse();
		ReArray(int leng);
		virtual ~ReArray();
		
};
ReArray::ReArray(int leng):MyArray(leng){
	cout<<"ReArray类对象已创建."<<endl; 
};
ReArray::~ReArray()
{
	cout<<"ReArray类对象被撤销."<<endl;
}
void ReArray::Reverse()
{
	int i,j;
	int *p=alist;
	int *t=alist;
	int term;
	for(i=0,j=length-1;i<j;i++,j--)
	{
		term=p[i];
		p[i]=t[j];
		t[j]=term;
	}
}
//平均值 
class AverArray:public virtual MyArray{
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
	delete [] alist;
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
//综合 
class NewArray:public SortArray,public ReArray,public AverArray{
	public:
		NewArray(int leng):MyArray(leng),SortArray(leng),ReArray(leng),AverArray(leng)
		{
			cout<<"NewArray类对象已创建"<<endl; 
		};
		~NewArray()
		{
			delete [] alist;
			cout<<"NewArray类对象被撤销"<<endl; 
		}
}; 

int main()
{
	NewArray s(5);
	s.Input();
	s.Display("显示排序以前的");
	s.sort();
	s.Display("显示排序以后的"); 
	s.Reverse();
	s.Display("显示倒置以后的");
	cout<<"这组整数的平均值："<<s.Aver()<<endl; 
	return 0; 
}	

