/*
    TASK:RC_Stream Int
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> del_num[100005];
int fw[1000005];
void update(int a,int b){
    int i;
    for(i=a;i<=1000000;i+=(i&-i))fw[i]+=b;
}
int query(int a){
    int i,sum=0;
    for(i=a;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}
int main(){
    int i,j,k,l,a,b,c,d,mid,r;
    int t,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%d %d",&a,&b);
            if(a==1){
                scanf("%d",&c);
                update(b,1);
                del_num[c].push_back(b);
            }else{
                l=1,r=1000001;
                while(l<r){
                    mid=(l+r)/2;
                    if(query(mid)>=b)r=mid;
                    else
                    l=mid+1;
                }
                if(l==1000001) printf("-1\n");
                    else printf("%d\n",l);
            }
            for(int it:del_num[i]){
                update(it,-1);
            }
        }
        for(i=1;i<=100000;i++){
            del_num[i].clear();
        }
    }
}
