//test4_x3.cpp
#include<iostream>
#include<string>
using namespace std;
class circle{
	public:
		circle(float r1)
		{
			r=r1;
		}
		void show_s()
		{
			cout<<"面积："<<3.14*r*r<<"平方米"<<endl;
		}
	private:
		float r;
}; 
class table{
	public:
		table(float high1,string color1)
		{
			high=high1;
			color=color1;
		}
		void show_h_c()
		{
			cout<<"高度:"<<high<<"米"<<endl;
			cout<<"颜色:"<<color<<endl;
		}
	private:
		float high;
		string color;
};
class roundtable:public circle,public table{
	public:
		roundtable(float r1,float high1,string color1):circle(r1),table(high1,color1)
		{
			
		} 
		void show()
		{
			show_s();
			show_h_c();
		}
	
};
int main()
{
	roundtable t(1.5,1.2,"黑色");
	t.show(); 
	return 0;
}
