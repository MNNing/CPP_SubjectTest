//test6_4.cpp
#include<iostream>
#include<math.h>
using namespace std;
float Sqrt(float x)
{
	if(x<0)
	{
		throw x;
	}
	return sqrt(x);
}
int main()
{
	char ch;
	float b;
	do
	{
		cout<<"����һ����:"<<endl;
	    cin>>b;
	    try
	    {
	    	cout<<b<<"������="<<Sqrt(b)<<endl;
	    } 
	    catch(float)
	    {
		    cout<<"��������Ϊ���������󣡣���"<<endl;
	    }
	    cout<<"����������:(y/n)"<<endl;
	    cin>>ch;
	}while(ch=='y'||ch=='Y');
	cout<<endl;
	return 0;
}
