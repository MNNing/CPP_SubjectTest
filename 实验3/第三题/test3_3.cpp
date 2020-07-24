#include<iostream>
#include<math.h>
using namespace std;
class Location
{public:
	Location(double,double);          //构造函数 
	double Getx();                    //成员函数，取x坐标的值 
	double Gety();                    //成员函数，取y坐标 的值 
	double dist (Location &);     //成员函数，求给定两点之间的距离 
	friend double dist(Location &,Location &);  //友元函数，求给定两点之间的距离 
 private:
 	double x,y;
};
Location::Location(double x0,double y0)
{
	x=x0;
	y=y0;
}
double Location::Getx()
{
	return x;
}
double Location::Gety()
{
	return y;
}
double Location::dist(Location &p1)
{
	double b1,q1,q2;
	q1=pow((y-p1.y),2.0);
	q2=pow((x-p1.x),2.0);
	b1=sqrt(q1+q2);
	return b1;
}
double dist(Location &p1,Location &p2)
{
	double b2,q1,q2;
	q1=pow((p2.y-p1.y),2.0);
	q2=pow((p2.x-p1.x),2.0);
	b2=sqrt(q1+q2);
	return b2;
}
int main()
{
	Location A(-1.0,-3.0),B(-5.0,6.0);
	cout<<"A("<<A.Getx()<<","<<A.Gety()<<"),";
	cout<<"B("<<B.Getx()<<","<<B.Gety()<<"),"<<endl;
	cout<<"Distance1="<<A.dist(B)<<endl;
	cout<<"Distance2="<<dist(A,B);
	return 0; 
	
 } 
