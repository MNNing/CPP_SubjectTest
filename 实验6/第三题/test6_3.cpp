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
	cout<<"����"<<endl;
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
	cout<<"����"<<endl;
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
		cout<<"���󣡣���"<<endl;
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
	cout<<"int��:"<<endl;
	arr1.printf();
	arr1.invert();
	arr1.printf();
	arr1.sort();
	arr1.printf();
	cout<<"int������Ԫ����ͣ�"<<arr1.add()<<endl;
	cout<<"double��:"<<endl;
	arr2.printf();
	arr2.invert();
	arr2.printf();
	arr2.sort();
	arr2.printf();
	cout<<"double������Ԫ�����:"<<arr2.add()<<endl;
	cout<<"��������Ҫ���ҵ�Ԫ���±�:";
	cin>>n;
	cout<<"int�������в��ҵ�Ԫ��:"<<arr1.finding(n)<<endl;
	cout<<"double�������в��ҵ�Ԫ�أ�"<<arr2.finding(n)<<endl;
	return 0;
}
