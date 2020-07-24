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
class SortArray:public MyArray{
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

int main()
{
	SortArray s(5);
	s.Input();
	s.Display("��ʾ������ǰ��");
	s.sort();
	s.Display("��ʾ�����Ժ��"); 
	return 0; 
}	

