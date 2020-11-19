#include<stdio.h>
#include<string.h>
int main()
{
int a;
scanf("%d",&a);
if(a>0){
printf("Positive Integer");
}else
if(a<0){
printf("Negative Integer");
}else
if(a==0){
printf("Zero Integer");
}

return 0;
}
