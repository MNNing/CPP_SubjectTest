#include<iostream>
using namespace std;
class Complex{
	public:
		Complex(){
		};
		Complex(double r,double i);
		Complex(const Complex &tp);
		Complex Add(Complex &tp);
		Complex Sub(Complex &tp);
		Complex Mul(Complex &tp);
		Complex Div(Complex &tp);
		Complex operator+(Complex tp);
		Complex operator-(Complex tp);
		Complex operator*(Complex tp);
		Complex operator/(Complex tp);
		Complex operator=(Complex tp);
		friend Complex Add(Complex &a,Complex &b);
		friend Complex Sub(Complex &a,Complex &b);
		friend Complex Mul(Complex &a,Complex &b);
		friend Complex Div(Complex &a,Complex &b);
		void print();
	private:
		double real;
		double imag;
}; 
//带参数的构造函数 
Complex::Complex(double r,double i)
{
	real=r;
	imag=i;
}
Complex::Complex(const Complex &tp)
{
	real=tp.real;
	imag=tp.imag;
}
Complex Complex::Add(Complex &tp)
{
	Complex temp;
	temp.real=real+tp.real;
	temp.imag=imag+tp.imag;
	return temp;
}
Complex Complex::Sub(Complex &tp)
{
	Complex temp;
	temp.real=real-tp.real;
	temp.imag=imag-tp.imag;
	return temp;
}
Complex Complex::Mul(Complex &tp)
{
	Complex temp;
	temp.real=real*tp.real-imag*tp.imag;
	temp.imag=real*tp.imag+imag*tp.imag;
	return temp;
}
Complex Complex::Div(Complex &tp)
{
	Complex temp;
	double t;
	t=1/(tp.real*tp.real+tp.imag*tp.imag);
	
	temp.real=(real*tp.real+imag*tp.imag)*t;
	temp.imag=(tp.real*imag-real*tp.imag)*t;
	return temp;
}
Complex Complex::operator+(Complex tp)
{
	Complex temp;
	temp.real=real+tp.real;
	temp.imag=imag+tp.imag;
	return temp;
	
}
Complex Complex::operator-(Complex tp)
{
	Complex temp;
	temp.real=real-tp.real;
	temp.imag=imag-tp.imag;
	return temp;
} 
Complex Complex::operator*(Complex tp)
{
	Complex temp;
	temp.real=real*tp.real-imag*tp.imag;
	temp.imag=real*tp.imag+imag*tp.imag;
	return temp;
}
Complex Complex::operator/(Complex tp)
{
	Complex temp;
	double t;
	t=1/(tp.real*tp.real+tp.imag*tp.imag);
	
	temp.real=(real*tp.real+imag*tp.imag)*t;
	temp.imag=(tp.real*imag-real*tp.imag)*t;
	return temp;
}
Complex Complex::operator=(Complex tp)
{
	real=tp.real;
	imag=tp.imag;
}
Complex Add(Complex &a,Complex &b)
{
	Complex temp;
	temp.real=a.real+b.real;
	temp.imag=a.imag+b.imag;
	return temp;
	
}
Complex Sub(Complex &a,Complex &b)
{
	Complex temp;
	temp.real=a.real-b.real;
	temp.imag=a.imag-b.imag;
	return temp;
}
Complex Mul(Complex &a,Complex &b)
{
	Complex temp;
	temp.real=a.real*b.real-a.imag*b.imag;
	temp.imag=a.real*b.imag+a.imag*b.imag;
	return temp;
}
Complex Div(Complex &a,Complex &b)
{
	Complex temp;
	double t;
	t=1/(b.real*b.real+b.imag*b.imag);
	
	temp.real=(a.real*b.real+a.imag*b.imag)*t;
	temp.imag=(b.real*a.imag-a.real*b.imag)*t;
	return temp;
}
void Complex::print()
{
	cout<<real;
	if(imag>0)cout<<"+";
	if(imag!=0)cout<<imag<<"i"<<endl;
}
int main()
{
	double i,r;
	cout<<"请输入复数的实部：";
	cin>>r;
	cout<<"请输入复数的虚部：";
	cin>>i;	
	Complex A1(i,r),A2(2.2,3.6),A3,A4,A5,A6;
	cout<<"调用有一个参数的普通成员函数进行加减乘除运算"<<endl;
	A3=A1.Add(A2);
	cout<<"加法：\n";
	A3.print();
	A4=A1.Sub(A2);
	cout<<"减法：\n";
	A4.print();
	A5=A1.Mul(A2);
	
	cout<<"乘法：\n";
	A5.print();
	A6=A1.Div(A2);
	cout<<"除法：\n";
	A6.print();
	cout<<"调用成员运算符重载函数进行运算："<<endl;
	A3=A1+A2;
	cout<<"加法：\n";
	A3.print();
	A4=A1-A2;
	cout<<"减法：\n";
	A4.print();
	A5=A1*A2;
	cout<<"乘法：\n";
	A5.print();
	A6=A1/A2;
	cout<<"除法：\n";
	A6.print(); 
	cout<<"调用友元函数进行运算："<<endl;
	A3=Add(A1,A2);
	cout<<"加法：\n";
	A3.print();
	A4=Sub(A1,A2);
	cout<<"减法：\n";
	A4.print();
	A5=Mul(A1,A2);
	cout<<"乘法：\n";
	A5.print();
	A6=Div(A1,A2);
	cout<<"除法：\n";
	A6.print(); 
	return 0;
	
}
