//
//  main.cpp
//  又是语法解析的题目，递归下降分析
//  有一个难点是里层和外层的变量关系；用一个哈希表，但是往下层传的时候只传值，不传引用
//  这样上层的变量会影响下层，但下层的修改 不影响上层
//  f处理一个完整的表达式，parse从一个连续序列中提取一段段内容
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<string, int> mp;
    int evaluate(string expression) {
        return f(expression, mp);
    }
    int f(string& str, unordered_map<string, int> mp) {
        if (str[0] >= '0' && str[0] <= '9' || str[0] == '-') return stoi(str);
        if (str[0] != '(') return mp[str];
        string s = str.substr(1, str.size() - 2);
        int now = 0;
        string cmd = parse(s, now);
        if (cmd == "let") {
            while (1) {
                string v = parse(s, now);
                if (now >= s.size()) return f(v, mp);
                string e = parse(s, now);
                mp[v] = f(e, mp);
            }
        } else if (cmd == "add") {
            string e1 = parse(s, now);
            string e2 = parse(s, now);
            return f(e1, mp) + f(e2, mp);
        } else if (cmd == "mult") {
            string e1 = parse(s, now), e2 = parse(s, now);
            return f(e1, mp) * f(e2, mp);
        }
        return 0;
    }
    string parse(string& s, int& now) {
        int end = now, cnt = 0, start = now;
        if (s[now] == '(') {
            cnt = 1;
            now++;
            while (cnt) {
                if (s[now] == '(') cnt++;
                if (s[now] == ')') cnt--;
                now++;
            }
        } else {
            while (now < s.size() && s[now] != ' ') now++;
        }
        now++;
        return s.substr(start, now - start - 1);

    }
};
