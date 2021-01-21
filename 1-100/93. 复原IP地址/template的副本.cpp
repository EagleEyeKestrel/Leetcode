//
//  main.cpp
//  dfs，pos表示从s的什么位置开始，k表示还剩下几段？tmp是当前字符串
//  每次穷举，是取接下来的1/2/3位。
//  有点难的是判断有无前导0？我这里直接用了转int再转str，看是否一样，直接用库函数了，舒服
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> res;
    int n;
    void dfs(string& s, int pos, int k, string& tmp) {
        if (!k) {
            if(pos == n) res.push_back(tmp);
            return;
        }
        for (int l = 1; l <= 3; l++) {
            if (n - pos < l) break;
            string str = s.substr(pos, l);
            int num = stoi(str);
            if (num > 255 || to_string(num) != str) break;
            if (k < 4) tmp.push_back('.');
            tmp += str;
            dfs(s, pos + l, k - 1, tmp);
            for (int ll = 0; ll < l; ll++) tmp.pop_back();
            if (k < 4) tmp.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        string tmp = "";
        dfs(s, 0, 4, tmp);
        return res;
    }
};
