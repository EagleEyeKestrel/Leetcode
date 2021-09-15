//
//  main.cpp
//  并不需要dp，直接看下性质就能解决
//  如果各个数字的和%3==0 直接排序输出即可
//  如果sum%3==1，那么肯定是要么删掉一个1/4/7，要么删掉两个2/5/8。其他得到的结果肯定更差，而且肯定优先删一个数字，因为数字位数越多肯定越大
//  sum%3==2也同样处理。特判一下sum==0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string f(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
        string res;
        for (int x: v1) res.push_back(x + '0');
        for (int x: v2) res.push_back(x + '0');
        for (int x: v3) res.push_back(x + '0');
        sort(res.begin(), res.end(), greater<char>());
        return res;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0, n = digits.size();
        vector<int> zero, one, two;
        for (int x: digits) {
            if (x % 3 == 0) zero.push_back(x);
            if (x % 3 == 1) one.push_back(x);
            if (x % 3 == 2) two.push_back(x);
            sum += x;
        }
        if (sum == 0) return "0";
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        string res;
        if (sum % 3 == 1) {
            if (one.size()) {
                one.erase(one.begin());
            } else if (two.size() > 1) {
                two.erase(two.begin(), two.begin() + 2);
            } else {
                return "";
            }
        }
        if (sum % 3 == 2) {
            if (two.size()) {
                two.erase(two.begin());
            } else if (one.size() > 1) {
                one.erase(one.begin(), one.begin() + 2);
            } else {
                return "";
            }
        }
        return f(zero, one, two);
    }
};
