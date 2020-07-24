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
		cout<<"输入一个数:"<<endl;
	    cin>>b;
	    try
	    {
	    	cout<<b<<"开根号="<<Sqrt(b)<<endl;
	    } 
	    catch(float)
	    {
		    cout<<"被开方数为负数，错误！！！"<<endl;
	    }
	    cout<<"继续测试吗？:(y/n)"<<endl;
	    cin>>ch;
	}while(ch=='y'||ch=='Y');
	cout<<endl;
	return 0;
}
