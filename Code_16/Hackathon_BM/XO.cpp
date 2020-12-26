/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,st,d,now,cnt=0,gc=0;
    int v1s,v2s,v3s,h1s,h2s,h3s,rds,lds,v1d,v2d,v3d,h1d,h2d,h3d,rdd,ldd;
    v1s=v2s=v3s=h1s=h2s=h3s=rds=lds=v1d=v2d=v3d=h1d=h2d=h3d=rdd=ldd=0;
    st=d=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        cnt++;
        gc++;
        if(cnt==10){
            v1s=v2s=v3s=h1s=h2s=h3s=rds=lds=v1d=v2d=v3d=h1d=h2d=h3d=rdd=ldd=0;
            cnt=1;
            gc=1;
        }
        // printf("r %d\n",cnt);
        if(gc%2){
            if(now==1){
                h1s++;
                v1s++;
                lds++;
                if(h1s!=3 && v1s!=3 && lds!=3){
                    continue;
                }else st++;
            }else if(now==2){
                h1s++;
                v2s++;
                if(h1s!=3 && v2s!=3){
                    continue;
                }else st++;
            }else if(now==3){
                h1s++;
                v3s++;
                rds++;
                if(h1s!=3 && v3s!=3 && rds!=3){
                    continue;
                }else st++;
            }else if(now==4){
                h2s++;
                v1s++;
                if(h2s!=3 && v1s!=3){
                    continue;
                }else st++;
            }else if(now==5){
                h2s++;
                v2s++;
                rds++;
                lds++;
                if(h2s!=3 && v2s!=3 && rds!=3 && lds!=3){
                    continue;
                }else st++;
            }else if(now==6){
                h2s++;
                v3s++;
                if(h2s!=3 && v3s!=3){
                    continue;
                }else st++;
            }else if(now==7){
                h3s++;
                v1s++;
                rds++;
                if(h3s!=3 && v1s!=3 && rds!=3){
                    continue;
                }else st++;
            }else if(now==8){
                h3s++;
                v2s++;
                if(h3s!=3 && v2s!=3){
                    continue;
                }else st++;
            }else if(now==9){
                h3s++;
                v3s++;
                lds++;
                if(h3s!=3 && v3s!=3 && lds!=3){
                    continue;
                }else st++;
            }
        }else{
            if(now==1){
                h1d++;
                v1d++;
                ldd++;
                if(h1d!=3 && v1d!=3 && ldd!=3){
                    continue;
                }else d++;
            }else if(now==2){
                h1d++;
                v2d++;
                if(h1d!=3 && v2d!=3){
                    continue;
                }else d++;
            }else if(now==3){
                h1d++;
                v3d++;
                rdd++;
                if(h1d!=3 && v3d!=3 && rdd!=3){
                    continue;
                }else d++;
            }else if(now==4){
                h2d++;
                v1d++;
                if(h2d!=3 && v1d!=3){
                    continue;
                }else d++;
            }else if(now==5){
                h2d++;
                v2d++;
                rdd++;
                ldd++;
                if(h2d!=3 && v2d!=3 && rdd!=3 && ldd!=3){
                    continue;
                }else d++;
            }else if(now==6){
                h2d++;
                v3d++;
                if(h2d!=3 && v3d!=3){
                    continue;
                }else d++;
            }else if(now==7){
                h3d++;
                v1d++;
                rdd++;
                if(h3d!=3 && v1d!=3 && rdd!=3){
                    continue;
                }else d++;
            }else if(now==8){
                h3d++;
                v2d++;
                if(h3d!=3 && v2d!=3){
                    continue;
                }else d++;
            }else if(now==9){
                h3d++;
                v3d++;
                ldd++;
                if(h3d!=3 && v3d!=3 && ldd!=3){
                    continue;
                }else d++;
            }
        }
        cnt=0;
        // printf("%d %d %d %d %d %d %d %d\n",v1s,v2s,v3s,h1s,h2s,h3s,lds,rds);
        // printf("%d %d %d %d %d %d %d %d\n",v1d,v2d,v3d,h1d,h2d,h3d,ldd,rdd);
        v1s=v2s=v3s=h1s=h2s=h3s=rds=lds=v1d=v2d=v3d=h1d=h2d=h3d=rdd=ldd=0;
        // printf("%d %d %d %d %d %d %d %d\n",v1s,v2s,v3s,h1s,h2s,h3s,lds,rds);
        // printf("%d %d %d %d %d %d %d %d\n",v1d,v2d,v3d,h1d,h2d,h3d,ldd,rdd);
        gc=0;
    }
    // printf("%d %d %d %d %d %d %d %d\n",v1s,v2s,v3s,h1s,h2s,h3s,lds,rds);
    // printf("%d %d %d %d %d %d %d %d\n",v1d,v2d,v3d,h1d,h2d,h3d,ldd,rdd);
    printf("%d\n%d\n",st,d);
    return 0;
}