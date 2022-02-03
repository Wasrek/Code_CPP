/*
    TASK:FC_Triangle Word
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[1000100][26];
char a[1000100];
int main()
{
    long long n,len,q,i,j,num,now,ans;
    scanf("%lld",&n);
    scanf(" %s",a+1);
    len=strlen(a+1);
    for(i=1;i<=len;i++){
        qs[i][a[i]-'A']=1;
        for(j=0;j<26;j++){
            qs[i][j]+=qs[i-1][j];
            //printf("%d ",qs[i][j]);
        }
        //printf("\n");
    }
    char check;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %c",&num,&check);
        long long ch = (check-'A');
        long long a=num;
        long long b=num-1;
        if(b%2) a/=2;
        else    b/=2;
        //printf("  %d\n",check);
        now=(((((a)%len)*((b)%len)))%len)+1;
//        printf("%lld\n",now);
        if(num+now-1>len){
            long long sum1=qs[len][ch]-qs[now-1][ch];
            num-=len-now+1;
            long long cc=num/len;
            long long sum2=cc*qs[len][ch];
            num-=cc*len;
            long long sum3=qs[num][ch];
//            ans=qs[len][ch]-qs[now-1][ch]  +qs[((now+num-1)%len)+1][ch]  +(qs[len][ch]*(num-1-(((now+num-1)%len)+1)-(len+1-now))/len);
            printf("%lld\n",sum1+sum2+sum3);
        }
        else{
            ans=qs[now+num-1][ch]-qs[now-1][ch];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
6
PEATTIGO
3
1 P
5 T
3 E

100
P
3
100 P

3
ABC
3
3 A
3 B
3 C
*/
