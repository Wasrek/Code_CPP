/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int ran(int l, int r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
unordered_map<int,int> mp;
void gen_zigzag(int n,int k){
    printf("%d\n",n);
    int lp=k,ch=0,now;
    while(lp--){
        now=ran(1,n-1);
        while(mp[now]){
            now++;
            now=max(1,(now%5001));
        }
        mp[now]=(lp%2)+1;
        if(!ch) ch=1,mp[now+1]=((lp+1)%2)+1;
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            if(mp[j] && i==mp[j]){
                printf("#");
            }else printf(".");
        }
        printf("\n");
    }
    mp.clear();
}
void gen_block(int n,int k){
    printf("%d\n",n);
    int lp=k-1,ch=0,now;
    while(lp--){
        now=ran(1,n);
        mp[now]=(lp%2)+1;
    }
    now=ran(1,n);
    mp[now]=3;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            if((mp[j] && i==mp[j])|| mp[j]==3){
                printf("#");
            }else printf(".");
        }
        printf("\n");
    }
    mp.clear();
}
void gen_1_3(int n,int ts){
    if(ts==1){
        for(int q=1;q<=n;q++){
            printf("%d\n",q);
            for(int i=1;i<=2;i++){
                for(int j=1;j<=q;j++){
                    printf(".");
                }
                printf("\n");
            }
        }
    }else{
        for(int q=n;q>=1;q--){
            printf("%d\n",q);
            for(int i=1;i<=2;i++){
                for(int j=1;j<=q;j++){
                    printf(".");
                }
                printf("\n");
            }
        }
    }
}
void gen(int n,int k){
    printf("%d\n",n);
    int lp=k,now;
    while(lp--){
        now=ran(1,n);
        mp[now]=(lp%2)+1;
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            if(mp[j] && i==mp[j] && !(i==2 && (mp[j-1]==1 || mp[j+1]==1))){
                printf("#");
            }else printf(".");
        }
        printf("\n");
    }
    mp.clear();
}
int main(int argc,char* argv[])
{
    // srand(time(0));
    int Q,N,ts,cnt=0;
    Q = atoi(argv[++cnt]);
	N = atoi(argv[++cnt]);
    ts = atoi(argv[++cnt]);
    // scanf("%d %d %d",&N,&Q,&ts);
    printf("%d\n",Q);
    if(ts<=2){
        gen_1_3(N,ts);
        return 0;
    }
    int rd=N/10;
    gen_zigzag(N,rd);
    cnt++;
    gen_zigzag(N,rd);
    cnt++;
    gen_block(N,rd);
    cnt++;
    gen_block(N,rd);
    cnt++;
    int st=1;
    while(cnt<Q){
        for(int q=st;q<=N && cnt<Q;q+=ts){
            // printf("%d %d %d %d %d\n",q,cnt,Q,q/3,q/50);
            if(q<=500)gen(q,ran(q/50,q/7));
            else gen(q,ran(q/100,q/20));
            cnt++;
        }
        st+=(N/10);
        if(st>N) st=max(1,(N/10));
    }
    return 0;
}