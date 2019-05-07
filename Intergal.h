#ifndef INTERGAL_H_INCLUDED
#define INTERGAL_H_INCLUDED
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
int integral(double a,double b,double (*f)(double),double eps,double graind,int iterate,double &res){
    double eps1=0;
    double L=0,h,p,f1=0,f2=0,L1=0;
    int i=0,out=0;
    res=0;
    p=fabs(b-a);
    while((eps1<eps)&&(i<iterate)){
        h=p/graind;
        f1=0;
        f2=0;
        for(unsigned j=1;j<=graind;j++){
            f1+=f(a+(j-0.5)*h);
        }
        for(unsigned j=1;j<=graind-1;j++){
            f2+=f(a+j*h);
        }
        L=(h/6)*(f(a)+f(b)+4*f1+2*f2);
        graind=graind*3;
        h=p/graind;
        f1=0;
        f2=0;
        for(unsigned j=1;j<=graind;j++){
            f1+=f(a+(j-0.5)*h);
        }
        for(unsigned j=1;j<=graind-1;j++){
            f2+=f(a+j*h);
        }
        L1=(h/6)*(f(a)+f(b)+4*f1+2*f2);
        eps1=fabs(L-L1);
        i++;
        res=L1;
    }
    if((eps1<=eps)&&(i==iterate))out=1;
    return out;
}

#endif // INTERGAL_H_INCLUDED
