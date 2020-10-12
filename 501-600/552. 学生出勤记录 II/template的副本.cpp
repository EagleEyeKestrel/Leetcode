//
//  main.cpp
//  dp就行了，dp[i][j][k]表示前i天，j=0表示没有过A，k表示最后有连续k个L
//  当然很容易看出来，空间是可以做到O(1)的，就是写出来有点难看懂，可以看注释
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        long dp[n + 1][2][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % mod;
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
        }
        return (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % mod;
    }
};

/*
 class Solution {
 public:
     int checkRecord(int n) {
         long all=0,axl=0,axx=1,noall=0,noaxl=1,noaxx=1,mod=1000000007;
         for(int i=1;i<n;i++){
             long a=all,b=axl,c=axx,d=noall,e=noaxl,f=noaxx;
             all=b;
             axl=c;
             axx=(a+b+c+d+e+f)%mod;
             noall=e;
             noaxl=f;
             noaxx=(d+e+f)%mod;
         }
         return (all+axl+axx+noall+noaxl+noaxx)%mod;
     }
 };
 */
