//test4_x1
#include<iostream>
using namespace std;
class Building{
	public:
		Building(int floors1,int rooms1,float square1)
		{
			floors=floors1;
			rooms=rooms1;
			square=square1;
		}
		void show();
	protected:
		int floors,rooms;
		float square;
		
}; 
void Building::show()
{
	cout<<"¥�Ĳ���:"<<floors<<endl;
	cout<<"������:"<<rooms<<endl;
	cout<<"�������"<<square<<endl; 
}
class house:public Building{
	public:
		house(int floors1,int rooms1,float square1,
		    int bedrooms1,int balcony1):Building(floors1,rooms1,square1)
		    {
		    	bedrooms=bedrooms1;
		    	balcony=balcony1;
		    }
		void show();
	private:
		int bedrooms,balcony;
};
void house:: show()
{
	Building::show();
	cout<<"���ҵ�����:"<<bedrooms<<endl;
	cout<<"��̨������:"<<balcony<<endl;
}
int main()
{
	house h(12,50,2000,200,100);
	h.show();
	return 0;
}

