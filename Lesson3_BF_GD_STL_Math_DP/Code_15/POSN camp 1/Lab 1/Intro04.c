/*
    TASK:Intro04
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<stdio.h>
int main()
{
    double d,a,b,c,s;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    s=(a/(c-b))*d;
    printf("%.2lf",s);
    return 0;
}
