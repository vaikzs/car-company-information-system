#include<iomanip.h>
#include<fstream.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>

void printe()
{cout<<"\t\t             ___________                    \n";
 cout<<"\t\t _____      /     |     \\                   \n";
 cout<<"\t\t   _||_____/______|______\\___________       \n";
 cout<<"\t\t  /                                  \\      \n";
 cout<<"\t\t /        ZONTOCQ MOTORS LTD          \\     \n";
 cout<<"\t\t/______   _______________________   ___\\    \n";
 cout<<"\t\t      ( * )                     ( * )         \n";
 }

void print()
{char c[5]="~è~è";
 for(int i=0;i<20;i++)
  cout<<c;
 cout<<"\n";
 }

void print1()
{char d[5]="~~";
 cout<<"\n";
 for(int i=0;i<20;i++)
  cout<<d;
  }

class models{char type[10],specs[20],trans[20],var[50];
	 int engine,seater;
	 float mileage;
      public:char name[10],brnd;
	 int rcrd_no,no_sold;
	 long float onrp[2];
	 void disp();
	 void read();
	 models(){no_sold=0;}
	 }mo;

class supp{public:int no,no_sld;
	  char head[10],gd_add[30],sa_off[10],bm_car[10],s_name;
	  void dis();
	  void bm_c();
	  supp(char s)
	  {s_name=s;
	   no_sld=0;}
	  };
supp v('v'),a('a'),h('h'),s1('s');

class cust{int cho1,cho2;
       struct date{int d,m,y;}dob,dod;
       char tel[10],addr[54],op1;
    public:int no,i;
       char name[15],item_ord[10][10];
       long int to_amt;
       cust(){to_amt=0;}
       void readdata();
       void dispdata();
       void amt_custdisp();
       int check(int,int,int);
       void date_custdisp();
       void car_custdisp(char c);
       }cus,cus1;

class acc{char brand[10],fea[40];
      public: char name[20];
	  float cost;
	  int to_set,rcrd_no;
          void read();
	  void display();
	  acc(){to_set=0;}
	  }ac;

class ann_rpt{ long int to_car_08,to_car_09,to_emp_08,to_acc_08,to_acc_09,to_emp_09;
	   float pro;
	   long int ann_rvnu,trnovr;
	   public: long int to_sales;
	       void disp_ann();
	       ann_rpt();
	       void calc();
	 }ann;


void cust::car_custdisp(char c)
{ifstream fo("cust.dat");
 int s=1;
 if(c=='v')
  {while(fo.read((char*)&cus,sizeof(cus)))
  {for(int j=0;j<=cus.i;j++)
   if(fo.eof()==0&&strcmpi(cus.item_ord[j],"Jetta")==0||strcmpi(cus.item_ord[j],"Passat")==0||strcmpi(cus.item_ord[j],"Touareg")==0)
   {cout<<s<<'.'<<cus.name<<'\n';
    break;
    }
   s++;
   }}
 else if(c=='a')
 {s=1;
 while(fo.read((char*)&cus,sizeof(cus)))
       {for(int j=0;j<=cus.i;j++)
	 if(fo.eof()==0&&strcmpi(cus.item_ord[j],"A4")==0||strcmpi(cus.item_ord[j],"A6")==0||strcmpi(cus.item_ord[j],"A8")==0)
	 {cout<<s<<'.'<<cus.name<<'\n';
	  break;
	  }
	s++;
	 }}
 else if(c=='s')
 {s=1;
       while(fo.read((char*)&cus,sizeof(cus)))
       {for(int j=0;j<=cus.i;j++)
	 if(fo.eof()==0&&strcmpi(cus.item_ord[j],"Octavia")==0||strcmpi(cus.item_ord[j],"Laura")==0||strcmpi(cus.item_ord[j],"Fabia")==0||strcmpi(cus.item_ord[j],"Superb")==0)
	 {cout<<s<<'.'<<cus.name<<'\n';
	  break;
	  }
	s++;
	 }}
 else if(c=='h')
 {s=1;
       while(fo.read((char*)&cus,sizeof(cus)))
       {for(int j=0;j<=cus.i;j++)
	 if(fo.eof()==0&&strcmpi(cus.item_ord[j],"City")==0||strcmpi(cus.item_ord[j],"Civic")==0||strcmpi(cus.item_ord[j],"Accord")==0||strcmpi(cus.item_ord[j],"CRV")==0)
	 {cout<<s<<'.'<<cus.name<<'\n';
	  break;
	  }
	s++;
	 }}
 fo.close();
 }

void cust::amt_custdisp()
{ifstream ff("cust.dat");
 int s=1;
 cout<<'\n';
 do
 {ff.read((char*)&cus,sizeof(cus));
  if(cus.to_amt>2000000&&ff.eof()==0)
  {cout<<s<<"."<<cus.name<<" - Rs."<<cus.to_amt<<"\n";
   s++;
   }
  }while(ff.eof()==0);
  cout<<"\n\nTHESE CUSTOMERS WERE GIVEN GIFTS!!!!\n\n";
  ff.close();
 }

void cust::date_custdisp()
{int d,m,y;
 ifstream ff("cust.dat");
 cout<<"Enter the date to be checked(in dd/mm/yyyy separated by a space):";
 cin>>d>>m>>y;
 while(d<=0||m<=0||d>31||m>12||y<2009||y>2010)
 {cout<<"Enter a valid date:";
  cin>>d>>m>>y;
  }
 int s=1;
 cout<<'\n';
 do
 {ff.read((char*)&cus,sizeof(cus));
  if(cus.check(d,m,y)==1&&ff.eof()==0)
   {cout<<s<<"."<<cus.name<<"\n";
    s++;
    }
  }while(ff.eof()==0);
 ff.close();
}

int cust::check(int d,int m,int y)
{if(dob.d==d&&dob.m==m&&dob.y==y)
  return 1;
 else return 0;
 }

void cust::readdata()
{int p=1;
 i=0;
 to_amt=0;
 ifstream ff("cust.dat");
 ff.seekg(0,ios::end);
 if(ff.tellg()!=0)
 {ff.seekg(0);
  while(ff.read((char*)&cus1,sizeof(cus1)));
  no=cus1.no+1;
   }
 else no=1;
 ff.close();
 cout<<"\n\nCustomer no:"<<no;
 cout<<"\nEnter name:";
 gets(name);
 cout<<"Enter telephone no.:";
 cin>>tel;
 cout<<"Enter address:";
 gets(addr);
 cout<<"Enter date of booking(in dd/mm/yyyy separated by a space):";
 cin>>dob.d>>dob.m>>dob.y;
 while(dob.d<=0||dob.m<=0||dob.d>31||dob.m>12||dob.y<2009||dob.y>2010)
 {cout<<"Enter a valid date:";
  cin>>dob.d>>dob.m>>dob.y;
  }
 fstream f2;
 cout<<"Do you want to buy a car?\nIf yes, press Y:";
 cin>>op1;
 if(toupper(op1)=='Y')
  cout<<"\n1.Jetta\n2.Passat\n3.Touareg\n4.A4\n5.A6\n6.A8\n7.Octavia\n8.Laura\n9.Superb\n10.Fabia\n11.City\n12.Accord\n13.Civic\n14.CRV\n";
 while(toupper(op1)=='Y')
 {cout<<"\nEnter car ordered:";
  cin>>cho1;
  f2.open("models.dat",ios::in|ios::out);
  if(!f2) cout<<"File not opened";
  do{f2.read((char*)&mo,sizeof(mo));
  if(cho1==mo.rcrd_no)
  {strcpy(item_ord[i],mo.name);
   mo.no_sold++;
   mo.disp();
   to_amt+=mo.onrp[1];
   break;
   }
   }while(f2.eof()==0);
 i++;
 if(f2.eof()==0)
 {f2.clear();
  f2.seekg(0);
  ofstream f3("models1.dat",ios::app);
  f3.write((char*)&mo,sizeof(mo));
  while(f2.read((char*)&mo,sizeof(mo)))
   if(cho1!=mo.rcrd_no)
    f3.write((char*)&mo,sizeof(mo));
  f2.close();
  f3.close();
  remove("models.dat");
  p=rename("models1.dat","models.dat");
  }
else
 {cout<<"Enter valid choice.";
  f2.close();
  }
 cout<<"Do you want to buy any more cars?\nIf yes, press Y:";
 cin>>op1;
 }
 cout<<"Do you want to buy any accessories?\nIf yes, press Y:";
 cin>>op1;
 if(toupper(op1)=='Y')
  cout<<"\n15.Stereo system\n16.Sensors\n17.Spoilers\n18.wheels\n19.Fancy lights\n";
 while(toupper(op1)=='Y')
 {cout<<"\nEnter accessories ordered:";
  cin>>cho2;
  f2.open("accs.dat",ios::in|ios::out);
  do{f2.read((char*)&ac,sizeof(ac));
  if(cho2==ac.rcrd_no)
  {strcpy(item_ord[i],ac.name);
   ac.to_set++;
   ac.display();
   to_amt+=ac.cost;
   break;
   }}while(f2.eof()==0);
 i++;
 if(f2.eof()==0)
 {f2.clear();
  f2.seekg(0);
  ofstream f3("accs1.dat",ios::app);
  f3.write((char*)&ac,sizeof(ac));
  while(f2.read((char*)&ac,sizeof(ac)))
   if(cho2!=ac.rcrd_no)
    f3.write((char*)&ac,sizeof(ac));
  f2.close();
  f3.close();
  remove("accs.dat");
  p=rename("accs1.dat","accs.dat");
  }
 else
 {cout<<"Enter valid choice.";
  f2.close();
  }
 cout<<"Do you want to buy any more accessories?\nIf yes, press Y:";
 cin>>op1;
 }
 cout<<"Total amount to be paid:Rs.";
 cout<<to_amt;
 }

void cust::dispdata()
{dod.d=dob.d+5;
 dod.m=dob.m;
 dod.y=dob.y;
 if(dod.d>30)
 {dod.d-=30;
  dod.m++;
  }
 else if(dod.m>12)
 {dod.m-=12;
  dod.y++;
  }
 cout<<"\nCustomer no.:"<<no<<"\nName:"<<name<<"\nTel. no.:"<<tel<<"\nAddress:"<<addr;
 cout<<"\nDate of booking:"<<dob.d<<"/"<<dob.m<<"/"<<dob.y<<"\nDate of delivery:"<<dod.d<<"/"<<dod.m<<"/"<<dod.y<<"\nTotal amount paid:"<<to_amt;
 cout<<"\nItems ordered:";
 for(int j=0;j<i;j++)
  cout<<'\n'<<item_ord[j];
}


ann_rpt::ann_rpt()
{to_sales=0;
 to_car_09=0;
 to_car_08=26788;
 to_acc_09=0;
 to_acc_08=53333;
 to_emp_09=562;
 to_emp_08=325;
 pro=10.4;
 trnovr=0;
 ann_rvnu=0;
 }

void ann_rpt::calc()
{ifstream f1("accs.dat");
 to_acc_09=0;
 to_sales=0;
 v.bm_c();
 a.bm_c();
 s1.bm_c();
 h.bm_c();
 to_car_09=v.no_sld+a.no_sld+h.no_sld+s1.no_sld;
 do{f1.read((char*)&ac,sizeof(ac));
 if(f1.eof()==0) to_acc_09+=ac.to_set;
 }while(f1.eof()==0);
 f1.close();
 f1.open("cust.dat");
 do{f1.read((char*)&cus,sizeof(cus));
 to_sales+=cus.to_amt;
 }while(f1.eof()==0);
 f1.close();
 trnovr=to_sales*(pro/100.0);
 ann_rvnu=to_sales+trnovr;
 }

void ann_rpt::disp_ann()
{cout<<"\n\nTotal number of cars sold 2008:"<<to_car_08<<"\n\nTotal number of cars sold 2009:";
 cout<<to_car_09<<"\n\nTotal number of employees 2008:"<<to_emp_08<<"\n\nTotal number of employees 2009:";
 cout<<to_emp_09<<"\n\nTotal number of accessories sold 2008:"<<to_acc_08<<"\n\nTotal number of accessories sold 2009:"<<to_acc_09;
 cout<<"\n\nProfit precentage:"<<pro<<"\n\nTotal sales in 2009:"<<setprecision(5)<<to_sales<<"\n\nAnnual revenue:"<<setprecision(5)<<ann_rvnu<<"\n\nTurnover:"<<setprecision(5)<<trnovr;
 }

void acc::display()
{cout<<"\nName:"<<name<<"\nBrand:"<<brand<<"\nCost:Rs."<<cost<<"\nFeatures:"<<fea;
cout<<"\nTotal number of sets sold:"<<to_set<<'\n';
}

void acc::read()
{cout<<"Name:";
 cin>>name;
 cout<<"Brand:";
 cin>>brand;
 cout<<"Features:";
 cin>>fea;
 cout<<"Cost:";
 cin>>cost;
 cout<<"Record no:";
 cin>>rcrd_no;
 }

void models::disp()
{cout<<"\nName:"<<name<<"\nType:"<<type<<"\nEngine:"<<engine<<"cc "<<specs;
cout<<"\nTransmission:"<<trans<<"\nSeater:"<<seater<<"\nVariants:"<<var<<"\nMileage:";
cout<<mileage<<"km\nPrice range:Rs."<<onrp[0]<<"-"<<onrp[1]<<"\nNo. sold:"<<no_sold<<'\n';
}

void models::read()
{cout<<"Name:";
 cin>>name;
 cout<<"Type:";
 cin>>type;
 cout<<"Engine:";
 cin>>engine;
 cout<<"Mileage:";
 cin>>mileage;
 cout<<"On-road price:";
 cin>>onrp[0]>>onrp[1];
 cout<<"Record no.:";
 cin>>rcrd_no;
 cout<<"brand:";
 cin>>brnd;
 cout<<"Specs:";
 gets(specs);
 cout<<"Transmission:";
 gets(trans);
 cout<<"Seater:";
 cin>>seater;
 cout<<"Variants:";
 gets(var);
 }


void supp::dis()
{bm_c();
 cout<<"\n\n\nSupplier no:"<<no<<"\n\nCompany head quarters:"<<head<<"\n\nGo-down address:"<<gd_add<<"\n\nContact officer:";
 cout<<sa_off<<"\n\nTotal no. of cars sold:"<<no_sld<<"\n\nBest moving car:"<<bm_car;
}


void inits()
{v.no=2432;
 strcpy(v.head,"Germany");
 strcpy(v.gd_add,"25,T.Nagar");
 strcpy(v.sa_off,"Ramu");
 a.no=2556;
 strcpy(a.head,"England");
 strcpy(a.gd_add,"25,RK.salai");
 strcpy(a.sa_off,"Srinivas");
 s1.no=2643;
 strcpy(s1.head,"Korea");
 strcpy(s1.gd_add,"61,Manapakkam");
 strcpy(s1.sa_off,"Krishna");
 h.no=2876;
 strcpy(h.head,"Japan");
 strcpy(h.gd_add,"29,Mylapore");
 strcpy(h.sa_off,"John");
}

void supp::bm_c()
{int large=0;
 no_sld=0;
 ifstream f1("models.dat");
 do{f1.read((char*)&mo,sizeof(mo));
 if(mo.brnd==s_name)
  {if(mo.no_sold>=large)
   {large=mo.no_sold;
    strcpy(bm_car,mo.name);
    }
   no_sld+=mo.no_sold;
 }}while(f1.eof()==0);
 f1.close();
 }


void main()
{textbackground(0);
 textcolor(3);
 clrscr();
 ofstream f1;
 ifstream f2;
 inits();
 int ch,ch1,ch2,ch3;
 char op;
 do
 {clrscr();
 print();
 printe();cout<<"\n";
 cout<<"\t\t\t                          \n\t\t\t\t\t   - Elegance Personified..!\n\n\n\n";
 print1();
 cout<<"\n\n1.Suppliers\n\n2.Accessories\n\n3.Customer details\n\n4.Reports\n\n5.Administrator\n\n6.Exit\n\nEnter choice:";
 cin>>ch;
 int no;
 cout<<'\n';
 switch(ch)
 {case 1:textbackground(7);
       textcolor(4);
       clrscr();
       cout<<'\n';
       print();
       cout<<"\t\t\t\t   Suppliers\n";
       print1();
       cout<<"\n\n1.Volkswagon\n\n2.Audi\n\n3.Skoda\n\n4.Honda\n\nEnter choice:";
       cin>>ch1;
       cout<<'\n';
       switch(ch1)
       {case 1:clrscr();
	     cout<<'\n';
	     print();
	     cout<<"\t\t\t\t   Volkswagon\n";
	     print1();
	     cout<<"\n\n\n1.Jetta\n\n2.Passat\n\n3.Touareg\n\n4.Supplier details\n\nEnter choice:";
	     cin>>ch2;
	     cout<<'\n';
	     f2.open("c:\\tcc\\models.dat");
	     if(!f2) {cout<<"File not opened";
	     getch();}
	     do{f2.read((char*)&mo,sizeof(mo));
	     if(mo.brnd=='v'&&f2.eof()==0)
	     {switch(ch2)
	     { case 1:if(strcmpi(mo.name,"Jetta")==0)
		 mo.disp();
		break;
	       case 2:if(strcmpi(mo.name,"Passat")==0)
		 mo.disp();
		break;
	       case 3:if(strcmpi(mo.name,"Touareg")==0)
		 mo.disp();
		break;
	       case 4:clrscr();
		cout<<'\n';
		print();
		cout<<"\t\t\t\t    Volkswagon\n";
		print1();
		v.dis();
		break;
	     }}
	      }while(f2.eof()==0);
	      f2.close();
	     break;
	case 2:clrscr();
	     cout<<'\n';
	     print();
	     cout<<"\t\t\t\t   Audi\n";
	     print1();
	     cout<<"\n\n1.A4\n\n2.A6\n\n3.A8\n\n4.Supplier details\n\nEnter choice:";
	     cin>>ch2;
	     cout<<'\n';
	     f2.open("c:\\tcc\\models.dat");
	     do{f2.read((char*)&mo,sizeof(mo));
	     if(mo.brnd=='a'&&f2.eof()==0)
	     {switch(ch2)
	     { case 1:if(strcmpi(mo.name,"A4")==0)
		 mo.disp();
		break;
	       case 2:if(strcmpi(mo.name,"A6")==0)
		 mo.disp();
		break;
	       case 3:if(strcmpi(mo.name,"A8")==0)
		 mo.disp();
		break;
	       case 4:clrscr();
		cout<<'\n';
		print();
		cout<<"\t\t\t\t    Audi\n";
		print1();
		a.dis();
		break;
	      }}
	    }while(f2.eof()==0);
	    f2.close();
	     break;
	case 3:clrscr();
	     cout<<'\n';
	     print();
	     cout<<"\t\t\t\t    Skoda\n";
	     print1();
	     cout<<"\n\n1.Octavia\n\n2.Laura\n\n3.Superb\n\n4.Fabia\n\n5.Supplier details\n\nEnter choice:";
	     cin>>ch2;
	     cout<<'\n';
	     f2.open("c:\\tcc\\models.dat");
	     do{f2.read((char*)&mo,sizeof(mo));
	     if(mo.brnd=='s'&&f2.eof()==0)
	     {switch(ch2)
	     { case 1:if(strcmpi(mo.name,"Octavia")==0)
		 mo.disp();
		break;
	       case 2:if(strcmpi(mo.name,"Laura")==0)
		 mo.disp();
		break;
	       case 3:if(strcmpi(mo.name,"Superb")==0)
		 mo.disp();
		break;
	       case 4:if(strcmpi(mo.name,"Fabia")==0)
		 mo.disp();
		break;
	       case 5:clrscr();
		cout<<'\n';
		print();
		cout<<"\t\t\t\t    Skoda\n";
		print1();
		s1.dis();
		break;
	      }}
	    }while(f2.eof()==0);
	    f2.close();
	     break;
	case 4:clrscr();
	     cout<<'\n';
	     print();
	     cout<<"\t\t\t\t    Honda\n";
	     print1();
	     cout<<"\n\n1.City\n\n2.Accord\n\n3.Civic\n\n4.CRV\n\n5.Supplier details\n\nEnter choice:";
	     cin>>ch2;
	     cout<<'\n';
	     f2.open("c:\\tcc\\models.dat");
	     do{f2.read((char*)&mo,sizeof(mo));
	     if(mo.brnd=='h'&&f2.eof()==0)
	     {switch(ch2)
	     { case 1:if(strcmpi(mo.name,"City")==0)
		 mo.disp();
		break;
	       case 2:if(strcmpi(mo.name,"Accord")==0)
		 mo.disp();
		break;
	       case 3:if(strcmpi(mo.name,"Civic")==0)
		 mo.disp();
		break;
	       case 4:if(strcmpi(mo.name,"CRV")==0)
		 mo.disp();
		break;
	       case 5:clrscr();
		cout<<'\n';
		print();
		cout<<"\t\t\t\t    Honda\n";
		print1();
		h.dis();
		break;
	      }}
	    }while(f2.eof()==0);
	    f2.close();
	     break;
      }
      break;
 case 2:textbackground(7);
      textcolor(0);
      clrscr();
      cout<<'\n';
      print();
      cout<<"\t\t\t\t    Accessories\n";
      print1();
      cout<<"\n\n15.Stereo system\n\n16.Sensors\n\n17.Spoilers\n\n18.wheels\n\n19.Fancy lights\n\nEnter choice:";
      cin>>ch1;
      f2.open("accs.dat");
     do{f2.read((char*)&ac,sizeof(ac));
      if(ac.rcrd_no==ch1&&f2.eof()==0)
       { ac.display();
	 break;
       }
	   }while(f2.eof()==0);
      f2.close();
      break;

 case 3:textbackground(7);
      textcolor(1);
      clrscr();
      cout<<'\n';
      print();
      cout<<"\t\t\t\t Customer details\n";
      print1();
      cout<<"\n\n1.Customer Booking \n\n2.Customer Database\n\nEnter Choice:\a";
      cin>>ch2;
      if(ch2==1)
       {cus.readdata();
	f1.open("cust.dat",ios::app);
	f1.write((char*)&cus,sizeof(cus));
	f1.close();
	}
      else if(ch2==2)
      {cout<<"\n\nEnter cust no:";
       cin>>no;
       f2.open("cust.dat");
       do{f2.read((char*)&cus,sizeof(cus));
	  if(no==cus.no&&f2.eof()==0)
	   cus.dispdata();
	}while(f2.eof()==0);
       f2.close();
       }
      break;

 case 4:textbackground(0);
      textcolor(6);
      clrscr();
      cout<<'\n';
      print();
      cout<<"\t\t\t     ZONTOCQ MOTORS LTD.\n\t\t\t\t\t   - Elegance Personified..!\n";
      print1();
      cout<<"\n\n1.Annual report\n\n2.Customer report\n\n3.Supplier report";
      cout<<"\n\nEnter choice:";
      cin>>ch2;
      cout<<"\n\n";
      if(ch2==1)
      {clrscr();
       cout<<'\n';
       print();
       cout<<"\t\t\t     Annual Report\n";
       print1();
       ann.calc();
       ann.disp_ann();
       }
      else if(ch2==2)
      {clrscr();
       cout<<'\n';
       print();
       cout<<"\t\t\t     Customer Report\n";
       print1();
       int d,m,y;
       ifstream ff("cust.dat");
       ff.seekg(0,ios::end);
       if(ff.tellg()!=0)
       {ff.seekg(0);
       while(ff.read((char*)&cus,sizeof(cus)));
       cout<<"\n\nNumber of customers:"<<cus.no;
       getch();
       cout<<"\n\nCustomers purchased on the entered date:\n";
       cus1.date_custdisp();
       getch();
       cout<<"\n\nCustomers purchased cars above Rs 20lakhs:";
       cus1.amt_custdisp();
       getch();
       cout<<"\n\nCustomers having bought Volkswagon cars:\n";
       cus1.car_custdisp('v');
       getch();
       cout<<"\n\nCustomers having bought Audi cars:\n";
       cus1.car_custdisp('a');
       getch();
       cout<<"\n\nCustomers having bought Skoda cars:\n";
       cus1.car_custdisp('s');
       getch();
       cout<<"\n\nCustomers having bought Honda cars:\n";
       cus1.car_custdisp('h');
       getch();
       }
      else cout<<"No customers.";
      }
      else if(ch2==3)
      {clrscr();
       cout<<'\n';
       print();
       cout<<"\t\t\t     Supplier report\n";
       print1();
       cout<<"\n\n1.Volkswagon\n\n2.Audi\n\n3.Skoda\n\n4.Honda\n\nEnter choice:";
       cin>>ch3;
       switch(ch3)
       { case 1:clrscr();
	    cout<<'\n';
	    print();
	    cout<<"\t\t\t\t    Volkswagon\n";
            print1();
            v.dis();
            getch();
	    cout<<"\n\nCustomers having bought Volkswagon cars:\n";
	    cus1.car_custdisp('v');
            getch();
	    ifstream fo("models.dat");
	    int s=1;
	    cout<<"\n\nVolkswagon cars and their details:\n";
	    while(fo.read((char*)&mo,sizeof(mo)))
             if(mo.brnd=='v')
             {cout<<'\n'<<s<<'.';
              mo.disp();
	      s++;
	      }
	     fo.close();
	     getch();
             break;
         case 2:clrscr();
            cout<<'\n';
            print();
            cout<<"\t\t\t\t    Audi\n";
	    print1();
	    a.dis();
            getch();
            cout<<"\n\nCustomers having bought Audi cars:\n";
	    cus1.car_custdisp('a');
	    ifstream fo1("models.dat");
	    getch();
             s=1;
             cout<<"\n\nAudi cars and their details:\n";
             while(fo1.read((char*)&mo,sizeof(mo)))
	      if(mo.brnd=='a')
	      {cout<<'\n'<<s<<'.';
            mo.disp();
            s++;
	    }
	      fo1.close();
	      getch();
	      break;
          case 3: clrscr();
              cout<<'\n';
              print();
	      cout<<"\t\t\t\t    Skoda\n";
	      print1();
	      s1.dis();
	      getch();
              cout<<"\n\nCustomers having bought Skoda cars:\n";
              cus1.car_custdisp('s');
              ifstream fo2("models.dat");
	     getch();
             s=1;
             cout<<"\n\nSkoda cars and their details:\n";
	     while(fo2.read((char*)&mo,sizeof(mo)))
	      if(mo.brnd=='s')
	      {cout<<'\n'<<s<<'.';
	       mo.disp();
               s++;
               }
             fo2.close();
             getch();
             break;
	  case 4:clrscr();
	     cout<<'\n';
             print();
             cout<<"\t\t\t\t    Honda\n";
	     print1();
	     h.dis();
	     getch();
	     cout<<"\n\nCustomers having bought Honda cars:\n";
             ifstream fo3("models.dat");
             cus1.car_custdisp('h');
	     getch();
	      s=1;
              cout<<"\n\nHonda cars and their details:\n";
              while(fo3.read((char*)&mo,sizeof(mo)))
	       if(mo.brnd=='h')
	       {cout<<'\n'<<s<<'.';
	    mo.disp();
	    s++;
            }
              fo3.close();
              getch();
	      break;
	 }
       }
      break;

 case 5:
      clrscr();
      cout<<'\n';
      print();
      cout<<"\t\t\t   ZONTOCQ MOTORS LTD.\n\t\t\t\t\t   - Elegance Personified..!\n";
      print1();
      char *pa;
      pa=getpass("\n\nENTER PASSWORD:");
      if(strcmpi(pa,"zontocq")==0)
      {clrscr();
       print();
       cout<<"\t\t\t   ZONTOCQ MOTORS LTD.\n\t\t\t\t\t   - Elegance Personified..!\n";
       print1();
       cout<<"\n\n1.Add automobile to database\n\n2.Add accessories to database\n\n";
       cout<<"3.Modify automobile database\n\n4.Modify accessories database\n\nEnter choice:";
       cin>>ch2;
       switch(ch2)
       {case 1:ofstream f3("models.dat",ios::app);
	   char ch;
	   cout<<"\n\n";
	   do{mo.read();
	   f3.write((char*)&mo,sizeof(mo));
	   cout<<"continue:";
	   cin>>ch;
	      }while(ch=='y');
	  f3.close();
	  break;
       case 2:ofstream f5("accs.dat",ios::app);
	  char ch1;
	  cout<<"\n\n";
	  do{ac.read();
	  f5.write((char*)&ac,sizeof(ac));
	  cout<<"continue:";
	  cin>>ch1;
	  }while(ch1=='y');
	  f5.close();
	  break;
       case 3:fstream f4;
	  f4.open("models.dat",ios::in|ios::out);
	  int cho1,p;
	  cout<<"\n1.Jetta\n2.Passat\n3.Touareg\n4.A4\n5.A6\n6.A8\n7.Octavia\n8.Laura\n9.Superb\n10.Fabia\n11.City\n12.Accord\n13.Civic\n14.CRV\nEnter record no to be modified:";
	  cin>>cho1;
	  if(!f4) cout<<"File not opened";
	  do{f4.read((char*)&mo,sizeof(mo));
	  if(cho1==mo.rcrd_no)
	  {mo.read();
	   break;
	   }
	   }while(f4.eof()==0);
	   if(f4.eof()==0)
	   {f4.clear();
	    f4.seekg(0);
	    ofstream f3("models1.dat",ios::app);
	    f3.write((char*)&mo,sizeof(mo));
	    while(f2.read((char*)&mo,sizeof(mo)))
	     if(cho1!=mo.rcrd_no)
	      f3.write((char*)&mo,sizeof(mo));
	     f4.close();
	     f3.close();
	     remove("models.dat");
	     p=rename("models1.dat","models.dat");
	      }
	    else cout<<"Record not found.";
	    break;
	case 4:ifstream f6;
	  f6.open("accs.dat");
	  int cho2;
	  cout<<"\n15.Stereo system\n16.Sensors\n17.Spoilers\n18.wheels\n19.Fancy lights\n\nEnter record no to be modified:";
	  cin>>cho2;
	  if(!f6) cout<<"File not opened";
	  while(f6.read((char*)&ac,sizeof(ac)))
	  if(cho2==ac.rcrd_no)
	  {ac.read();
	   break;
	   }
	   if(f6.eof()==0)
	   {f6.clear();
	    f6.seekg(0);
	    ofstream f3("accs1.dat",ios::app);
	    f3.write((char*)&ac,sizeof(ac));
	    while(f6.read((char*)&ac,sizeof(ac)))
	     if(cho2!=ac.rcrd_no)
	      f3.write((char*)&ac,sizeof(ac));
	    f3.close();
	    remove("accs.dat");
	    p=rename("accs1.dat","accs.dat");
	     }
	    else cout<<"Record not present.";
	    f6.close();
	    break;
	    }
	       }
	   else
	   {  cout<<"INCORRECT PASSWORD";
	      break; }
	       break;

 case 6:clrscr();
    print();
    cout<<"\t\t\tThank you for using.!!\n";
    cout<<"\n\t\t\t\tDone by:Arun Shankar\n\t\t\t\t\tS.Vaikunth\n\t\t\t\t\tSiddharth Kumar\n\n";
    print1();
    getch();
    exit(0);
	     }
 cout<<"\n\nTo go back to main options, press M.";
 cin>>op;
 cout<<'\n';
 print();
 textbackground(0);
 textcolor(3);
 }while(toupper(op)=='M');
 getch();
 clrscr();
 print();
 cout<<"\t\t\tThank you for using.!!\n";
 cout<<"\n\t\t\t\tDone by:Arun Shankar\n\t\t\t\t\tS.Vaikunth\n\t\t\t\t\tSiddharth Kumar\n\n";
 print1();
 getch();
 }