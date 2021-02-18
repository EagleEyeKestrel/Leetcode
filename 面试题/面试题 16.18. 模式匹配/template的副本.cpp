//
//  main.cpp
//  如果只有一种字母，直接检查
//  如果有两种字母，穷举a的长度，可以推断出b的长度，然后看连起来是不是value
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int a = 0, b = 0, n = value.size();
        for (char c: pattern) {
            if (c == 'a') a++;
            else b++;
        }
        if (!a || !b) {
            int cnt = a + b;
            if (n % cnt) return false;
            string s = value.substr(0, n / cnt);
            for (int i = n / cnt; i < n; i += n / cnt) {
                if (value.substr(i, n / cnt) != s) return false;
            }
            return true;
        }
        for (int al = 0; al * a <= n; al++) {
            if ((n - al * a) % b) continue;
            int bl = (n - al * a) / b, now = 0;
            string sa = "", sb = "", res;
            for (int i = 0; i < pattern.size(); i++) {
                char c = pattern[i];
                if (c == 'a' && sa.empty()) sa = value.substr(now, al);
                if (c == 'b' && sb.empty()) sb = value.substr(now, bl);
                if (c == 'a') res += sa, now += al;
                else res += sb, now += bl;
            }
            if (res == value && sa != sb) return true;
        }
        return false;
    }
};
