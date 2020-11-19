#include<stdio.h>
#include<math.h>
int main()
{
   double a,b,c,d,e,f,x,y,z,k,r;
   scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
   x=sqrt(pow(a-c,2)+pow(b-d,2));
   y=sqrt(pow(c-e,2)+pow(d-f,2));
   z=sqrt(pow(e-a,2)+pow(f-b,2));
   k=(x+y+z)/2;
   r=sqrt(k*(k-x)*(k-y)*(k-z));
   printf("%.2lf",r);
}
