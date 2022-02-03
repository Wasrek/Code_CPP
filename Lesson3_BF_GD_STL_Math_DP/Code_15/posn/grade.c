#include<stdio.h>
int main()
{
int a,b,c,x;
scanf("%d %d %d",&a,&b,&c);
x=a+b+c;
if(x<=100 && x>=0){
if(x>=80){
printf("A");
}else
if(x>=75){
printf("B+");
}else
if(x>=70){
printf("B");
}else
if(x>=65){
printf("C+");
}else
if(x>=60){
printf("C");
}else
if(x>=55){
printf("D+");
}else
if(x>=50){
printf("D");
}else
{printf("f");}
}
}
