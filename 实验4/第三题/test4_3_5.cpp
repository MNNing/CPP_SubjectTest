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
//���� 
class SortArray:public virtual MyArray{
	public:
		void sort();
		SortArray(int leng):MyArray(leng)
		{
			cout<<"SortArray������Ѵ���."<<endl;
		}
		virtual~SortArray();
};
SortArray::~SortArray()
{
	delete [] alist; 
	cout<<"SortArray����󱻳���."<<endl;
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
//���� 
class ReArray:public virtual MyArray{
	public:
		void Reverse();
		ReArray(int leng);
		virtual ~ReArray();
		
};
ReArray::ReArray(int leng):MyArray(leng){
	cout<<"ReArray������Ѵ���."<<endl; 
};
ReArray::~ReArray()
{
	cout<<"ReArray����󱻳���."<<endl;
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
//ƽ��ֵ 
class AverArray:public virtual MyArray{
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
	delete [] alist;
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
//�ۺ� 
class NewArray:public SortArray,public ReArray,public AverArray{
	public:
		NewArray(int leng):MyArray(leng),SortArray(leng),ReArray(leng),AverArray(leng)
		{
			cout<<"NewArray������Ѵ���"<<endl; 
		};
		~NewArray()
		{
			delete [] alist;
			cout<<"NewArray����󱻳���"<<endl; 
		}
}; 

int main()
{
	NewArray s(5);
	s.Input();
	s.Display("��ʾ������ǰ��");
	s.sort();
	s.Display("��ʾ�����Ժ��"); 
	s.Reverse();
	s.Display("��ʾ�����Ժ��");
	cout<<"����������ƽ��ֵ��"<<s.Aver()<<endl; 
	return 0; 
}	

