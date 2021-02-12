//
//  main.cpp
//  关键是看a叠加的次数上限？ 假设a'[aaaa]a''括号里含有b
//  方括号内最多有n/m次，所以是n/m+2
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        string A = a;
        for (int i = 1; i <= n / m + 2; i++) {
            if (A.find(b) != string::npos) return i;
            A += a;
        }
        return -1;
    }
};
