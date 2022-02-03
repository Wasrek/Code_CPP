#include<stdio.h>
#include<string.h>
int main()
{
char a;
scanf("%c",&a);
if(a>=97 && a<=122){
printf("Small");
}else
if(a>=65 && a<=90){
printf("Big");
}else
printf("Not Alphabet");


return 0;
}
