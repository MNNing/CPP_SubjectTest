//test1_3_1.cpp
#include<iostream>
using namespace std;
int add(int a,int b);
int main()
{
	int x,y,sum;
	cout<<"Enter two numbers:"<<'\n';
	cin>>x;
	cin>>y;
	sum=add(x,y);
	cout<<"The sum is:"<<sum<<'\n';
	return 0;
}
int add(int a,int b)
{
	return a+b;
}
