#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <stdio.h>
using namespace std;
static int i,cr,gy,ne;
//class idpaswrd
class idpaswrd
 {
    public:
    string id,password;
    void newidpas();
    void newwrite(class idpaswrd obj);
};
void idpaswrd::newidpas()
{
    cout<<"create your id and password\nid:\n";
    cin>>id;
    cout<<"password\n";
    cin>>password;
}
void idpaswrd::newwrite(class idpaswrd obj)
 {
 ofstream ip("idpas.txt",ios::app);
 //ip.write((char *)&obj,sizeof(obj));
 ip<<obj.id<<"$"<<obj.password<<"$";
 ip<<"\n";
 }
 //class idpaswrd
 class newdetails:public idpaswrd
 {
 public:
 string name,dname,pres,medrec;
 void newdet(class idpaswrd obj);
 void newdwrite(class newdetails obj);
 void admindetails(string id);
 };

void newdetails::newdet(class idpaswrd obj)
{
id=obj.id;
cout<<"enter your name\n";
cin>>name;
cout<<"what type of doctor you want to consult\ngynae\nneuro\ncardio\n";
cin>>dname;
if(dname=="gynae")
{
fstream g("gynae.txt",ios::out|ios::app);
g<<name<<'$';
}
else if(dname=="neuro")
{
fstream n("neuro.txt",ios::out|ios::app);
n<<name<<'$';
}
else if(dname=="cardio")
{
fstream c("cardio.txt",ios::out|ios::app);
c<<name<<'$';
}
}
void newdetails::newdwrite(class newdetails obj)
{
fstream pd("patdet.txt",ios::out|ios::app);
 pd<<obj.id<<'$'<<obj.name<<'$'<<obj.dname<<'$';
 pd<<"\n";
}
void newdetails::admindetails(string id)
{
string s;int f=0,am;
      fstream pd("patdet.txt",ios::in);
      fstream fd("finaldet.txt",ios::out|ios::in|ios::app);
      fstream rep("replace.txt",ios::out|ios::app);
      cout<<"press 1 if you want to add details\npress 2 if you want to modify details\n";
      cin>>am;
 if(am==1)
 {
      if(pd.is_open())
        {
          while(!pd.eof())
           {
            getline(pd,s,'$');
            if(id==s)
            {
            f=1;
            fd<<id<<'$';
            getline(pd,s,'$');
            fd<<s<<'$';
            getline(pd,s,'$');
            fd<<s<<'$';
            break;
            }
            getline(pd,s,'\n');
           }
        }
        pd.close();
        if(f==0)
        {
        cout<<"no such id exists\n";
        return;
        }
        cout<<"enter medical record of "<<id<<"\n";
        cin>>s;
        fd<<s<<'$';
        cout<<"enter prescription of "<<id<<"\n";
        cin>>s;
        fd<<s<<'$'<<"\n";
        fd.close();
}
/*else if(am==2)
{
if(fd.is_open())
        {
          while(!fd.eof())
           {
            getline(fd,s,'$');
            if(id==s)
            {
            rep<<s<<'$';
            getline(fd,s,'$');
            rep<<s<<'$';
            getline(fd,s,'$');
            rep<<s<<'$';
            cout<<"enter medical record\n";
            cin>>s;
            rep<<s<<'$';
            cout<<"enter prescription\n";
            cin>>s;
            rep<<s<<'$'<<"\n";
            getline(fd,s,'\n');
            }
            else
            {
            rep<<s<<'$';
            getline(fd,s,'$');
            rep<<s<<'$';
            getline(fd,s,'$');
            rep<<s<<'$';
            getline(fd,s,'$');
            rep<<s<<'$';
            getline(fd,s,'$');
            rep<<s<<'$'<<"\n";
            }
           }
        }
fd.close();
rep.close();
}*/
}
void number()
{
    ifstream ip("idpas.txt");
    string line;

       if(ip.is_open())
        {
          while(!ip.eof())
           {
            getline(ip,line);
            i++;
           }
        ip.close();
        }
   cout<<"number of lines : " << i << endl;
}//to calculate total number of patients in list


void newpatient()
{
i++;
void bookappointment();
class idpaswrd npat;
class newdetails ndet;
npat.newidpas();
npat.newwrite(npat);
ndet.newdet(npat);
ndet.newdwrite(ndet);
bookappointment();
}
void bookappointment()
{
time_t now = time(0);
tm *ltm=localtime(&now);
cout<<endl<<"Your appointment is fixed for " << 1900+ltm->tm_year<<"/"<<(ltm->tm_mon+1)%12<< "/"<<  (ltm->tm_mday+7)%30<< endl;
}
int checkpasword(string idn,string p)
{   string s;
    int flag=0;
     fstream ip("idpas.txt",ios::in);
            if(ip.is_open())
        {
          while(!ip.eof())
         {
            getline(ip,s,'$');
            if(s==idn)
            {
            getline(ip,s,'$');
            if(s==p)
            {
            flag=1;
            break;
            }
            }
            getline(ip,s,'\n');
         }
        ip.close();
        }
        return flag;
}
void showdetails(string idn)
{
int f=0,o=0,p=0;;
string password,s;
cout<<"enter password\n";
cin>>password;
if(checkpasword(idn,password))
{
     fstream fd("finaldet.txt",ios::in|ios::app|ios::out);
            if(fd.is_open())
        {
          while(!fd.eof())
           {
            getline(fd,s,'$');
            f++;
            if(idn==s)
            {
            o=1;
            break;
            }
            getline(fd,s,'\n');
           }

        }
        if(fd.is_open()&&o==1)
        {
            cout<<"id: "<<idn<<endl;
            getline(fd,s,'$');
            cout<<"name: "<<s<<endl;
            getline(fd,s,'$');
            cout<<"doctor: "<<s<<endl;
            getline(fd,s,'$');
            cout<<"medred: "<<s<<endl;
            getline(fd,s,'$');
            cout<<"pres: "<<s<<endl;

            fd.close();
        }
}
        if(o==0)
        {
        fstream pd("patdet.txt",ios::in|ios::app|ios::out);
            if(pd.is_open())
        {
          while(!pd.eof())
           {
            getline(pd,s,'$');
            if(idn==s)
            {
            p=1;
            break;
            }
            getline(pd,s,'\n');
           }

        }
        if(pd.is_open()&&p==1)
        {
            cout<<"id: "<<idn<<endl;
            getline(pd,s,'$');
            cout<<"name: "<<s<<endl;
            getline(pd,s,'$');
            cout<<"doctor: "<<s<<endl;
            getline(pd,s,'$');
            pd.close();
        }

       }

if(p==0&&o==0)
cout<<"wrong password.Try again\n";
}
int checkid(string idn)
{
int f=0;
string s;
ifstream ip("idpas.txt");

       if(ip.is_open())
        {
          while(!ip.eof())
           {
            getline(ip,s,'$');
            if(idn==s)
            {
            f=1;
            break;
            }
            getline(ip,s,'\n');
           }
        ip.close();
        }
        return f;
}
void oldpatient()
{
int f,l;
cout<<"enter your login id\n";
string idn;
cin>>idn;
f=checkid(idn);
if(f)
{cout<<"press 1 if you want to book an appointment\npress 2 to view your details\n";
cin>>l;
if(l==2)
showdetails(idn);
if(l==1)
bookappointment();
}
else
cout<<"you dont have an account\n";
}
void admin()
{

string id;class newdetails nd;
cout<<"enter the id of patient,whose details you want to add or modify\n";
cin>>id;
nd.admindetails(id);
}
int main()
{
int n,m,p;string mp;
do
{
cout<<"......................welcome to patient record management......................\npress 1 to continue\npress 0 to exit\n";
cin>>m;
switch(m)
{

case 1:
cout<<"                            if you are admin.please enter 1\n                          if you are an old patient,please enter 2\n                          if you are a new patient please enter 3\n";
cin>>n;
switch(n)
{
case 1:
cout<<"enter admin's password\n";
cin>>mp;
if(mp=="mansiprerna")
admin();
else
cout<<"wrong password\n";
break;
case 2:oldpatient();
break;
case 3:newpatient();
break;
}
cout<<"press 1 to goto main menu\n";
cin>>p;
break;
case 0:exit(0);
break;
}
}while(p);
}
