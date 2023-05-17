/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
char a[2000010];
vector< char > now;
vector< vector< char > > nm;
int main()
{
    int n,q,opr;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %s",a);
        for(int j=0;j<strlen(a);j++){
            now.push_back(a[j]);
        }
        nm.push_back(now);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&opr);
        if(opr==1){

        }else{

        }
    }
    return 0;
}

#define md 1000010
char a[md],b[md];
int pi[md];
int main(){
    int lena,lenb,i,j=0,cou=0;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    for(i=2;i<=lenb;i++){
        while(j>0 && b[j+1]!=b[i])j=pi[j];
        if(b[j+1]==b[i])j++;
        pi[i]=j;
    }
    for(i=1,j=0;i<=lena;i++){
        while(j>0 && b[j+1]!=a[i])j=pi[j];
        if(b[j+1]==a[i])j++;
        if(j==lenb){
            cou++;j=0;
        }
    }
    printf("%d\n",cou);
    return 0;
}
