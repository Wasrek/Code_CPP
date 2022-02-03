/*
    TASK:Possess
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double k,d,bk,s=15,x,y,xaxis,r,f,h;
    scanf("%lf %lf",&k,&d);
    if(k==40)
    {
       d=d+15.00;
       x=d/60.00;
       y=fmod(d,60);
       if(fmod(x,2)<1)
       {
          xaxis=y;
       }else
       {xaxis=60-y;}
       printf("%.1lf %.1lf",xaxis,40.0);
    }else
    if(k<40)
    {
        bk=40-k;
        r=sqrt(pow(15,2)+pow(bk,2));
        f=(15*(d+r))/r;
        if(f<=60)
        {
            h=(f*bk)/15;
            printf("%.1lf %.1lf",f,h+k);
        }else
        if(f>60)
        {
            x=f/60.00;
            y=fmod(f,60);
            if(fmod(x,2)<1)
       {
          xaxis=y;
       }else
       {xaxis=60-y;}

       printf("%.1lf %.1lf",xaxis,h+k);

        }
    }else
    if(k>40)
    {
        bk=k-40;
        r=sqrt(pow(15,2)+pow(bk,2));
        f=(15*(d+r))/r;
        if(f<=60)
        {
            h=f*bk/15;
            printf("%.1lf %.1lf",f,k-h);
        }else
        if(f>60)
        {

        }
    }
    return 0;
}
