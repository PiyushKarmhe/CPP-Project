#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct accd{
 int e; long p;
};
void assignacn();
class account
{
 private:
 long accno;
 char name[20];
 char acctype;
 double balance;
 public:
 account()
 {
  accno=-1;
  name[20]='*';
  acctype='g';
  balance=0;
 }
 void getdata()
 {
  cout<<"\n\t\tGive ACCOUNT HOLDER NAME : ";
  gets(name);
  cout<<"\n\t\tGive ACCOUNT TYPE(S/C) : ";
  cin>>acctype;
  cout<<"\n\t\tBALANCE : ";
  cin>>balance;
  assvalue();
 }
 void assvalue()
 {
  acctype=toupper(acctype);
  strupr(name);
  assignacn();
 }
 void setacn(long acn)
 {
  accno=acn;
 }
 void disp()
 {
  cout<<"\n\t\tACCOUNT No.: "<<accno;
  cout<<"\n\t\tACCOUNT HOLDER NAME : "<<name;
  cout<<"\n\t\tACCOUNT TYPE : "<<acctype;
  cout<<"\n\t\tBALANCE : "<<balance;
 }
 int withdraw(double x)
 {
  if(x>=balance)
  {
    cout<<"\n\t\tInsufficient BALANCE!!!";
    return 0;
  }
  else
  {
    balance-=x;
    return 1;
  }
 }
 void deposit(double x)
 {
  balance+=x;
 }
 long accn()
 {
  return accno;
 }
 double rbalance()
 {
  return balance;
 }
 char racct()
 {
  return acctype;
 }
 void editaccname()
 {
  cout<<"\n\t\tGive new Name : ";
  gets(name);
  strupr(name);
 }
 void editacctype()
 {
  cout<<"\n\t\tGive New Account Type : ";
  cin>>acctype;
  acctype=toupper(acctype);
 }
};
account o;
accd checkaccexistance(long acn)
{
 account b;
 accd s;  long x=0;
 fstream fio;
 fio.open("ACC.dat",ios::in|ios::binary|ios::out);
 fio.seekg(0);
 if(fio.fail())
	{
		cout<<"\t\t\tInput file opening failed.\n";
		getch();
		exit(1);
	}
 while(!fio.eof())
 {
  x=fio.tellg();
  fio.read((char*)&b,sizeof(account));
  if(b.accn()==acn)
  {
   s.e=1;
   s.p=x;
   fio.close();
   return(s);
  }
 }
 s.e=0;
 s.p=fio.tellg();
 fio.close();
 return(s);
}
void assignacn()
{
 long acn=1;
 accd s;
 s.e=1;
 while(s.e)
 {
   s=checkaccexistance(acn);
   if(s.e)
   {
    acn+=1;
   }
   else
   {
    o.setacn(acn);
    break;
   }
 }
}
void deleteacc()
{
 long acn;
 account m;
 char found='n';
 cout<<"\n\n\n\t\tGive Account no. to delete : ";
 cin>>acn;
 fstream fr, fw;
 fr.open("ACC.dat",ios::binary|ios::in);
 fw.open("Temp.dat",ios::binary|ios::out);
 while(fr.read((char*)&m,sizeof(account)))
 {
  if(acn==m.accn())
  {
   m.disp();
   cout<<"\n\t\tPress any key to delete";
   getch();
   found='f';
   cout<<"\n\t\tAccount deteted";
  }
  else
   fw.write((char*)&m,sizeof(account));
 }
 if(found!='f')
  cout<<"\n\t\tAccount not found!";
 fr.close();
 fw.close();
 remove("ACC.dat");
 rename("Temp.dat","ACC.dat");
}
void displayacc()
{
 int c,a;
 char t,ch;
 double b;
 account m;
 display:
 fstream fr;
 clrscr();
 fr.open("ACC.dat",ios::binary|ios::in);
 cout<<"\n\n\n\t\tGive the parameter on which you want to display : ";
 cout<<"\n\t\t1.Account Type\n\t\t2.Balance\n\t\tChoice : ";
 cin>>c;
 switch(c)
 {
  case 1: cout<<"\n\t\tGive the Account Type : ";
	  cin>>t;
	  while(fr.read((char*)&m,sizeof(account)))
	  {
	   if(toupper(t)==m.racct())
	   {
	    m.disp();
	    getch();
	   }
	  }
  break;
  case 2: cout<<"\n\t\tGive the Amount : ";
	  cin>>b;
	  bal:
	  cout<<"\n\n\t\tGive Choice : ";
	  cout<<"\n\t\t1.Display Account with balance<=amount";
	  cout<<"\n\t\t2.Display Account with balance>=amount";
	  cout<<"\n\t\tChoice : ";
	  cin>>a;
	  switch(a)
	  {
	   case 1: while(fr.read((char*)&m,sizeof(account)))
		   {
		    if(b>=m.rbalance())
		    {
		     m.disp();
		     getch();
		    }
		   }
	   break;
	   case 2: while(fr.read((char*)&m,sizeof(account)))
		   {
		    if(b<=m.rbalance())
		    {
		     m.disp();
		     getch();
		    }
		   }
	   break;
	   default: cout<<"\n\t\tINVALID INPUT!!!";
		    cout<<"\n\t\tPress any key to go back to main menu!!";
		    getch();
		    goto bal;
	  }
  break;
  default : cout<<"\n\t\tINVALID INPUT!!!";
	    cout<<"\n\t\tPress any key to go back to main menu!!";
	    getch();
	    goto display;
 }
 cout<<"\n\t\tDo you want to do more\?(Y/N)";
 cout<<"\n\t\tChoice : ";
 cin>>ch;
 if(ch=='Y'||ch=='y')
 goto display;
}
void edit(long acn)
{
 int ch;
 account m;
 char found='n';
 editing:
 fstream fr, fw;
 fr.open("ACC.dat",ios::binary|ios::in);
 fw.open("Temp.dat",ios::binary|ios::out);
 while(fr.read((char*)&m,sizeof(account)))
 {
  if(acn==m.accn())
  {
   found='f';
   choice:
   clrscr();
   m.disp();
   cout<<"\n\n\t\tWhat you want to edit : ";
   cout<<"\n\t\t1.Account Holder Name\n\t\t2.Account Type\n\t\tChoice : ";
   cin>>ch;
   switch(ch)
   {
    case 1: m.editaccname();
	    m.disp();
    break;
    case 2: m.editacctype();
	    m.disp();
    break;
    default: cout<<"\n\t\tINVALID INPUT!!!";
	     cout<<"\n\t\tPress any key to redo!!";
	     getch();
	     goto choice;
   }
   fw.write((char*)&m,sizeof(account));
  }
  else
   fw.write((char*)&m,sizeof(account));
 }
 if(found!='f')
 {
  cout<<"\n\t\t\tAccount not found!";
  getch();
  goto editing;
 }
 fr.close();
 fw.close();
 remove("ACC.dat");
 rename("Temp.dat","ACC.dat");
}
void login()
{
 char pwd[9];
 cout<<"\n\t\tEnter admin password : ";
 char ch;
 int i=0;
 while(1)
 {
  ch=getch();
  if(ch==13)
  break;
  pwd[i++]=ch;
  cout<<'*';
 }
 pwd[i]='\0';
 if(strcmp(pwd,"admin")==0)
 {
  cout<<"\n\n\t\t\t    **Access enabled for ADMIN.**\n";
  cout<<"\n\t\tPress any key to continue";
  getch();
 }
 else
 {
  cout<<"\n\n\t\tIncorrect password\n\t\tPress any key to exit";
  getch();
  exit(0);
 }
}
int main()
{
 account a;
 char ans;
 int c,h;
 accd f;
 long acn;
 double amt;
 clrscr();
 cout<<"\n\n\n\t\t***--->WELCOME!!!!TO THE BANK PORTAL!!!<---***"<<endl;
 cout<<"\n\t\tYOU are the data administrator";
 cout<<"\n\t\tPress any KEY!!";
 getch();
 login();
 do{
    clrscr();
    start:
    cout<<"\n\n\n\t\tGive Choice : ";
    cout<<"\n\t\t1. New Account\n\t\t2. Existing Account\n\t\t3. Delete account";
    cout<<"\n\t\t4. Display Accounts\n\t\t5. Exit";
    cout<<"\n\t\tChoice : ";
    cin>>c;
    clrscr();
    switch(c)
    {
     case 1: char y;
	     do{
		fill:
		clrscr();
		cout<<"\n\n\n\t\tGive Details of new ACCOUNT holder ";
		o.getdata();
		acn=o.accn();
		fstream fio("ACC.dat",ios::out|ios::binary|ios::app);
		fio.write((char*)&o,sizeof(account));
		cout<<"\n\t\tACCOUNT details as ENTERED ABOVE";
		o.disp();
		cout<<"\n\t\t\tACCOUNT ADDED SUCCESSFULY!!";
		fio.close();
		cout<<"\n\t\tDO YOU WANT TO ADD MORE ACCOUNTS!!!(Y/N)";
		cout<<"\n\t\tCHOICE : ";
		cin>>y;
		}while(y=='y'||y=='Y');
	     break;
     case 2: char g;
	     do{
		 accsearch:
		 clrscr();
		 cout<<"\n\n\n\t\tGive ACCOUNT No. of existing ACCOUNT : ";
		 cin>>acn;
		 f=checkaccexistance(acn);
		if(f.e==0)
		{
		  cout<<"\n\t\tACCOUNT No. NOT FOUND!!!";
		  cout<<"\n\t\tGive VALIDE ACCOUNT No. ";
		  getch();
		  goto accsearch;
		}
		else
		{
		 clrscr();
		 fstream fio("ACC.dat",ios::in|ios::out|ios::binary);
		 fio.seekg(f.p);
		 fio.read((char*)&a,sizeof(account));
		 a.disp();
		 cout<<"\n\n\n\t\tGive Choice : ";
		 cout<<"\n\t\t1. Withdraw\n\t\t2. Deposit\n\t\t3. Edit Details";
		 cout<<"\n\t\tChoice : ";
		 cin>>h;
		 clrscr();
		switch(h)
		{
		  case 1: a.disp();
			  int k;
			  with:
			  cout<<"\n\t\tGive the ammount to withdraw : ";
			  cin>>amt;
			  k=a.withdraw(amt);
			  a.disp();
			  if(k)
			  {
			   fio.seekp(f.p);
			   fio.write((char*)&a,sizeof(account));
			   cout<<"\n\t\t\tTRANSACTION SUCCESSFUL!!";
			  }
			  else
			  goto with;
			  break;
		  case 2: cout<<"\n\t\tGive the amount to deposit : ";
			  cin>>amt;
			  a.deposit(amt);
			  a.disp();
			  fio.seekp(f.p);
			  fio.write((char*)&a,sizeof(account));
			  cout<<"\n\t\t\tTRANSACTION SUCCESSFUL!!";
			  break;
		  case 3: edit(acn);
			  break;
		default : cout<<"\n\t\tINVALID INPUT!!!";
			  cout<<"\n\t\tPress any key to go back to main menu!!";
			  getch();
			  goto accsearch;
	       }
	       fio.close();
	      }
	      cout<<"\n\t\tWANT TO DO MORE!!!(Y/N)";
	      cout<<"\n\t\tCHOICE : ";
	      cin>>g;
	    }while(g=='y'||g=='Y');
	    break;
     case 3: deleteacc();
     break;
     case 4: displayacc();
     break;
     case 5: exit(0);
     break;
     default : cout<<"\n\t\tINVALID INPUT!!!";
	       cout<<"\n\t\tPress any key to go back to main menu!!";
	       getch();
	       goto start;
    }
    cout<<"\n\t\tDo YOU WANT TO GOTO MAIN MENU (Y/N)\?";
    cout<<"\n\t\tChoice : ";
    cin>>ans;
 }while(ans=='Y'||ans=='y');
 return 0;
}