/*
    TASK:RT_Set Menu
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[25],sm[6],ch[25],cou[25],ww[25],w[25];
int main(){
    int k,i,n,all=0,p,check,ma=0,s;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&s);
    for(i=1;i<=4;i++){
        scanf("%d",&sm[i]);
        ch[sm[i]]=1;
    }
    scanf("%d",&n);
    check=1;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        all+=a[w[i]];
        if(ch[w[i]])check=0,cou[w[i]]++,ma=max(ma,cou[w[i]]);
        if(ww[w[i]]>0){
            ww[w[i]]++;
            w[i]=-1;
        }else ww[w[i]]++;
    }
//    for(i=1;i<=n;i++){
//        if(w[i]==-1)continue;
//        printf("%d\n",ww[w[i]]);
//    }
    if(check){
        printf("%d\n",all);
        return 0;
    }
    //printf("%d\n",all);
    int mi=all,j;
    for(i=1;i<=ma;i++){
        p=all+(s*i);
        //printf("\n - %d -\n",p);
        for(j=1;j<=n;j++){
            if(w[j]==-1)continue;
            //printf("- %d\n",w[j]);
            if(ch[w[j]]){
                //printf("- y - %d %d\n",w[j],ww[w[j]]);
                if(ww[w[j]]>=i){
                    p-=(a[w[j]]*i);
                    //printf(" - 1 -%d %d %d\n",p,a[w[j]],i);
                }else{
                    p-=(a[w[j]]*ww[w[j]]);
                    //printf(" - 2 -%d\n",p);
                }
            }
        }
        mi=min(mi,p);
    }
    printf("%d\n",mi);
    return 0;
}
/*
6 12 5 7 8 9 3
14
4 3 1 2
5
1 2 1 6 6
*/
