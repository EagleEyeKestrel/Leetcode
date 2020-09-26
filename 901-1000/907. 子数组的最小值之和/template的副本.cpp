//
//  main.cpp
//  以前觉得很难的题，现在到底不一样了。。
//  遍历i，每次处理A[i]结尾的子数组
//  用单调栈表示i左边元素的最小值情况。now维护当前栈内元素的累积和(最小值*作为最小值的次数)求和
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    struct node {
        int val, cnt;
    };
    int sumSubarrayMins(vector<int>& A) {
        long long res = 0, n = A.size(), mod =1e9 + 7, now = 0;
        stack<node> s;
        for(int i = 0; i < n; i++) {
            node tmp;
            tmp.val = i;
            tmp.cnt = 1;
            now += A[i];
            while(!s.empty() && A[s.top().val] >= A[i]) {
                now -= (A[s.top().val] - A[i]) * s.top().cnt;
                tmp.cnt += s.top().cnt;
                s.pop();
            }
            s.push(tmp);
            res = (res + now) % mod;
        }
        return res % mod;
    }
};
