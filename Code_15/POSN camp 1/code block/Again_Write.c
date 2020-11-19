#include<stdio.h>
char a[30],b[41000];
int main()
{
   int sa,sb,q,k,j,i;
   scanf("%d",&q);
   while(q--)
   {
    int ch=1;
   scanf(" %s %s",&a,&b);
   sa=strlen(a);
   sb=strlen(b);
   if(sb%sa!=0)
   {
      printf("No");
      continue;
   }else if(sb%sa==0)
   {
      k=sb/sa;
      for(j=0;j<sb;j+=sa){
        if(strncmp(a,&b[j],sa)){
           ch=0;
           break;
        }
      }
   }
   if(ch)
    printf("Yes\n");
   else
    printf("No\n");
}
}
