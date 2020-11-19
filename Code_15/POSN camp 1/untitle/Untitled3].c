#include<stdio.h>
void main()
{
   int age;
   printf("How old are you");
   scanf("%d" ,&age);
   if(age>60){
   printf("you are old");
   }else{printf("You are young");}
   printf("\nGood bye");
   return 0;
}
