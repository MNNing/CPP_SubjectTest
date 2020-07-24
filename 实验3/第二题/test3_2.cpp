#include<iostream>
#include<iomanip>
using namespace std;
class magic                   //声明魔方类 
{public:
	void getdata();           //输入初始成员函数 
	void setfirstmagic();      //设置初始魔方成员函数 
	void generatmagic();       //生成最终魔方成员函数 
	void printmagic();         //显示魔方成员函数 
	~magic(){}
	
  private:
  	int m[4][4];
  	int step;                  //相邻元素之间的差值 
  	int first;                 //起始值 
  	int sum;                   //最大元素和最小元素的和  
};
void magic::getdata()
{
	cout<<"请输入初始魔方的起始值和相邻元素之间的差值："<<endl;
	cin>>first>>step; 
} 
void magic::setfirstmagic()
{
	int i,j,term;
	term=first;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			m[i][j]=term;
			term=term+step;
		}
	}
}
void magic::generatmagic()
{
	int i,j,term;
	sum=m[0][0]+m[3][3];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			m[i][j]=sum-m[i][j];
		}
	}
}
void magic::printmagic()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<setw(4)<<m[i][j];
		}
		cout<<endl;
	}
}
int main()
{
	magic p;
	p.getdata();
	p.setfirstmagic();
	p.generatmagic();
	p.printmagic();
	return 0;
} 
