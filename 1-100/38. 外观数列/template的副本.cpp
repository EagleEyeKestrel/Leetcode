//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string s[31];
    string countAndSay(int n) {
        s[1] = "1";
        for (int i = 2; i <= n; i++) {
            string last = s[i - 1], res;
            vector<int> cnt, num;
            int tmp;
            for (int j = 0; j < last.size(); j++) {
                if (!j || last[j] != last[j - 1]) tmp = 1;
                else tmp++;
                if (j == last.size() - 1 || last[j] != last[j + 1]) {
                    cnt.push_back(tmp);
                    num.push_back(last[j]);
                }
            }
            for (int j = 0; j < cnt.size(); j++) {
                res += to_string(cnt[j]);
                res.push_back(num[j]);
            }
            s[i] = res;
        }
        return s[n];
    }
};
