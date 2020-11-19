#include<stdio.h>
void kersa(char s[]){
   printf("your name is %s\n",s);
}
void Helloname(char name[100])
{
   printf("Hello %s",name);
}
int main(){
   char name[10];
   printf("What is your nickname ? ==>");
   scanf("%s",name);
   kersa(name);
   Helloname(name);
   return 0;
}
