//test4_3_2.cpp
#include<iostream>
#include<string>
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
class SortArray:public MyArray{
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

int main()
{
	SortArray s(5);
	s.Input();
	s.Display("显示排序以前的");
	s.sort();
	s.Display("显示排序以后的"); 
	return 0; 
}	

