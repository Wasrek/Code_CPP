#include<stdio.h>
int gcd(int a,int b){
   if(a%b==0) return b;
   else return gcd(b,a%b);
}
int main(){
   int a,b,c,n,i,j;
   scanf("%d %d %d",&a,&b,&c);
   int g= gcd(a,b);
   if(c%g==0)printf("Yes");
   else
   printf("No");
}
