/*
    TASK:RT_Str Sequence
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
map<string,int> mp;
int main(){
    int n,i,len,r,l,j,now,ma=0,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %s",a);
        now=0;
        len=strlen(a);
        l=0;r=len-1;j=0;
        while(a[r]==a[l] && l<len && r>=0){
            if(a[l]!=a[0]){l++,b[j++]=a[r];r--;continue;}
            b[j++]=a[r];
            //printf("%d %d\n",l,r);
//            for(k=1;k<=j;k++)printf("%c",b[k]);
//            printf("\n");
//            printf("-%s",b+1);
            //printf("%s %d %d\n\n",b,mp[b],j);
            now+=mp[b];
            l++;r--;
        }
        ma=max(ma,now+1);
        mp[a]++;
        for(k=0;k<len;k++){
            b[k]=0;
        }
        }
    printf("%d\n",ma);
}
/*
6
A
A
ABA
BBB
ABABA
AAAAAB
*/
