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
//���캯�� 
Set::Set(){
	len=0;
}
//�򼯺������һ��Ԫ�� 
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
//���ؼ�����Ԫ�صĸ��� 
int Set::length()
{
	return len;
}
//���ؼ�����λ��i��Ԫ�� 
int Set::getd(int i)
{
	return s[i];
}
//������ϵ�����Ԫ�� 
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
//��Ա��������غ�����ʵ�������ϵĲ����� 
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
//��Ա��������غ�����ʵ�������ϵĲ����� 
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
//��Ա��������غ�����ʵ�������ϵĽ����� 
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
//��Ա��������غ�����ʵ�������ϵĸ�ֵ���� 
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
	cout<<"�����뼯��Ԫ�صĸ���:";
	cin>>n;
	cout<<"���뼯��Ԫ��:";
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
	cout<<"������:"<<"s1+s2=";
	s3=s1+s2;
	s3.disp();
	cout<<"������:s1-s2=";
	s4=s1-s2;
	s4.disp();
	cout<<"������:s1*s2=";
	s5=s1*s2;
	s5.disp();
	return 0;
}
