/*
    TASK:Playbase
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[100],b[100],c[100];
int main() {
   int x,lena,lenb,numa=0,numb=0,ans,i;
   scanf("%d %s %s",&x,a,b);
   lena = strlen(a);
   for(i=0;i<lena;i++){
      numa*=x;
      if(isalpha(a[i]))
         numa += (a[i]-'A'+10);
         else
         numa += (a[i]-'0');
   }
   lenb=strlen(b);
   for(i=0;i<lenb;i++){
   numb *= x;
   if(isalpha(b[i]))
         numb += (b[i]-'A'+10);
         else
         numb += (b[i]-'0');
   }
   ans=numa+numb;
   printf("%d\n",ans);
   for(i=0;ans>0;i++)
   {
   c[i]= ans%x;
   ans/=x;
   }
   for(i--;i>=0;i--){
     if(c[i]>=10 && c[i]<=15)
     printf("%c",c[i]-10+'A');
     else
     printf("%c",c[i]+'0');
   }
   printf("\n");
   return 0;
}
