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
	cout<<"楼的层数:"<<floors<<endl;
	cout<<"房间数:"<<rooms<<endl;
	cout<<"总面积："<<square<<endl; 
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
	cout<<"卧室的数量:"<<bedrooms<<endl;
	cout<<"阳台的数量:"<<balcony<<endl;
}
int main()
{
	house h(12,50,2000,200,100);
	h.show();
	return 0;
}

