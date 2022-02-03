/*
    TASK:COI (FC_COI Secret Code)
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
char str[N],TMP[N],ans[N];
int kmp[N],sta[N];
int main(){
    int q,n,i,j,lena,lenb;
    scanf("%d",&q);
    while(q--){
        memset(kmp,0,sizeof kmp);
        scanf(" %s %s",str+1,TMP+1);
        lena=strlen(str+1);
        lenb=strlen(TMP+1);
        j=0;
        for(i=2;i<=lenb;i++){
            while(j!=0 && TMP[j+1]!=TMP[i])j=kmp[j];
            if(TMP[j+1]==TMP[i])j++;
            kmp[i]=j;
        }
        int top=0;
        j=0;
        for(i=1;i<=lena;i++){
            while(j!=0 && TMP[j+1]!=str[i])j=kmp[j];
            if(TMP[j+1]==str[i])j++;
            if(j==lenb){//complete
                top-=lenb-1;
                j=sta[top];
            }else{
                sta[++top]=j;
                ans[top]=str[i];
            }
        }
        if(top==0)printf("No COI Secret Code\n");
        else {
            ans[top+1]=0;
            printf("%s\n",ans+1);
        }
    }
    return 0;
}
