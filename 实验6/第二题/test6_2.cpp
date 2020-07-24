#include<iostream>
using namespace std;
template<typename T>
void find_m(T *p,int n)
{
	int i;
	T max,min;
	max=p[0];
	min=p[0];
	for(i=1;i<n;i++)
	{
		if(p[i]>max)
		{
			max=p[i];
		}
		if(p[i]<min)
		{
			min=p[1];
		}
	}
	cout<<"数组的最大值:"<<max<<endl;
	cout<<"数组的最小值:"<<min<<endl; 
}
int main()
{
	int a[5]={1,2,3,4,5};
	float b[5]={1.1,2.3,3.6,1.8,5.4};
	double c[5]={2.0,3.6,2.36,5.23,1.25};
	char d[5]={'a','l','k','y','e'};
	cout<<"int型:"<<endl;
	find_m(a,5);
	cout<<"float型:"<<endl;
	find_m(b,5);
	cout<<"double型:"<<endl;
	find_m(c,5);
	cout<<"char型:"<<endl;
	find_m(d,5);
	return 0;
	
}
