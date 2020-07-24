//test3_4.cpp
#include<iostream>
using namespace std;
class Student
{public:
	void account(int i);
	static float sum();
	static void average();	
  private:
  	float score;
  	static float total_score;
  	static int count;
};
void Student::account(int i)
{
	cout<<"请输入第"<<i<<"位学生的分数"<<endl;
	cin>>score;
	++count;
	total_score=total_score+score; 
}
float Student::sum()
{
	return total_score;
}
void Student::average()
{
	float ave;
	ave=total_score/count;
	cout<<"平均成绩为："<<ave<<endl;
}
float Student::total_score=0;
int Student::count=0;
int main()
{
	Student stu[10];
	int i;
	for(i=0;i<10;i++)
	{
		stu[i].account(i+1);
	}
	cout<<"全班同学的成绩之和："<<Student::sum()<<endl;
	Student::average();
	return 0;
}
