/*
    TASK:FC_Drawer
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int p[300010],h[300010];
int fin(int i){
    if(p[i]==i)return i;
    else return p[i]=fin(p[i]);
}
int main(){
    int n,l,a,b,i,cou;
    scanf("%d %d",&n,&l);
    for(i=1;i<=l;i++)p[i]=i,h[i]=1;
    while(n--){
        scanf("%d %d",&a,&b);
        if(fin(a)!=fin(b)){
            //printf("\n%d %d\n",fin(a),fin(b));
            //printf("%d %d\n",h[fin(a)],h[fin(b)]);
            h[fin(b)]+=h[fin(a)];
            h[fin(a)] = 0;
            //h[fin(a)]=h[fin(b)];
            //printf("%d %d\n",h[fin(a)],h[fin(b)]);
            p[fin(a)]=fin(b);
        }
        //h[fin(b)]--;
//        for(i=1;i<=l;i++){
//            printf("%d ",h[i]);
//        }printf("\n");
//        for(i=1;i<=l;i++){
//            printf("%d ",fin(i));
//        }printf("\n");
//        printf("\n");
        if(h[fin(b)]>0){
                printf("Yes\n");
                h[fin(b)]--;
        }
        else printf("No\n");
        //printf("%d\n",h[fin(b)]);
    }
}
/*
9 10
1 2
3 4
5 6
7 8
9 10
2 3
1 5
8 2
7 9
*/
