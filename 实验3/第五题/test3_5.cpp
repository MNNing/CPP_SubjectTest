#include<iostream>
#include<string>
using namespace std;
int main()
{
	string st[5]={"Germany","Japan","America","Britain","france"};
	int i;
	cout<<"��תǰ��"<<endl; 
	for(i=0;i<5;i++)
	{
		cout<<st[i]<<"    ";
	}
	cout<<endl<<"��ת��"<<endl; 
	for(i=4;i>=0;i--)
	{
		cout<<st[i]<<"    ";
	}
}
 
