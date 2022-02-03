/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char str[1010];
struct A{
    int type;
    long long n;
    int d,m,y,cnt;
    bool operator <(const A & o) const{
        if(y!=o.y) return y<o.y;
        if(m!=o.m) return m<o.m;
        if(d!=o.d) return d<o.d;
        return cnt<o.cnt;
    }
};
vector< A > v;
void prinum(long long val){
    long long rr=val%100;
    val-=rr;
    val/=100;
    // printf("%lld\n",val);
    // printf("%lld\n",(long long)log10((double)val));
    if(val>0){
    long long len=(long long)log10((double)val)+1;
    long long fr=len%3;
    // printf("%lld %lld\n",len,fr);
    if(fr){
        long long fn=val/(long long)(pow(10.00,(double)(len-fr)));
        printf("%lld",fn);
        val-=(fn*(long long)(pow(10.00,(double)(len-fr))));
    }
    len-=fr;
    long long ch=0;
    if(fr==0) ch=1;
    while(len>0){
        long long fn=val/(long long)(pow(10.00,(double)(len-3)));
        val-=(fn*(long long)(pow(10.00,(double)(len-3))));
        len-=3;
        if(ch){printf("%03lld",fn);ch=0;}
        else{printf(",%03lld",fn);}
    }
    }else{
        printf("0");
    }
    printf(".%02lld",rr);
    return ;
}
int main()
{
    double n;
    long long sum=0,now,r;
    int cnt=0;
    char type;
    int d,m,y;
    char pass;
    printf("Title: ");
    gets(str);
    printf("\n");
    while(1){
        printf("type: ");
        scanf(" %c",&type);
        if(type=='0'){
            break;
        }
        // printf("%d\n",type);
        if(type!='1' && type!='2'){printf("skip\n");continue;}
        printf("amout: ");
        scanf("%lf",&n);
        printf("day: ");
        scanf("%d",&d);
        printf("month: ");
        scanf("%d",&m);
        printf("year: ");
        scanf("%d",&y);
        printf("correct? ");
        scanf(" %c",&pass);
        if(pass!='y'){printf("skip\n");continue;}
        now=(long long)(n*100.0);
        // printf("%lld\n",now);
        printf("\n");
        if(type=='1')sum+=now;
        else sum-=now;
        cnt++;
        v.push_back({type,now,d,m,y,cnt});
    }
    printf("%s\n",str);
    printf("OVERALL %d receipts ",cnt);
    // printf("here %lld\n",sum);
    prinum(sum);
    printf(" total\n");
    // printf("%d\n",v.size());
    sort(v.begin(),v.end());
    // printf("%d\n",v.size());
    for(int i=0;i<v.size();i++){
        A x=v[i];
        if(x.type=='1') printf("+ ");
        else printf("- ");
        printf("%d %02d/%02d/%d ",x.cnt,x.d,x.m,x.y);
        prinum(x.n);
        printf("\n");
    }
    return 0;
}