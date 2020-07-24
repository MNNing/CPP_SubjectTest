//test5_3.cpp
#include<iostream>
using namespace std;
class container{
	protected:
		double radius;//�뾶
	public:
	    container(double radius1);
		virtual double surface_area()=0;
		virtual double volume()=0; 
};
container::container(double radius1)
{
	radius=radius1;
}
class cube:public container{
	public:
		cube(double a):container(a)
		{
			
		}
		double surface_area()
		{
		    double q;
		    q=6*radius*radius;
			return q;
		}
		double volume()
		{
			double q;
			q=radius*radius*radius;
			return q;
		}
};
class sphere:public container{
	public:
		sphere(double r):container(r)
		{
		}
		double surface_area()
		{
			double q;
			q=4*3.14*radius*radius;
			return q;
		}
		double volume()
		{
			double q;
			q=1.33*3.14*radius*radius*radius;
			return q;
		}
};
class cylinder:public container{
	public:
		cylinder(double r,double h):container(r)
		{
			high=h;
		}
		double surface_area()
		{
			double q;
			q=3.14* radius*radius*2+2*3.14*radius*high;
			
			return q;
		}
		double volume()
		{
			double q;
			q=3.14* radius*radius*high;
			return q;
		}
	private:
		double high;
};
int main()
{
	cube A(6.0);
	sphere B(5.0);
	cylinder C(5.0,6.0);
	container *pt;
	pt=&A;
	cout<<"������ı����Ϊ:"<<pt->surface_area()<<endl;
    cout<<"����������Ϊ:"<<pt->volume()<<endl;
    pt=&B;
    cout<<"����ı����:"<<pt->surface_area()<<endl;
    cout<<"��������:"<<pt->volume()<<endl;
    pt=&C;
    cout<<"Բ����ı����:"<<pt->surface_area()<<endl;
    cout<<"Բ��������:"<<pt->volume()<<endl;
    return 0;
}
