/*
    TASK:RT_Telephone
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[1010];
int mark[1000010],ma[1010],le[1010];
char a[1000][1000010];
int main(){
    int n,i,len,j,now;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %s",&a[i][1]);
        len=strlen(&a[i][1]);
        le[i]=len;
        if(len>1000)continue;
        ma[i]=1;
        for(j=1;j<=len;j++){
            //printf("%c",a[i][j]);
            a[i][j]=tolower(a[i][j]);
            if(a[i][j]=='z' || a[i][j]=='w' || a[i][j]=='y')a[i][j]='9';
            else
                if(a[i][j]=='s')a[i][j]='7';
            else
                if(a[i][j]=='v')a[i][j]='8';
            else
            a[i][j]=((int)a[i][j]+2)/3+17;
            //printf("%c",a[i][j]);
        }
        //printf("\n");
    }
    int cou=0,ch=0;
    scanf(" %s",&s[1]);
    len=strlen(&s[1]);
    for(i=1;i<=len;i++){
        if(s[i]=='1'){
            printf("0\n");
            return 0;
        }
    }
    for(i=1;i<=n;i++){
        if(!ma[i])continue;
        if(len!=le[i])continue;
        ch=1;
        for(j=1;j<=len;j++){
            if(s[j]!=a[i][j]){ch=0;break;}
        }
        if(ch){cou++;}//printf("%d\n",i);}
    }
    printf("%d\n",cou);
    return 0;
}
/*
10
jk
jt
ju
jv
kv
vk
eo
rit
fick
jt
58
*/
