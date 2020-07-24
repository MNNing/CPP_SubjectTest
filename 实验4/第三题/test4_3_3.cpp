//test4_3_3.cpp
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
class ReArray:public MyArray{
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
int main()
{
	ReArray s(5);
	s.Input();
	s.Display("显示倒置以前的");
	s.Reverse();
	s.Display("显示倒置以后的"); 
	return 0; 
}	

