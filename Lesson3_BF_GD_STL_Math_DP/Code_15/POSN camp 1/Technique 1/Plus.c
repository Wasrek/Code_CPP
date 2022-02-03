/*
    TASK:Playbase
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
char a[6000],b[6000],d[6000];
int c[6000];
int main(){
   int lena,lenb,i,j,k,tod=0,ch;
   scanf(" %s %s",a,b);
   if(a[0]=='-' && b[0]=='-'){
    printf("-");
    strcpy(a,&a[1]);
    strcpy(b,&b[1]);
   }
   lena = strlen(a);
   lenb = strlen(b);
   if(a[0] != '-' && b[0] != '-'){
    for(i=lena-1,j=lenb-1,k=0;i>=0 && j>=0;i--,j--,k++){
        c[k] = a[i]-'0' + b[j]-'0' + tod;
        tod = c[k]/10;
        c[k]%= 10;
    }
    for(;i>=0;i--,k++){
        c[k]= a[i]-'0' + tod;
        tod = c[k]/10;
        c[k]%=10;
    }
    for(;j>=0;j--,k++){
        c[k]= b[j]-'0' + tod;
        tod = c[k]/10;
        c[k]%=10;
    }
    if(tod)
        c[k++]=tod;
        for(i=k-1;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");

   }else{
      if(a[0]=='-'){
        strcpy(d,a);strcpy(a,b);strcpy(b,d);
      }
      strcpy(&b[0],&b[1]);
      lena = strlen(a);
      lenb = strlen(b);
      //printf("%s %s\n",a,b);
      if(lena>lenb) ch=1;
      else if(lenb>lena) ch=2;
      else if(lena == lenb){
        if(strcmp(a,b)>0) ch=1;
        else if(strcmp(a,b)<0) ch=2;
        else {printf("0\n"); return 0;}
      }
      if(ch==2){
            printf("-"); strcpy(d,a);strcpy(a,b);strcpy(b,d);
      }
      lena = strlen(a);
   lenb = strlen(b);
      for(i=lena-1,j=lenb-1,k=0;i>=0 && j>=0;i--,j--,k++){
        if(a[i]<b[j]){
        c[k]=(a[i]-'0'+10)-(b[j]-'0');
        a[i-1]--;
      }else
      {
          c[k]=(a[i]-'0')-(b[j]-'0');
      }}
      for(;i>=0;i--,k++){
        if(a[i]-'0'==-1)
            a[i]+=10,a[i-1]--;
      c[k]=a[i]-'0';
      }
      for(i=k-1;i>=0 && c[i]==0;i--);
      for(;i>=0;i--)
        printf("%d",c[i]);
      printf("\n");
   }
return 0;
}
