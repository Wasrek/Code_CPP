/*
    TASK:Intro05
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,x2,y2,x3,y3,k,ci,area,s,a1,b1,c1;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&k);
    double a,b,c;
    a=sqrt((((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
    b=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
    c=sqrt((((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3))));
    a1=a*k;
    b1=b*k;
    c1=c*k;
    ci= (M_PI*(k*k));
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%.2lf\n",area);
    printf("%.2lf",ci+a1+b1+c1);


    return 0;
}
