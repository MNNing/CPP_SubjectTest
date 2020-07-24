//test2_2_1.cpp
#include<iostream>
using namespace std;
void fun(int,int&);
int main()
{
	int x,y;
	fun(3,x);
	fun(4,y);
	cout<<"x+y="<<x+y<<endl;
	return 0;
}
void fun(int m,int &n)
{
	n=m*5;
}
