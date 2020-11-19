#include<stdio.h>
void check(int pass)
{
   if(pass==48)
   {
   printf("You are BNK48 Ota");
   }else{printf("WHY SO SERIOUS");}
}
int main(){
    int p;
   printf("Enter your BNK password :");
   scanf("%d",&p);
   check(p);
}
