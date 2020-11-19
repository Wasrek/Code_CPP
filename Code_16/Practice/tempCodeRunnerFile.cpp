
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",s[i]);
    // }
    // printf("\n");
    int sum=0;
    for(int i=1;i<=n;i++){
        if(s[i]>0) dp[i]=dp[s[i]-1]+1;
        sum+=dp[i];
    }
    printf("%d\n",sum);
    return 0;
}