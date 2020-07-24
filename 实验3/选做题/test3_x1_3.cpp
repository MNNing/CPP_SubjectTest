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
	void set_Book()
	{
		qu=qu+1;
		price=price+1;
	}
 private:
 	int qu;
 	int price;
};
void fun(Book *q)
{
	q->set_Book();
}
void fun(Book &q)
{
	q.set_Book();
}
void fun1(Book q)
{
	q.set_Book();
}
int main()
{
	int i;
	Book p[5]={1,2,3,4,5};
	cout<<"形参为指针:"<<endl;
	for(i=0;i<5;i++)
	{
		fun(&p[i]);
	}

	for(i=0;i<5;i++)
	{
		cout<<p[i].get_qu()*p[i].get_price()<<endl;
	}
	Book q[5]={1,2,3,4,5};
	cout<<"形参为引用："<<endl;
	for(i=0;i<5;i++)
	{
		fun(q[i]);
	}

	for(i=0;i<5;i++)
	{
		cout<<q[i].get_qu()*q[i].get_price()<<endl;
	}
	Book r[5]={1,2,3,4,5};
	cout<<"形参为对象成员："<<endl;
	for(i=0;i<5;i++)
	{
		fun1(r[i]);
	}

	for(i=0;i<5;i++)
	{
		cout<<r[i].get_qu()*r[i].get_price()<<endl;
	}
	return 0;
}
