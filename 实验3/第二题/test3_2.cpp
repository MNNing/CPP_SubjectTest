#include<iostream>
#include<iomanip>
using namespace std;
class magic                   //����ħ���� 
{public:
	void getdata();           //�����ʼ��Ա���� 
	void setfirstmagic();      //���ó�ʼħ����Ա���� 
	void generatmagic();       //��������ħ����Ա���� 
	void printmagic();         //��ʾħ����Ա���� 
	~magic(){}
	
  private:
  	int m[4][4];
  	int step;                  //����Ԫ��֮��Ĳ�ֵ 
  	int first;                 //��ʼֵ 
  	int sum;                   //���Ԫ�غ���СԪ�صĺ�  
};
void magic::getdata()
{
	cout<<"�������ʼħ������ʼֵ������Ԫ��֮��Ĳ�ֵ��"<<endl;
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
