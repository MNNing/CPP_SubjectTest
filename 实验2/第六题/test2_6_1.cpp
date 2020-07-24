//test2_5_1.cpp
#include<iostream>
using namespace std;
int main()
{
	double *p,s;
	p=new double;
	cout<<"输入圆的半径："<<endl;
	cin>>*p;
	s=3.1415926**p**p;
	cout<<"圆的面积："<<s<<endl;
	delete p;
	return 0; 
}
