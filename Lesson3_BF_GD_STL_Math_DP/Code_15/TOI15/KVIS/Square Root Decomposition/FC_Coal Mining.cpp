/*
    TASK:FC_Coal Mining
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int MA[1005],val[1000007];
int sq = 1000,n;
int block(int i){
    return i/sq+1;//+1 ให้เริ่มที่1  ไม่ต้องบวกก็ได้ แค่อ่านง่ายกว่่า
}
int leftmost(int i){
    return (i-1)*sq;
}
int rightmost(int i){
    return (i-1)*sq+sq-1;
}
int getleft(int pos,int v){
    int i,j;
    for(i=pos;i>=leftmost(block(pos));i--){
        if(v<val[i])return pos-i;
    }
    for(i=block(pos)-1;i>0;i--){
        if(MA[i]<=v)continue;
        for(j=rightmost(i);v>=val[j];j--);
        return pos-j;
    }
    return 1<<30;
}
int getright(int pos,int v){
    int i,j;
    for(i=pos;i<=rightmost(block(pos));i++){
        if(v<val[i])return i-pos;
    }
    for(i=block(pos)+1;i<=block(n);i++){
        if(MA[i]<=v)continue;
        for(j=leftmost(i);val[j]<=v;j++);
        return j-pos;
    }
    return 1<<30;
}
int main(){
    int m,a,b;
    scanf(" %d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        int ans = min(n,min(getleft(a,b),getright(a,b)));
        printf("%d\n",ans);
        //Upddate
        MA[block(a)]=max(MA[block(a)],b);
        val[a]=b;
    }
    return 0;
}
