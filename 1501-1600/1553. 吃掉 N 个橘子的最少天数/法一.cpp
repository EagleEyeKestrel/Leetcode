//
//  main.cpp
//  比赛时的解法，现在看看还挺不错的
//  先预处理出100000以下的情形，对>100000以上的情形直接递归处理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int dp[],int n,int depth){
        if(n<100000) return dp[n];
        if(depth>20) return INT_MAX-100;
        int res=1000;
        if(n%3==0) res=min(res,f(dp,n/3,depth+1)+1);
        if(n%2==0) res=min(res,f(dp,n/2,depth+1)+1);
        res=min(res,f(dp,n-1,depth+1)+1);
        return res;
    }
    int minDays(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 2;
        int dp[100000];
        dp[1]=1;
        dp[2]=2;
        dp[3]=2;
        for(int i=4;i<min(100000,n+1);i++){
            dp[i]=dp[i-1]+1;
            if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1);
            if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1);
        }
        if(n<100000) return dp[n];
        int res=f(dp,n,1);
        return res;
    }
};
