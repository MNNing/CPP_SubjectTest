//test6_1_2.cpp
#include<iostream>
using namespace std;
template<typename T>

int max(int a,int b)
{
	return a>b?a:b;
}
double max(double a,double b)
{
	return a>b?a:b;
}
int main()
{
	cout<<"max('3','7') is"<<max('3','7')<<endl;
	return 0;
}
