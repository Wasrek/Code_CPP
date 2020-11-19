
            if(dp[x]>1e9) ch=1;
            dp[x]%=1000000000;
        }
    }
    if(ch) printf("%09d\n",dp[1]);
    else printf("%d\n",dp[1]);
    return 0;
}