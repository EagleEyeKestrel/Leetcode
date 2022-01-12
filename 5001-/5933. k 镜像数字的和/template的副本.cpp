//
//  main.cpp
//  很无聊的题，我如果每次都从1开始遍历到999999然后排序，会超时
//  所以需要从小到大处理回文数，这样就不超时了
//  或者直接打表，肯定也可以！
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int ispalindrome(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return 0;
            l++, r--;
        }
        return 1;
    }
    int f(long long x, int k) {
        string str;
        while (x) {
            str.push_back(x % k + '0');
            x /= k;
        }
        return ispalindrome(str);
    }

    long long kMirror(int k, int n) {
        vector<long long> nums;
        for (int i = 1; i <= 9; i++) {
            if (f(i, k)) nums.push_back(i);
        }
        for (int bits = 2; bits <= 12; bits++) {
            int K = bits / 2;
            for (int num = pow(10, K - 1); num < pow(10, K); num++) {
                string s = to_string(num);
                string t = s;
                reverse(t.begin(), t.end());
                if (bits % 2) {
                    for (int mid = 0; mid <= 9; mid++) {
                        string m = to_string(mid);
                        long long val = stoll(s + m + t);
                        if (f(val, k)) nums.push_back(val);
                    }
                } else {
                    long long val = stoll(s + t);
                    if (f(val, k)) nums.push_back(val);
                }
                if (nums.size() >= n) break;
            }
            if (nums.size() >= n) break;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += nums[i];
        return ans;
    }
};
