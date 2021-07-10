 for(int i=n;i>=1;i--){
        dp[i]+=dp[i+2];
    }