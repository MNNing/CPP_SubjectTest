//test2_3_1.cpp
#include<iostream>
using namespace std;
int Find_max(int a,int b);
int Find_max(int a,int b,int c);
double Find_max(double a,double b);
double Find_max(double a,double b,double c);
int main()
{
	int x,y;
	cout<<"Enter two int number:"<<endl;
	cin>>x>>y;
	Find_max(x,y);
	int z;
	cout<<"Enter three int number:"<<endl;
	cin>>x>>y>>z;
	Find_max(x,y,z);
	double o,p,t;
	cout<<"Enter two double number:"<<endl;
	cin>>o>>p;
	Find_max(o,p);
	cout<<"Enter three double number:"<<endl;
	cin>>o>>p>>t;
	Find_max(o,p,t);
	
}
int Find_max(int a,int b)
{
	if(a>=b)
	{
		cout<<a<<endl;
		
	}
	else
	{
		cout<<b<<endl;
	}
	return 0;
}
int Find_max(int a,int b,int c)
{
	if(a>=b)
	{
		if(a>=c)
		cout<<a<<endl;
		
	}
	else if(b>=c)
	{
		cout<<b<<endl;
	}
	else
	  cout<<c<<endl;
	return 0;
}

double Find_max(double a,double b)
{
	if(a>=b)
	{
		cout<<a<<endl;
		
	}
	else
	{
		cout<<b<<endl;
	}
	return 0;
}
double Find_max(double a,double b,double c)
{
	if(a>=b)
	{
		if(a>=c)
		cout<<a<<endl;
		
	}
	else if(b>=c)
	{
		cout<<b<<endl;
	}
	else
	  cout<<c<<endl;
	return 0;
}









