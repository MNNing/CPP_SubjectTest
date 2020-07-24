//test6_3.cpp
#include<iostream>
#include<cstdlib>
using namespace std;
template<class Type>
class Array{
	public:
		Array(Type *p){
			arr=p;
		}
		void printf();
		void sort();
		void invert();
		Type finding(int n);
		Type add();
	private:
		Type *arr;
		
};
template<class Type>
void Array<Type>::printf()
{
	int i;
	for(i=0;i<5;i++)
	{
		cout<<arr[i]<<"   ";
	}
	cout<<endl;
}
template<class Type>
void Array<Type>::sort()
{
	int i,j;
	Type term;
	cout<<"排序"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
		if(arr[j]>arr[i])
			{
				term=arr[i];
				arr[i]=arr[j];
				arr[j]=term;
			}
		}
	}
}
template<class Type>
void Array<Type>::invert()
{
	Type term;
	int i,j;
	cout<<"倒置"<<endl;
	for(i=0,j=4;i<j;i++,j--)
	{
		term=arr[i];
		arr[i]=arr[j];
		arr[j]=term;
	}
}
template<class Type>
Type Array<Type>::finding(int n)
{
	if(n>=5||n<0)
	{
		cout<<"错误！！！"<<endl;
		exit(1);
	}
	else
	{
		return arr[n];
	}
}
template<class Type>
Type Array<Type>::add()
{
	Type sum=0;
	int i;
	for(i=0;i<5;i++)
	{
		sum=sum+arr[i];
	}
	return sum;
}
int main()
{
	int n;
	int a[5]={1,2,3,4,5};
	double b[5]={1.2,3.6,5.4,5.9,9.4};
	Array <int> arr1(a);
	Array <double> arr2(b);
	cout<<"int型:"<<endl;
	arr1.printf();
	arr1.invert();
	arr1.printf();
	arr1.sort();
	arr1.printf();
	cout<<"int型数组元素求和："<<arr1.add()<<endl;
	cout<<"double型:"<<endl;
	arr2.printf();
	arr2.invert();
	arr2.printf();
	arr2.sort();
	arr2.printf();
	cout<<"double型数组元素求和:"<<arr2.add()<<endl;
	cout<<"请输入想要查找的元素下标:";
	cin>>n;
	cout<<"int型数组中查找的元素:"<<arr1.finding(n)<<endl;
	cout<<"double型数组中查找的元素："<<arr2.finding(n)<<endl;
	return 0;
}
