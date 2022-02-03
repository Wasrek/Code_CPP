#include<stdio.h>
void main()
{
   char g;
   printf("Enter your grade :");
   scanf("%c",&g);
   switch(g)
   {
      case 'A':case 'a': printf("Very Good");break;
      case 'B':case 'b': printf("Good");break;
      case 'C':case 'c': printf("Fair");break;
      case 'D':case 'd': printf("Badly");break;
      case 'F':case 'f': printf("Fail");break;
      default: printf("Try again !!");

   }
   printf("\nSee you again next semester");
}
