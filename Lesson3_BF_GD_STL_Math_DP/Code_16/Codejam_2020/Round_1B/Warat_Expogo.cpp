#include<bits/stdc++.h>
using namespace std;
int t,i,j,k,n,m,minn,minm,ch,nn,mm,cnt;
int bin[50],bim[50],mx;
char ans[50];
int main(){
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        mx=-1;
        memset(bin,0,sizeof bin);
        memset(bim,0,sizeof bim);
        scanf("%d %d",&n,&m);

        if(n<0) minn=1,n*=-1;
        else minn=0;
        if(m<0) minm=1,m*=-1;
        else minm=0;
        if((n%2==1&&m%2==1)||(n%2==0&&m%2==0)){
            printf("Case #%d: IMPOSSIBLE\n",k);
            continue;
        }
        nn=n;
        mm=m;
        cnt=0;
        while(nn>0){
            bin[cnt++]=nn%2;
            nn/=2;
        }
        mx=max(mx,cnt);
        cnt=0;
        while(mm>0){
            bim[cnt++]=mm%2;
            mm/=2;
        }
        mx=max(mx,cnt);
        printf("Case #%d: ",k);
        for(i=0;i<=mx;i++){
            if(bin[i]==0&&bim[i]==1){
                if(minm==0) ans[i]='N';
                else ans[i]='S';
            }else if(bin[i]==1&&bim[i]==0){
                if(minn==0) ans[i]='E';
                else ans[i]='W';
            }else if(bin[i]==0&&bim[i]==0){
                if(ans[i-1]=='N'||ans[i-1]=='S'){
                   if(ans[i-1]=='N') ans[i-1]='S',ans[i]='N';
                   else ans[i-1]='N',ans[i]='S';
                }else{
                   if(ans[i-1]=='E') ans[i-1]='W',ans[i]='E';
                   else ans[i-1]='E',ans[i]='W';
                }
            }else {
                if(ans[i-1]=='N'||ans[i-1]=='S'){
                    if(ans[i-1]=='N') ans[i-1]='S';
                    else ans[i-1]='N';
                    if(minn==0) ans[i]='E';
                    else ans[i]='W';
                    for(j=i+1;j<=mx+1;j++){
                        if(bim[j]==0) {
                            bim[j]=1;
                            break;
                        }else bim[j]=0;

                    }
                }else{
                    if(ans[i-1]=='E') ans[i-1]='W';
                    else ans[i-1]='E';
                    if(minm==0) ans[i]='N';
                    else ans[i]='S';
                    for(j=i+1;j<=mx+1;j++){
                        if(bin[j]==0) {
                            bin[j]=1;
                            break;
                        }else bin[j]=0;

                    }
                }
            }
        }
        if(ans[mx]=='N'&&ans[mx-1]=='S'){
            for(i=0;i<=mx-2;i++) printf("%c",ans[i]);
            printf("N");
        }else if(ans[mx]=='S'&&ans[mx-1]=='N'){
            for(i=0;i<=mx-2;i++) printf("%c",ans[i]);
            printf("S");
        }else if(ans[mx]=='E'&&ans[mx-1]=='W'){
            for(i=0;i<=mx-2;i++) printf("%c",ans[i]);
            printf("E");
        }else if(ans[mx]=='W'&&ans[mx-1]=='E'){
            for(i=0;i<=mx-2;i++) printf("%c",ans[i]);
            printf("W");
        }else{
            for(i=0;i<=mx;i++) printf("%c",ans[i]);
        }

        printf("\n");
    }
return 0;
}