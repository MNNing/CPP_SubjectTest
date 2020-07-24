//ͼ�����ϵͳ
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Reader;
//ͼ���� 
class Book{
	public:
		Book()             //���캯�� 
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
//ͼ����Ϣ������ 
int Book::Bput_in(Book *b)
{
	Book *p=b;
	char i;
	int n=0;               //ͼ�����ͳ�� 
	int j,fl=0;
	cout<<"�������ʾ����ͼ����Ϣ:"<<endl;
	do
	{
		fl=0;                //�ж��Ƿ������ظ��ı�־ 
		cout<<"����:";cin>>p->name;
		cout<<"\nͼ����:";cin>>p->num;
		cout<<"\n����:";cin>>p->writer;
		cout<<"\n������:";cin>>p->publisher;
		cout<<"\n����������:";cin>>p->pu_year>>p->pu_month>>p->pu_day;
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
			cout<<"ͼ���������ظ�������������:"<<endl;
			i='y';   
		}
		else
		{
			
			n++;
			cout<<"�Ƿ��������ͼ����Ϣ(y\n):";
		    cin>>i;
		    p++;
		}
	}while(i=='y'||i=='Y');
	//��ͼ����Ϣд������ļ�test7.dat.text 
	ofstream fout("test7.dat.text",ios::out|ios::trunc);
	if(!fout)
	{
		cout<<"Cannot open output file.\n";
		exit(1);
	}
	fout<<"	����	ͼ����	����	������	����������"<<endl;
	for(j=0;j<n;j++)
	{
		fout<<"	"<<(b+j)->name<<"	"<<(b+j)->num<<"		"<<(b+j)->writer<<"	"<<(b+j)->publisher;
		fout<<"	"<<(b+j)->pu_year<<"."<<(b+j)->pu_month<<"."<<(b+j)->pu_day<<endl; 
	}
	fout.close();
	delete p;
	return n;
}
//ͼ����Ϣ�Ĳ�ѯ
void Book::Binquire(Book *p,int n)
{
	long num1;
	cout<<"��������Ҫ��ѯ��ͼ��ı��:";
	cin>>num1;cout<<endl;
	int i,fl=0;
	for(i=0;i<n;i++,p++)
	{
		if(p->num==num1)
		{
			fl=1;
			cout<<"����:"<<p->name<<endl;
			cout<<"����:"<<p->writer<<endl;
			cout<<"������:"<<p->publisher<<endl;
			cout<<"����������:"<<p->pu_year<<"."<<p->pu_month<<"."<<p->pu_day<<endl;
 
		}
		

	}
	if(fl==0)
	{
		cout<<"û���ҵ����ϱ�ŵ�ͼ�飡"<<endl;
	}
}
//ͼ����Ϣ��ɾ��
void Book::Bdelete(Book *p,int *n)
{
	long num1;
	int i,pose=-1;
	cout<<"��������Ҫɾ����ͼ��ı��:";
	cin>>num1;cout<<endl;
	for(i=0;i<*n;i++)
	{
		if((p+i)->num==num1)
		{
			pose=i;         //���λ�� 
			break;
		}
		
	}
	if(pose==-1)
	{
		cout<<"û�ҵ����ϱ�ŵ�ͼ�飡��"<<endl;
	}
	else
	{
		for(i=pose;i<*n-1;i++)
	    {
		    *(p+i)=*(p+i+1);	//����ǰ��һ����λ 
	    }
	    *n=*n-1;
	    cout<<"�ɹ�ɾ������"<<endl;
	}
	
}
//ͼ������޸�
void Book::Balter(Book *p,int n)
{
	long num1;
	int i;
	int x;
	int fl=0;
	cout<<"��������Ҫ�޸ĵ�ͼ����:";
	cin>>num1;cout<<endl;
	for(i=0;i<n;i++,p++)
	{
		if(p->num==num1)
		{
			fl=1;
			cout<<"��ѡ����Ҫ�޸ĵ���Ϣ:"<<endl;
			cout<<"	------1.����--------"<<endl;
			cout<<"	------2.ͼ����----"<<endl;
			cout<<"	------3.����--------"<<endl;
			cout<<"	------4.������------"<<endl;
			cout<<"	------5.����������--"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
					cout<<"��������������:"<<endl;
					cin>>p->name;
					break;
				case 2:
					cout<<"����������ͼ����:"<<endl;
					cin>>p->num;
					break;
				case 3:
					cout<<"��������������:"<<endl;
					cin>>p->writer;
					break;
				case 5:
					cout<<"�������������������:"<<endl;
					cin>>p->pu_year>>p->pu_month>>p->pu_day;
					break;
				case 4:
				    cout<<"���������������:"<<endl;
					cin>>p->publisher;
					break;
				default:
			     	cout<<"Unknow operator!\n"<<endl; 	
			}
			 
		} 
		if(fl==0)
		{
			cout<<"�Ҳ����ñ�Ŷ�Ӧ�Ķ��ߣ���"<<endl;
		} 
	}
}
void Book::print(Book *p,int n)
{
	if(n==0)     //�����û�н�����Ϣ���룬������ļ��е����� 
	{
		ifstream fin("test7.dat.text",ios::binary);    //���������ļ������󣬴򿪶����������ļ� 
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
		    cout<<"	����	ͼ����	����	������	����������"<<endl;
		    cout<<"	"<<p->name<<"	"<<p->num<<"		"<<p->writer<<"	"<<p->publisher;
		    cout<<"	"<<p->pu_year<<"."<<p->pu_month<<"."<<p->pu_day<<endl; 
	    }
	}
	
}

//������
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
//������Ϣ������ 
int Reader::Rput_in(Reader *r)
{
	Reader *q=r;
	char i;
	int n=0;
	int j,fl=0;
	Book *p;
	p=new Book;
	cout<<"�������ʾ���������Ϣ:"<<endl;
	do
	{
		fl=0;
		cout<<"����:";cin>>q->Rname;
		cout<<"\n���߱��:";cin>>q->Rnum;
		cout<<"\n��������:(1~3)"<<endl;
		cout<<"---1.��ʿ��---"<<endl;
		cout<<"---2.˶ʿ��---"<<endl;
		cout<<"---3.������---"<<endl; 
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
			cout<<"���߱�������ظ�������������:"<<endl;
			i='y';
		}
		else
		{
			
			n++;
			cout<<"�Ƿ�������������Ϣ(y\n):";
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
		fout<<"��"<<j+1<<"λ����"; 
		fout<<"����:"<<(r+j)->Rname<<endl;
		fout<<"���߱��:"<<(r+j)->Rnum<<endl;
		fout<<"��������:";
		switch((r+j)->type)
		{
			case 1:
				fout<<"��ʿ��"<<endl;
				break;
			case 2:
				fout<<"˶ʿ��"<<endl;
				break;
			case 3:
				fout<<"������"<<endl;
				break;
			default:
				fout<<"Unknow operator!\n"<<endl; 
		}
		fout<<"���ɽ���ͼ����Ŀ:"<<(r+j)->maximum<<endl;
		fout<<"�ö��������ĵ�ͼ�����Ϣ:"<<endl;
		fout<<"	����	ͼ����	����	������	����������"<<endl;
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
//������Ĳ�ѯ
void Reader::Rinquire(Reader *r,int n)
{
	long num;
	cout<<"������Ҫ��ѯ�Ķ��߱��:"<<endl;
	cin>>num;
	int i,j,fl=0;
	for(i=0;i<n;i++)
	{
		if(num==(r+i)->Rnum)
		{
			fl=1;
			cout<<"����:"<<(r+i)->Rname<<endl;
			cout<<"���߱��:"<<(r+i)->Rnum<<endl;
			cout<<"��������:";
			switch((r+i)->type)
			{
				case 1:
					cout<<"��ʿ��"<<endl;
					break;
				case 2:
					cout<<"˶ʿ��"<<endl;
					break;
				case 3:
					cout<<"������"<<endl;
					break;
				default:
				    cout<<"Unknow operator!\n"<<endl; 
			}
			cout<<"���ɽ���ͼ����Ŀ:"<<(r+i)->maximum<<endl;
			cout<<"�ö��������ĵ�ͼ�����Ϣ:"<<endl;
			Book *p;
			p=new Book;
			p->print((r+i)->books,Bnum);
		}
		
	}
	if(fl==0)
	{
		cout<<"�Ҳ����ñ�Ŷ�Ӧ�Ķ��ߣ���"<<endl;
	}
} 
//�������ɾ��
void Reader::Rdelete(Reader *r,int *n)
{
	int i,pose=-1;
	long num;
	
	cout<<"������Ҫɾ���Ķ��߱��:"<<endl;
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
		cout<<"û���ҵ��ñ�Ŷ�Ӧ�Ķ���!!"<<endl;
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
//������Ϣ���޸�
void Reader::Ralter(Reader *r,int n)
{
	long num;
	int i,x,fl=0;
	cout<<"������Ҫ�޸ĵĶ��߱��:"<<endl;
	cin>>num;
	for(i=0;i<n;i++)
	{
		if(num==(r+i)->Rnum)
		{
			fl=1;
			cout<<"��ѡ��Ҫ�޸ĵ���Ϣ:(1~4)"<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"------1.��������-------------"<<endl;
			cout<<"------2.���߱��-------------"<<endl;
			cout<<"------3.��������-------------"<<endl;
			cout<<"------4.�����ĵ�ͼ�����Ϣ---"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
					cout<<"�����������������:"<<endl;
					cin>>(r+i)->Rname;
					break;
				case 2:
					cout<<"������������߱�ţ�"<<endl;
					cin>>(r+i)->Rnum;
					break;
				case 3:
					cout<<"�����������������:(1~3)"<<endl;
					cout<<"---1.��ʿ��---"<<endl;
					cout<<"---2.˶ʿ��---"<<endl;
					cout<<"---3.������---"<<endl; 
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
		cout<<"�Ҳ����ñ�Ŷ�Ӧ�Ķ��ߣ�����"<<endl;
	}
} 
//������Ϣ�����
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
			cout<<"��"<<i+1<<"λ����"; 
			cout<<"����:"<<(r+i)->Rname<<endl;
			cout<<"���߱��:"<<(r+i)->Rnum<<endl;
			cout<<"��������:";
			switch((r+i)->type)
			{
				case 1:
					cout<<"��ʿ��"<<endl;
					break;
				case 2:
					cout<<"˶ʿ��"<<endl;
					break;
				case 3:
					cout<<"������"<<endl;
					break;
				default:
				    cout<<"Unknow operator!\n"<<endl; 
			}
			cout<<"���ɽ���ͼ����Ŀ:"<<(r+i)->maximum<<endl;
			cout<<"�ö��������ĵ�ͼ�����Ϣ:"<<endl;
			Book *p;
			p=new Book;
			p->print((r+i)->books,(r+i)->Bnum);
		}
	}
}
void start()
{
	cout<<"******************************"<<endl;
	cout<<"*------ͼ�����ϵͳ----------*"<<endl;
	cout<<"*----------------------------*"<<endl;
	cout<<"*------���ߣ������� 17080224-*"<<endl;
	cout<<"*------�汾��1.01------------*"<<endl;
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
		cout<<"��ѡ�񣺣�1~3��"<<endl;
	    cout<<"***************************"<<endl;;
	    cout<<"*------1.ͼ����Ϣ����-----*"<<endl;
	    cout<<"*------2.������Ϣ����-----*"<<endl;
	    cout<<"*------3.�˳�����---------*"<<endl;
	    cout<<"***************************"<<endl;
	    cin>>x;
	    switch(x)
	    {
		    case 1:
		    	do
		    	{
		    		cout<<"|----------------------|"<<endl;
		    		cout<<"|******1.��Ϣ����******|"<<endl;
			        cout<<"|******2.��Ϣ��ѯ******|"<<endl;
			        cout<<"|******3.��Ϣɾ��******|"<<endl;
			    	cout<<"|******4.��Ϣ�޸�******|"<<endl;
			    	cout<<"|******5.��ʾ������Ϣ**|"<<endl; 
			    	cout<<"|******6.�����ϲ�******|"<<endl;
			    	cout<<"|----------------------|"<<endl; 
			    	cout<<"��ѡ��:(1~6)"<<endl;
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
			    	cout<<"|******1.��Ϣ����******|"<<endl;
				    cout<<"|******2.��Ϣ��ѯ******|"<<endl;
				    cout<<"|******3.��Ϣɾ��******|"<<endl;
				    cout<<"|******4.��Ϣ�޸�******|"<<endl;
				    cout<<"|******5.��ʾ������Ϣ**|"<<endl; 
				    cout<<"|******6.�����ϲ�******|"<<endl;
				    cout<<"|----------------------|"<<endl; 
				    cout<<"��ѡ��:(1~6)"<<endl;
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

