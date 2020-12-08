//
//  main.cpp
//  看到1年前是用dfs做的。这里没必要dfs
//  反正固定前两项是int范围，那不超过10位，所以穷举前两项，然后后面的字符串就都是确定的了
//  复杂度O(100n)。挺多边界条件要注意的。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    long long f(string &s, int start, int end) {
        long long res = 0;
        for(int i = start; i <= end; i++) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }
    vector<int> splitIntoFibonacci(string S) {
        int n = S.size();
        for(int i = 0; i <= 9; i++) {
            if(i && S[0] == '0') continue;
            for(int j = i + 1; j <= i + 10; j++) {
                if(j >= n) break;
                if(j > i + 1 && S[i + 1] == '0') break;
                long long f1 = f(S, 0, i);
                long long f2 = f(S, i + 1, j);
                if(f1 > INT_MAX || f2 > INT_MAX) continue;
                vector<int> res = {(int)f1, (int)f2};
                int last = j;
                while(last < n) {
                    long long f3 = f1 + f2;
                    if(f3 > INT_MAX) break;
                    string s3 = to_string(f3);
                    int l3 = s3.size();
                    if(last + l3 >= n || S.substr(last + 1, l3) != s3) break;
                    res.push_back((int)f3);
                    f1 = f2;
                    f2 = f3;
                    last += l3;
                }
                if(last == n - 1 && res.size() > 2) return res;
            }
        }
        return {};
    }
};
