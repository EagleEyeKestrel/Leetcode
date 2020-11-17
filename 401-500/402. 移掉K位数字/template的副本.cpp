//
//  main.cpp
//  单调栈题，写的烦了点，每次发现栈下面的数更大，就pop掉。因为如果不pop，只会得到更大的数
//  边界情况要处理一下，对于0
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int kk = k;
        for(char c: num) {
            while(k && !s.empty() && c < s.top()) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        string res;
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        res.resize(num.size() - kk);
        if(res.empty()) return "0";
        int id = 0;
        while(id < res.size() && res[id] == '0') {
            id++;
        }
        if(id >= res.size()) return "0";
        res = res.substr(id);
        return res;
    }
};
