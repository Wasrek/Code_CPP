#include<stdio.h>
int main()
{
int N,x,y,a,b,z,n;
scanf(" %d",&N);
n=(2*N)-1;
for(z=1;z<N;z++){
a=z;
b=n-(2*z);
for(x=1;x<=a;x++)
{
printf("+");
}
for(y=b;y>=1;y--)
{
printf("-");
}
for(x=1;x<=a;x++)
{
printf("+");
}
printf("\n");
}
for(x=1;x<=n;x++){
    printf("+");
}

return 0;
}
