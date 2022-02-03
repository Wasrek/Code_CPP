
            }
            if(s[i]=='J'){
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]+x);
                dp[i][1]=2e9;
            }
            if(s[i]=='?'){
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]+x);
                dp[i][1]=min(dp[i-1][1],dp[i-1][2]+y);
            }
            // printf("%d %d\n",dp[i][1],dp[i][2]);
        }
        printf("Case #%d: %d\n",Q,min(dp[len][1],dp[len][2]));
    }
    return 0;
}