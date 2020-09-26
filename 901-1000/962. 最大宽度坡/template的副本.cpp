//
//  main.cpp
//  O(n)的做法其实还挺难想的，要不是做过我肯定不会
//  先从最开始的元素做一个递减栈。最大宽度坡的i一定在栈中。
//  因为对于栈相邻两层之间的元素，它如果作为i，还不如两层里面下面的元素作为i
//  然后从右向左穷举j，保证栈里每个元素都是被最右侧的j弹出
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int n = A.size(), res = 0;
        for(int i = 0; i < A.size(); i++) {
            if(s.empty() || A[i] < A[s.top()]) {
                s.push(i);
            }
        }
        for(int i = n - 1; i >= res; i--) {
            while(!s.empty() && A[s.top()] <= A[i]) {
                res = max(res, i - s.top());
                s.pop();
            }
        }
        return res;
    }
};
