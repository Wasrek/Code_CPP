#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
double r,a,v;
scanf("%lf",&r);
a=pow(r,2)*acos(-1);
v=4/3*pow(r,3)*acos(-1);
printf("%.2lf \n%.2lf",a,v);

return 0;
}
