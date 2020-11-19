#include<stdio.h>
int main()
{
   int a,x;
   scanf(" %d",&a);
   int n[a],m[a],p[a],s[a];
   for(x=0;x<a;x++)
   {
       scanf(" %d %d",&n[x],&m[x]);
       p[x]=(2*(n[x]+m[x]));
       s[x]=(n[x]*m[x]);
   }
   for(x=0;x<a;x++)
   {
       printf("%d %d\n",p[x],s[x]);
   }
}
