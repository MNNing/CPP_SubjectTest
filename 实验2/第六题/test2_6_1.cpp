//test2_5_1.cpp
#include<iostream>
using namespace std;
int main()
{
	double *p,s;
	p=new double;
	cout<<"����Բ�İ뾶��"<<endl;
	cin>>*p;
	s=3.1415926**p**p;
	cout<<"Բ�������"<<s<<endl;
	delete p;
	return 0; 
}
