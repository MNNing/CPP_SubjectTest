//Point��
#include <iostream>
using namespace std;
class Point{
	public:
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		Point operator++();
		Point operator++(int);
		Point operator--();
		Point operator--(int);
		void print()
		{
			cout<<"�������Ϊ����"<<x<<";"<<y<<")\n"; 
		}
	private:
		int x,y;
}; 
Point Point::operator++()
{
	++x;
	++y;
	return *this;
}
Point Point::operator++(int)
{
	Point tp(*this);
	x++;
	y++;
	return tp;
}
Point Point::operator--()
{
	--x;
	--y;
	return *this;
}
Point Point::operator--(int)
{
	x--;
	y--;
	return *this;
}
int main()
{
	Point p(10,20);
	cout<<"����++   ";
	p++;
	p.print();
	cout<<"ǰ��++   " ;
	++p;
	p.print();
	cout<<"����--   " ;
	p--;
	p.print();
	cout<<"ǰ��--   " ;
	--p;
	p.print();
	return 0;
	
}
