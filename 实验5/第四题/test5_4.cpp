//test5_4.cpp
#include<iostream>
#define MAX 100
using namespace std;
class Set{
	public:
		Set();
		void input(int d);
		int length();
		int getd(int i);
		void disp();
		Set operator+(Set s1);
		Set operator-(Set s1);
		Set operator*(Set s1);
		Set operator=(Set s1);
	protected:
		int len;
		int s[MAX];
};
//构造函数 
Set::Set(){
	len=0;
}
//向集合中添加一个元素 
void Set::input(int d)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(d==s[i])
		return;
	}
	s[len]=d;
	len=len+1;
}
//返回集合中元素的个数 
int Set::length()
{
	return len;
}
//返回集合中位置i的元素 
int Set::getd(int i)
{
	return s[i];
}
//输出集合的所有元素 
void Set::disp()
{
	int i;
	cout<<"{";
	for(i=0;i<len;i++)
	{
		cout<<s[i]<<"     ";
	}
	
	cout<<"}"<<endl;
}
//成员运算符重载函数，实现两集合的并运算 
Set Set::operator+(Set s1)
{
	int i;
	Set s2;
	s2=s1;
	for(i=0;i<len;i++)
	{
		s2.input(s[i]);
	}

	return s2;
}
//成员运算符重载函数，实现两集合的差运算 
Set Set::operator-(Set s1)
{
	int i,j,k;
	Set s2;
	for(i=0;i<len;i++)
	{
		k=0;
		for(j=0;j<s1.len;j++)
		{
			if(s[i]==s1.s[j])
			{
				k++;
			}
		}
		if(k==0)
		{
			s2.input(s[i]);
		}
	}
	return s2;
}
//成员运算符重载函数，实现两集合的交运算 
Set Set::operator*(Set s1)
{
	int i,j,k;
	Set s2;
	for(i=0;i<len;i++)
	{
		k=0;
		for(j=0;j<s1.len;j++)
		{
			if(s[i]==s1.s[j])
			{
				k++;
			}
		}
		if(k!=0)
		{
			s2.input(s[i]);
		}
	}
	return s2;
}
//成员运算符重载函数，实现两集合的赋值运算 
Set Set::operator=(Set s1)
{
	int i;
	len=s1.len;
	for(i=0;i<len;i++)
	{
		s[i]=s1.s[i];
	}
}
void makeSet(Set &s0)
{
	int n,i,k;
	cout<<"请输入集合元素的个数:";
	cin>>n;
	cout<<"输入集合元素:";
	for(i=0;i<n;i++)
	{
		cin>>k;
		s0.input(k); 
	}
}
int main()
{
	Set s1,s2,s3,s4,s5;
	makeSet(s1);
	makeSet(s2);
	cout<<"交运算:"<<"s1+s2=";
	s3=s1+s2;
	s3.disp();
	cout<<"差运算:s1-s2=";
	s4=s1-s2;
	s4.disp();
	cout<<"交运算:s1*s2=";
	s5=s1*s2;
	s5.disp();
	return 0;
}
