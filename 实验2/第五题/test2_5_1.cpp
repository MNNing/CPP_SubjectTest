//test2_5_1.cpp
#include<iostream>
using namespace std;
int sum=0;
int main()
{
	int sum=0;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	for(;i<10;i++)
	{
		::sum=::sum+a[i];
		if(a[i]%2!=0)
		{
			sum+=a[i];
		}
	}
	cout<<"所有元素之和为："<<::sum<<endl; 
	cout<<"奇数元素之和为："<<sum<<endl; 
	return 0; 
}
