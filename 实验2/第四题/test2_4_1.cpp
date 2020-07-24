//test2_4_1.cpp
#include<iostream>
#include<string>
using namespace std;
void swap(string &a,string &b);
int main()
{
	string x,y;
	cout<<"Enter two word:"<<endl;
	cin>>x>>y;
	swap(x,y);
	cout<<x<<">"<<y<<endl;
}
void swap(string &a,string &b)
{
	string term;
	if(a<b)
	{
		term=a;
		a=b;
		b=term;
	}
}
