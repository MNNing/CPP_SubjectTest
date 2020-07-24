//test5_2.cpp
#include<iostream>
using namespace std;
class Time{
	public:
		Time(int h=0,int m=0,int s=0);
		Time operator+(Time &);
		void disptime(string);
	private:
		int hours;
		int minutes;
		int seconds;
};
Time::Time(int h,int m,int s)
{
	hours=h;
	minutes=m;
	seconds=s;
}
Time Time::operator+(Time & tp)
{
	
	Time temp;
	temp.hours=hours+tp.hours;
	temp.minutes=minutes+tp.minutes;
	temp.seconds=seconds+tp.seconds;
	if(temp.seconds<0)
	{
		cout<<"seconds is wrong!"<<endl;
	}
	for(;temp.seconds>=60;)
	{
		temp.seconds=temp.seconds-60;
		temp.minutes=temp.minutes+1;
	}
	if(temp.minutes<0)
	{
		cout<<"minutes is wrong!"<<endl;
	}
	for(;temp.minutes>=60;)
	{
		temp.minutes=temp.minutes-60;
		temp.hours=temp.hours+1;
	}
	return temp;
}
void Time::disptime(string t)
{
	cout<<t<<endl;
	cout<<"hours="<<hours<<endl;
	cout<<"minutes="<<minutes<<endl;
	cout<<"seconds="<<seconds<<endl;
}
int main()
{
	Time time1(5,45,36);
	Time time2(2,35,45);
	Time time0;
	time0=time1.operator+(time2);
	time0.disptime("the result is:");
	return 0;
}
