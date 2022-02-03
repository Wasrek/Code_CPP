             ans[i]=(((ans[i-2]+dis[i][i-2])%n)+n)%n;
                }else{
                    ans[i]=(ans[i-2]-dis[i][i-2]+n)%n;
                }