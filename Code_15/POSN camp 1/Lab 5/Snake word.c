/*
    TASK:Snake word
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[50][50];
char s[250];
int l,ans=0;
int r,c,f,px,py;
void play(int i,int j){
if(a[i][j]!='0'){
   if(f!=l){
   if(i-1>=0 && a[i-1][j]==s[f+1]){a[i][j]='0';f++;play(i-1,j);px=i;py=j;}
   if(j-1>=0 && a[i][j-1]==s[f+1]){a[i][j]='0';f++;play(i,j-1);py=j;py=j;}
   if(i+1<r && a[i+1][j]==s[f+1]){a[i][j]='0';f++;play(i+1,j);px=i;py=j;}
   if(j+1<c && a[i][j+1]==s[f+1]){a[i][j]='0';f++;play(i,j+1);py=j;px=i;}
   }else{
   ans=1;
   printf("\n%d %d",px,py);
   }
   }
}
int main()
{
    int i,j,q,n,f,v;
    scanf(" %d %d",&c,&r);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf(" %c",&a[i][j]);
            a[i][j] = toupper(a[i][j]);
        }
    }
    scanf("%d",&q);
    for(n=0;n<q;n++)
    {
        scanf(" %s",s);
        l=strlen(s);
        for(v=0;v<l;v++)
        {
            s[v]=toupper(s[v]);
        }
        l=l-1;
        for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==s[0]){
                play(i,j);
            }
            f=0;
        }
    }

    if(ans==0)
    {
        printf("No Matching Word");
    }else{printf("yes");}
    f=0;ans=0;
    }

    return 0;
}
/*
3 5
TAEPE
TULAR
STOPW
2
PEATT
HELLOWORLD
*/
