//test4_x2.cpp
#include<iostream>
using namespace std;
class fruit{
   public:
     virtual char *identify(){return "fruit";}
 };
 class tree{
   public:
     virtual char *identify(){return "tree";}
 };
class apple:public fruit,public tree{
	public:
		void showa()
		{
			cout<<"apple: fruit, tree"<<endl;
		}
		
};
class pear:public fruit,public tree{
	public:
		void showp()
		{
			cout<<"pear: fruit, tree"<<endl;
		}
};
class apple_pear:public apple,public pear{
	public:
		void showap()
		{
			cout<<"apple-pear: (apple: fruit, tree), (pear: fruit, tree)"<<endl;
		}
		
};
int main()
{
	apple a;
	a.showa();
	pear p;
	p.showp();
	apple_pear ap;
	ap.showap();
	return 0;
}
