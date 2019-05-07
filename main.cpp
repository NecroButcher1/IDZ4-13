#include "Intergal.h"
double Integral1(double x);
double Integral2(double x);
void menu();
void Integration_function(double &a,double &b,double &eps,double &g,int &p);

int main()
{
    double p,g,a,b,eps,graind,q1,q2;
    int chm=0,checker=0,x,iterate;
    double (*I1)(double)=Integral1;
    double (*I2)(double)=Integral2;
    double (*I3)(double)=exp;
    double (*I4)(double)=sin;
    while(chm!=5){
        menu();
        cin>>chm;
        while((chm<1)||(chm>5)||(!cin)){
            system("cls");
            menu();
            cin.clear();
            cin.ignore(32767,'\n');
            cin>>chm;
        }
        if(chm==1){
            system("cls");
            Integration_function(a,b,eps,graind,iterate);
            checker=integral(a,b,I1,eps,graind,iterate,p);
            if(checker==0){
                cout<<p<<endl;
            }
            if(checker==1){
                cout<<"Iterate"<<endl;
                cout<<p<<endl;
            }
            chm=0;
        }
        if(chm==2){
            system("cls");
            Integration_function(a,b,eps,graind,iterate);
            checker=integral(a,b,I2,eps,graind,iterate,p);
            if(checker==0){
                cout<<p<<endl;
            }
            if(checker==1){
                cout<<"Iterate"<<endl;
                cout<<p<<endl;
            }
            chm=0;
        }
        if(chm==3){
            system("cls");
            Integration_function(a,b,eps,graind,iterate);
            checker=integral(a,b,I3,eps,graind,iterate,p);
            if(checker==0){
                cout<<p<<endl;
            }
            if(checker==1){
                cout<<"Iterate"<<endl;
                cout<<p<<endl;
            }

            chm=0;
            q1=exp(b)-exp(a);
            cout<<"NL :"<<q1<<endl;
        }
        if(chm==4){
            system("cls");
            Integration_function(a,b,eps,graind,iterate);
            checker=integral(a,b,I4,eps,graind,iterate,p);
            if(checker==0){
                cout<<p<<endl;
            }
            if(checker==1){
                cout<<"Iterate"<<endl;
                cout<<p<<endl;
            }

            chm=0;
            q1=-cos(b)+cos(a);
            cout<<"NL :"<<q1<<endl;
        }
    }

    return 0;
}
double Integral1(double x){
    return cos(pow(10,x));
}
double Integral2(double x){
    return pow(2,pow(x,3));
}
void Integration_function(double &a,double &b,double &eps,double &g,int &p){
    system("cls");
    cout<<"Left border A:";
    cin>>a;
    while(!cin){
        system("cls");
        cin.clear();
        cin.ignore(32767,'\n');
        cout<<"Left border A:";
        cin>>a;
    }
    system("cls");
    cout<<"Right border B:";
    cin>>b;
    while(!cin){
        cin.clear();
        system("cls");
        cin.ignore(32767,'\n');
        cout<<"Right border B:";
        cin>>b;
    }
    system("cls");
    cout<<"Accuracy :";
    cin>>eps;
    while(!cin){
        cin.clear();
        cin.ignore(32767,'\n');
        system("cls");
        cout<<"Accuracy :";
        cin>>eps;
    }
    system("cls");
    cout<<"Partition :";
    cin>>g;
    while(!cin){
         cin.clear();
        cin.ignore(32767,'\n');
        system("cls");
        cout<<"Partition :";
        cin>>g;
    }
    system("cls");
    cout<<"Iterate :";
    cin>>p;
     while(!cin){
        cin.clear();
        cin.ignore(32767,'\n');
        system("cls");
        cout<<"Iterate :";
        cin>>p;
    }
}
void menu(){
    cout<<"==================="<<endl;
    cout<<"[1].Cos(10^x)"<<endl;
    cout<<"[2].2^(x^3)"<<endl;
    cout<<"[3].Exp"<<endl;
    cout<<"[4].Sin "<<endl;
    cout<<"[5]exit"<<endl;
    cout<<"==================="<<endl;
    cout<<":";
}
