//图书管理系统
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Reader;
//图书类 
class Book{
	public:
		Book()             //构造函数 
		{
			
		}
		friend  Reader;
		int Bput_in(Book *b);      
		void Binquire(Book *p,int n); 
		void Bdelete(Book *p,int *n);
		void Balter(Book *p,int n);
		void print(Book *p,int n);
	private:
		char name[20];
		long num;
		char writer[10];
		char publisher[10];
		int pu_year;
		int pu_month;
		int pu_day;
}; 
//图书信息的输入 
int Book::Bput_in(Book *b)
{
	Book *p=b;
	char i;
	int n=0;               //图书个数统计 
	int j,fl=0;
	cout<<"请根据提示输入图书信息:"<<endl;
	do
	{
		fl=0;                //判断是否输入重复的标志 
		cout<<"书名:";cin>>p->name;
		cout<<"\n图书编号:";cin>>p->num;
		cout<<"\n作者:";cin>>p->writer;
		cout<<"\n出版社:";cin>>p->publisher;
		cout<<"\n出版年月日:";cin>>p->pu_year>>p->pu_month>>p->pu_day;
		cout<<endl;
		for(j=0;j<n;j++)
		{
			if(p->num==(b+j)->num)
			{
				fl=1;
			}
			
		}
		if(fl==1)
		{
			cout<<"图书编号输入重复！请重新输入:"<<endl;
			i='y';   
		}
		else
		{
			
			n++;
			cout<<"是否继续输入图书信息(y\n):";
		    cin>>i;
		    p++;
		}
	}while(i=='y'||i=='Y');
	//把图书信息写入磁盘文件test7.dat.text 
	ofstream fout("test7.dat.text",ios::out|ios::trunc);
	if(!fout)
	{
		cout<<"Cannot open output file.\n";
		exit(1);
	}
	fout<<"	书名	图书编号	作者	出版社	出版年月日"<<endl;
	for(j=0;j<n;j++)
	{
		fout<<"	"<<(b+j)->name<<"	"<<(b+j)->num<<"		"<<(b+j)->writer<<"	"<<(b+j)->publisher;
		fout<<"	"<<(b+j)->pu_year<<"."<<(b+j)->pu_month<<"."<<(b+j)->pu_day<<endl; 
	}
	fout.close();
	delete p;
	return n;
}
//图书信息的查询
void Book::Binquire(Book *p,int n)
{
	long num1;
	cout<<"请输入你要查询的图书的编号:";
	cin>>num1;cout<<endl;
	int i,fl=0;
	for(i=0;i<n;i++,p++)
	{
		if(p->num==num1)
		{
			fl=1;
			cout<<"书名:"<<p->name<<endl;
			cout<<"作者:"<<p->writer<<endl;
			cout<<"出版社:"<<p->publisher<<endl;
			cout<<"出版年月日:"<<p->pu_year<<"."<<p->pu_month<<"."<<p->pu_day<<endl;
 
		}
		

	}
	if(fl==0)
	{
		cout<<"没有找到符合编号的图书！"<<endl;
	}
}
//图书信息的删除
void Book::Bdelete(Book *p,int *n)
{
	long num1;
	int i,pose=-1;
	cout<<"请输入你要删除的图书的编号:";
	cin>>num1;cout<<endl;
	for(i=0;i<*n;i++)
	{
		if((p+i)->num==num1)
		{
			pose=i;         //标记位置 
			break;
		}
		
	}
	if(pose==-1)
	{
		cout<<"没找到符合编号的图书！！"<<endl;
	}
	else
	{
		for(i=pose;i<*n-1;i++)
	    {
		    *(p+i)=*(p+i+1);	//依次前移一个单位 
	    }
	    *n=*n-1;
	    cout<<"成功删除！！"<<endl;
	}
	
}
//图书类的修改
void Book::Balter(Book *p,int n)
{
	long num1;
	int i;
	int x;
	int fl=0;
	cout<<"请输入需要修改的图书编号:";
	cin>>num1;cout<<endl;
	for(i=0;i<n;i++,p++)
	{
		if(p->num==num1)
		{
			fl=1;
			cout<<"请选择需要修改的信息:"<<endl;
			cout<<"	------1.书名--------"<<endl;
			cout<<"	------2.图书编号----"<<endl;
			cout<<"	------3.作者--------"<<endl;
			cout<<"	------4.出版社------"<<endl;
			cout<<"	------5.出版年月日--"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
					cout<<"请重新输入书名:"<<endl;
					cin>>p->name;
					break;
				case 2:
					cout<<"请重新输入图书编号:"<<endl;
					cin>>p->num;
					break;
				case 3:
					cout<<"请重新输入作者:"<<endl;
					cin>>p->writer;
					break;
				case 5:
					cout<<"请重新输入出版年月日:"<<endl;
					cin>>p->pu_year>>p->pu_month>>p->pu_day;
					break;
				case 4:
				    cout<<"请重新输入出版社:"<<endl;
					cin>>p->publisher;
					break;
				default:
			     	cout<<"Unknow operator!\n"<<endl; 	
			}
			 
		} 
		if(fl==0)
		{
			cout<<"找不到该编号对应的读者！！"<<endl;
		} 
	}
}
void Book::print(Book *p,int n)
{
	if(n==0)     //如果还没有进行信息输入，则输出文件中的内容 
	{
		ifstream fin("test7.dat.text",ios::binary);    //定义输入文件流对象，打开二进制输入文件 
		if(!fin)
		{
			cout<<"Cannot open input file.\n";
			exit(1);
		}
		char ch;
	    while(fin.get(ch))
	    {
	    	cout<<ch;
	    }
		fin.close();
	}
	else
	{
		int i;
	    for(i=0;i<n;i++,p++)
	    {
		    cout<<"	书名	图书编号	作者	出版社	出版年月日"<<endl;
		    cout<<"	"<<p->name<<"	"<<p->num<<"		"<<p->writer<<"	"<<p->publisher;
		    cout<<"	"<<p->pu_year<<"."<<p->pu_month<<"."<<p->pu_day<<endl; 
	    }
	}
	
}

//读者类
class Reader{
	public:
		Reader()
		{
			
		}
		int Rput_in(Reader *r);
		void Rinquire(Reader *r,int n);
		void Rdelete(Reader *r,int *n);
		void Ralter(Reader *r,int n);
		void printf(Reader *r,int n);
	private:
		char Rname[10];
		long Rnum;
		int type;
		int maximum;
		Book books[10];
		int Bnum;
		
		
}; 
//读者信息的输入 
int Reader::Rput_in(Reader *r)
{
	Reader *q=r;
	char i;
	int n=0;
	int j,fl=0;
	Book *p;
	p=new Book;
	cout<<"请根据提示输入读者信息:"<<endl;
	do
	{
		fl=0;
		cout<<"姓名:";cin>>q->Rname;
		cout<<"\n读者编号:";cin>>q->Rnum;
		cout<<"\n读者类型:(1~3)"<<endl;
		cout<<"---1.博士生---"<<endl;
		cout<<"---2.硕士生---"<<endl;
		cout<<"---3.本科生---"<<endl; 
		cin>>q->type;
		switch(q->type)
		{
			case 1:
				q->maximum=10;
			    break;
			case 2:
				q->maximum=8;
				break;
			case 3:
				q->maximum=6;
				break;
			default:
				cout<<"Unknow operator!\n"<<endl; 
		}
		q->Bnum=p->Bput_in(q->books);
		for(j=0;j<n;j++)
		{
			if(q->Rnum==(r+j)->Rnum)
			{
				fl=1;
			}
			
		}
		if(fl==1)
		{
			cout<<"读者编号输入重复！请重新输入:"<<endl;
			i='y';
		}
		else
		{
			
			n++;
			cout<<"是否继续输入读者信息(y\n):";
		    cin>>i;
		    q++;
		}
	}while(i=='y'||i=='Y');
	// 
	int k;
	ofstream fout("test7.1.dat.text",ios::out|ios::trunc);
	if(!fout)
	{
		cout<<"Cannot open output file.\n";
		exit(1);
	}
	for(j=0;j<n;j++)
	{
		fout<<"第"<<j+1<<"位读者"; 
		fout<<"姓名:"<<(r+j)->Rname<<endl;
		fout<<"读者编号:"<<(r+j)->Rnum<<endl;
		fout<<"读者类型:";
		switch((r+j)->type)
		{
			case 1:
				fout<<"博士生"<<endl;
				break;
			case 2:
				fout<<"硕士生"<<endl;
				break;
			case 3:
				fout<<"本科生"<<endl;
				break;
			default:
				fout<<"Unknow operator!\n"<<endl; 
		}
		fout<<"最大可借阅图书书目:"<<(r+j)->maximum<<endl;
		fout<<"该读者所借阅的图书的信息:"<<endl;
		fout<<"	书名	图书编号	作者	出版社	出版年月日"<<endl;
		p=(r+j)->books;
	    for(k=0;k<(r+j)->Bnum;k++)
	    {
		    fout<<"	"<<(p+k)->name<<"	"<<(p+k)->num<<"		"<<(p+k)->writer<<"	"<<(p+k)->publisher;
		    fout<<"	"<<(p+k)->pu_year<<"."<<(p+k)->pu_month<<"."<<(p+k)->pu_day<<endl; 
	    }
	} 
	delete p,q;
	fout.close();
	return n;
}
//读者类的查询
void Reader::Rinquire(Reader *r,int n)
{
	long num;
	cout<<"请输入要查询的读者编号:"<<endl;
	cin>>num;
	int i,j,fl=0;
	for(i=0;i<n;i++)
	{
		if(num==(r+i)->Rnum)
		{
			fl=1;
			cout<<"姓名:"<<(r+i)->Rname<<endl;
			cout<<"读者编号:"<<(r+i)->Rnum<<endl;
			cout<<"读者类型:";
			switch((r+i)->type)
			{
				case 1:
					cout<<"博士生"<<endl;
					break;
				case 2:
					cout<<"硕士生"<<endl;
					break;
				case 3:
					cout<<"本科生"<<endl;
					break;
				default:
				    cout<<"Unknow operator!\n"<<endl; 
			}
			cout<<"最大可借阅图书书目:"<<(r+i)->maximum<<endl;
			cout<<"该读者所借阅的图书的信息:"<<endl;
			Book *p;
			p=new Book;
			p->print((r+i)->books,Bnum);
		}
		
	}
	if(fl==0)
	{
		cout<<"找不到该编号对应的读者！！"<<endl;
	}
} 
//读者类的删除
void Reader::Rdelete(Reader *r,int *n)
{
	int i,pose=-1;
	long num;
	
	cout<<"请输入要删除的读者编号:"<<endl;
	cin>>num;
	for(i=0;i<*n;i++)
	{
		if(num==(r+i)->Rnum)
		{
			pose=i;
			break;
			
		}
	}
	if(pose==-1)
	{
		cout<<"没有找到该编号对应的读者!!"<<endl;
	}
	else
	{
		for(i=pose;i<*n-1;i++)
		{
			*(r+i)=*(r+i+1);
		}
		*n=*n-1;
	}
} 
//读者信息的修改
void Reader::Ralter(Reader *r,int n)
{
	long num;
	int i,x,fl=0;
	cout<<"请输入要修改的读者编号:"<<endl;
	cin>>num;
	for(i=0;i<n;i++)
	{
		if(num==(r+i)->Rnum)
		{
			fl=1;
			cout<<"请选择要修改的信息:(1~4)"<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"------1.读者姓名-------------"<<endl;
			cout<<"------2.读者编号-------------"<<endl;
			cout<<"------3.读者类型-------------"<<endl;
			cout<<"------4.所借阅的图书的信息---"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
					cout<<"请重新输入读者姓名:"<<endl;
					cin>>(r+i)->Rname;
					break;
				case 2:
					cout<<"请重新输入读者编号："<<endl;
					cin>>(r+i)->Rnum;
					break;
				case 3:
					cout<<"请重新输入读者类型:(1~3)"<<endl;
					cout<<"---1.博士生---"<<endl;
					cout<<"---2.硕士生---"<<endl;
					cout<<"---3.本科生---"<<endl; 
					cin>>(r+i)->type;
					switch((r+i)->type)
					{
						case 1:
							(r+i)->maximum=10;
						    break;
						case 2:
							(r+i)->maximum=8;
							break;
						case 3:
							(r+i)->maximum=6;
							break;
						default:
							cout<<"Unknow operator!\n"<<endl; 
					}
					break;
				case 4:
					Book *p;
					p=new Book;
					p->Balter((r+i)->books,(r+i)->Bnum);
				default:
					cout<<"Unknow operator!\n"<<endl;
			}
			 
		}
		
	} 
	if(fl==0)
	{
		cout<<"找不到该编号对应的读者！！！"<<endl;
	}
} 
//读者信息的输出
void Reader::printf(Reader *r,int n) 
{
	if(n==0)
	{
		ifstream fin("test7.1.dat.text",ios::binary);
		if(!fin)
		{
			cout<<"Cannot open input file.\n";
			exit(1);
		}
		char ch;
	    while(fin.get(ch))
	    {
	    	cout<<ch;
	    }
		fin.close();
	}
	else
	{
		int i;
		for(i=0;i<n;i++)
		{
			cout<<"第"<<i+1<<"位读者"; 
			cout<<"姓名:"<<(r+i)->Rname<<endl;
			cout<<"读者编号:"<<(r+i)->Rnum<<endl;
			cout<<"读者类型:";
			switch((r+i)->type)
			{
				case 1:
					cout<<"博士生"<<endl;
					break;
				case 2:
					cout<<"硕士生"<<endl;
					break;
				case 3:
					cout<<"本科生"<<endl;
					break;
				default:
				    cout<<"Unknow operator!\n"<<endl; 
			}
			cout<<"最大可借阅图书书目:"<<(r+i)->maximum<<endl;
			cout<<"该读者所借阅的图书的信息:"<<endl;
			Book *p;
			p=new Book;
			p->print((r+i)->books,(r+i)->Bnum);
		}
	}
}
void start()
{
	cout<<"******************************"<<endl;
	cout<<"*------图书管理系统----------*"<<endl;
	cout<<"*----------------------------*"<<endl;
	cout<<"*------作者：孟宁宁 17080224-*"<<endl;
	cout<<"*------版本：1.01------------*"<<endl;
	cout<<"******************************"<<endl;
	system("pause");
	system("cls"); 
	 
}
int main()
{
	Book book[100];
	int n=0,n1=0;
	int *t=&n;
	int *n0=&n1;
	int x;
	int i=0,j=0,k=0;
	Book *p;
	p=new Book;
	Reader people[100];
	Reader *q;
	q=new Reader;
	start();
	do
	{
		cout<<"请选择：（1~3）"<<endl;
	    cout<<"***************************"<<endl;;
	    cout<<"*------1.图书信息管理-----*"<<endl;
	    cout<<"*------2.读者信息管理-----*"<<endl;
	    cout<<"*------3.退出程序---------*"<<endl;
	    cout<<"***************************"<<endl;
	    cin>>x;
	    switch(x)
	    {
		    case 1:
		    	do
		    	{
		    		cout<<"|----------------------|"<<endl;
		    		cout<<"|******1.信息输入******|"<<endl;
			        cout<<"|******2.信息查询******|"<<endl;
			        cout<<"|******3.信息删除******|"<<endl;
			    	cout<<"|******4.信息修改******|"<<endl;
			    	cout<<"|******5.显示所有信息**|"<<endl; 
			    	cout<<"|******6.返回上层******|"<<endl;
			    	cout<<"|----------------------|"<<endl; 
			    	cout<<"请选择:(1~6)"<<endl;
					cin>>x;
					switch(x)
					{
						case 1:
						    n=p->Bput_in(book);
							
							break;
						case 2:
							p->Binquire(book, n);
							break;
						case 3:
							p->Bdelete(book,t);
							break;
						case 4:
							p->Balter(book,n);
							break;
						case 5:
							p->print(book,n);
							break;
						case 6:
							j=1;
							break;
						
						default:
							cout<<"Unknow operator!\n"<<endl;  
							
					}
					system("pause");
	                system("cls"); 
		    		
		    	}while(j==0);
		    	break;
		    case 2:
		    	do
			    {
			    	cout<<"|----------------------|"<<endl;
			    	cout<<"|******1.信息输入******|"<<endl;
				    cout<<"|******2.信息查询******|"<<endl;
				    cout<<"|******3.信息删除******|"<<endl;
				    cout<<"|******4.信息修改******|"<<endl;
				    cout<<"|******5.显示所有信息**|"<<endl; 
				    cout<<"|******6.返回上层******|"<<endl;
				    cout<<"|----------------------|"<<endl; 
				    cout<<"请选择:(1~6)"<<endl;
					cin>>x;
					switch(x)
					{
						case 1:
							n1=q->Rput_in(people);    
							break;
						case 2:
							q->Rinquire(people,n1);	
							break;
						case 3:
							q->Rdelete(people,n0);	
							break;
						case 4:
							q->Ralter(people,n1);	
							break;
						case 5:
							q->printf(people,n1);
							break;
						case 6:
							k=1;
							break;
							
						default:
							cout<<"Unknow operator!\n"<<endl;  
								
					}
						system("pause");
		                system("cls"); 
			    		
			    }while(k==0);
		    		
		    		break;
		    	case 3:
		    		i=1;
		    		break;
		    	default:
		    		cout<<"Unknow operator!\n"<<endl;  
				 
	    }	
	}while(i==0);
	delete p,q,t,n0;
	return 0;
}

