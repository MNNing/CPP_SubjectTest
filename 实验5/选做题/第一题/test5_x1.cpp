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
//�������Ĺ��캯�� 
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
	cout<<"�����븴����ʵ����";
	cin>>r;
	cout<<"�����븴�����鲿��";
	cin>>i;	
	Complex A1(i,r),A2(2.2,3.6),A3,A4,A5,A6;
	cout<<"������һ����������ͨ��Ա�������мӼ��˳�����"<<endl;
	A3=A1.Add(A2);
	cout<<"�ӷ���\n";
	A3.print();
	A4=A1.Sub(A2);
	cout<<"������\n";
	A4.print();
	A5=A1.Mul(A2);
	
	cout<<"�˷���\n";
	A5.print();
	A6=A1.Div(A2);
	cout<<"������\n";
	A6.print();
	cout<<"���ó�Ա��������غ����������㣺"<<endl;
	A3=A1+A2;
	cout<<"�ӷ���\n";
	A3.print();
	A4=A1-A2;
	cout<<"������\n";
	A4.print();
	A5=A1*A2;
	cout<<"�˷���\n";
	A5.print();
	A6=A1/A2;
	cout<<"������\n";
	A6.print(); 
	cout<<"������Ԫ�����������㣺"<<endl;
	A3=Add(A1,A2);
	cout<<"�ӷ���\n";
	A3.print();
	A4=Sub(A1,A2);
	cout<<"������\n";
	A4.print();
	A5=Mul(A1,A2);
	cout<<"�˷���\n";
	A5.print();
	A6=Div(A1,A2);
	cout<<"������\n";
	A6.print(); 
	return 0;
	
}
