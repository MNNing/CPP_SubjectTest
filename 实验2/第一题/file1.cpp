//file1.cpp
#include<iostream>
using namespace std;
int add(int a,int b);
int main()
{
	 int x,y,sum;
	 cout<<"Enter two numbers:"<<endl;
	 cin>>x;
	 cin>>y;
	 sum=add(x,y);
	 cout<<"The sum is:"<<sum<<endl;
	 return 0;
}
