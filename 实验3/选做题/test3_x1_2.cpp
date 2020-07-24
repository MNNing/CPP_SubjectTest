//test3_x1_2.cpp 
#include<iostream>
using namespace std;
class Book
{public:
	Book(int x)
	{
		qu=x;
		price=10*x;
	}
	int get_qu()
	{
		return qu;
	}
	int get_price()
	{
		return price;
	}
 private:
 	int qu;
 	int price;
};
void fun(Book *q);

int main()
{
	int i;
	Book p[5]={1,2,3,4,5};
	Book *a=NULL;
	a=&p[4];

	for(i=4;i>=0;a--,i--)
	{
		cout<<a->get_qu()*a->get_price()<<endl;
	}
	return 0;
}
