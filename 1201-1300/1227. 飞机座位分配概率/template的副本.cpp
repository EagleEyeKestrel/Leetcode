//
//  main.cpp
//  没做出来。。
//  算dp[n]的时候，关键是当第一个人坐在i的时候，显然2到i-1都不受影响
//  那第i个人坐在哪里，然后如何递推？因为剩下的座位都没有i本应坐的座位，而1号开始还有1号位置可以选择，情况不一样
//  其实，我们可以把i坐在1视作坐在了自己本来的位置，因为这样对之后的i+1到n没有任何影响
//  1一开始坐在1号位置的意义也只是不会对之后的人造成任何影响
//  所以递推公式：dp[n]=1/n(dp[n-1]+dp[n-2]+...+dp[2]+dp[1])
//  然后可以推出 dp[n+1]=dp[n]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};
