//test3_x1_1.cpp 
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

int main()
{
	int i;
	Book p[5]={1,2,3,4,5};

	for(i=0;i<5;i++)
	{
		cout<<p[i].get_qu()*p[i].get_price()<<endl;
	}
	return 0;
}
