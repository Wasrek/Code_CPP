#include<stdio.h>
void main()
{
   int scr;
   printf("Enter your score :");
   scanf(" %d",&scr);
   if(scr>=80)
   printf("A");
   else if(scr>=70)
    printf("B");
   else if(scr>=60)
    printf("C");
   else if(scr>=50)
    printf("D");
   else printf("fail");
   printf("\nSee you again next semester");
}
