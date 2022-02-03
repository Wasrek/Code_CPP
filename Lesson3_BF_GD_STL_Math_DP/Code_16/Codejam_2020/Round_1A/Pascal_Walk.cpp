/*
    TASK:Pascal Walk
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long pc[510][510],qs[510][510];
int main()
{
    pc[1][1]=1;
    qs[1][1]=1;
    for(int i=2;i<=500;i++){
        for(int j=1;j<=500;j++){
            pc[i][j]=pc[i-1][j-1]+pc[i-1][j];
            for(int k=1;k<=i;k++){
                qs[i][k]=qs[i][k-1]+pc[i][k];
            }
        }
    }
    // for(int i=1;i<=10;i++){
    //     for(int j=1;j<=10;j++){
    //         printf("%lld ",qs[i][j]);
    //     }
    //     printf("\n");
    // }
    int Q,n,row,cnt,now,jj,top,la,cn;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d",&n);
        cnt=0;
        printf("Case #%d:\n",q);
        now=0;
        row=0;
        while(1){
            if(now+qs[row+1][row+1]<=n){
                now+=qs[row+1][row+1];
                row++;
                cnt+=row;
            }else{
                break;
            }
        }
        // printf("%d %d\n",cnt,row);
        if((cnt+(n-now))<=500){
            for(int i=1;i<=row;i++){
                // printf("%d\n",i);
                if(i%2){
                    for(int j=i;j>=1;j--){
                        printf("%d %d\n",i,j);
                    }
                }else{
                    for(int j=1;j<=i;j++){
                        printf("%d %d\n",i,j);
                    }
                }
            }
            now=n-now;
            jj=row+1;
            row++;
            while(now){
                if((jj+1)%2){
                    printf("%d 1\n",row);
                }else{
                    printf("%d %d\n",row,row);
                }
                row++;
                now--;
            }
            continue;
        }else{
            top=1;
            while(1){
                row++;
                cnt+=qs[row][row];
                top++;
                cnt-=(qs[top][top]-1);
                if(cnt>n) break;
            }
            la=row;
            row--;
            cn=cnt;
            for(int i=1;i<=top;i++){
                if(top%2){
                    printf("%d 1\n",i,1);
                }else{
                    printf("%d %d\n",i,i);
                }
            }
            for(int i=top+1;i<=row;i++){
                // printf("%d\n",i);
                if(i%2){
                    for(int j=i;j>=1;j--){
                        printf("%d %d\n",i,j);
                    }
                }else{
                    for(int j=1;j<=i;j++){
                        printf("%d %d\n",i,j);
                    }
                }
            }
            now=n-cnt;
            jj=row+1;
            row++;
            while(now){
                if((jj+1)%2){
                    printf("%d 1\n",row);
                }else{
                    printf("%d %d\n",row,row);
                }
                row++;
                now--;
            }
    }
    }
    return 0;
}
/*
while(cn>n){
                cn-=pc[row][la];
                la--;
            }
            if(cn!=n){

            }else{
            if((row-top)%2){
            for(int i=1;i<=top;i++){
                printf("%d 1",i);
            }
            for(int j=top+1;j<row;j++){
                if((j-top)%2){
                    for(int i=1;i<=j;i++){
                        printf("%d %d\n",j,i);
                    }
                }else{
                    for(int i=j;i>=1;i--){
                        printf("%d %d\n",j,i);
                    }
                }
            }
            }else{
                for(int i=1;i<=top;i++){
                    printf("%d %d",i,i);
                }
                 for(int j=top+1;j<row;j++){
                    if(((j-top)%2)==0){
                    for(int i=1;i<=j;i++){
                        printf("%d %d\n",j,i);
                    }
                }else{
                    for(int i=j;i>=1;i--){
                        printf("%d %d\n",j,i);
                    }
                }
            }
            }
            for(int i=1;i<=la;i++){
                printf("%d %d\n",row,la);
            }
        }
*/