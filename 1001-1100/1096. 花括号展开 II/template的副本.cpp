//
//  main.cpp
//  这个写完估计只有我自己看得懂在写什么。。
//  还是简单说一下吧。。先预处理出每个括号的映射关系
//  expr是个递归函数，处理[l,r]部分的表达式，返回一个vector。
//  注意最后结果是直接排序就可以了，题目好像没讲清楚这个“有序”
//
//  expr部分先判断特殊情况。如果是{...}直接处理内部
//  如果这个部分没有括号，那就说明是一个完整的单词，直接返回
//  否则，有两种情况，一种是逗号隔开取并集，一种是做笛卡尔积，用个flag判断一下
//  并集部分，递归处理子问题，然后最后并在ans里
//  笛卡尔积部分，先用res表示各个{}{}{}...{}部分子问题的序列
//  （注意{}可能没有{}，只是一个单词，比如a{b,c}
//  然后用bfs，建一个队列得到各个部分的直积
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f[60];
    vector<string> bfs(vector<vector<string>> &res) {
        queue<string> q;
        q.push("");
        for (int i = 0; i < res.size(); i++) {
            int n = q.size();
            while (n--) {
                string top = q.front();
                q.pop();
                for (string ss: res[i]) {
                    q.push(top + ss);
                }
            }
        }
        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    vector<string> expr(string& s, int l, int r) {
        if (f[l] == r) return expr(s, l + 1, r - 1);
        int haveBrace = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
                haveBrace = 1;
                break;
            }
        }
        if (!haveBrace) {
            return { s.substr(l, r - l + 1) };
        }
        int d = 0, flag = 1;
        for (int i = l; i <= r; i++) {
            if (s[i] == '{') d++;
            if (s[i] == '}') d--;
            if (!d && s[i] == ',') {
                flag = 0;
                break;
            }
        }
        //  union
        if (!flag) {
            unordered_set<string> se;
            vector<string> ans;
            d = 0;
            int nowl = l;
            for (int i = l; i <= r; i++) {
                if (s[i] == '{') d++;
                if (s[i] == '}') d--;
                if (i == r || s[i + 1] == ',' && !d) {
                    vector<string> tmp = expr(s, nowl, i);
                    nowl = i + 2;
                    for (string& ss: tmp) {
                        if (!se.count(ss)) {
                            ans.push_back(ss);
                            se.insert(ss);
                        }
                    }
                }
            }
            return ans;
        }
        //  mul
        vector<vector<string>> res;
        int now = l;
        while (now <= r) {
            if (f[now] != -1) {
                res.push_back(expr(s, now, f[now]));
                now = f[now] + 1;
            } else {
                int nowr = now;
                while (nowr <= r && s[nowr] != '{') nowr++;
                res.push_back(expr(s, now, nowr - 1));
                now = nowr;
            }
        }
        return bfs(res);
    }
    vector<string> braceExpansionII(string expression) {
        int n = expression.size();
        for (int i = 0; i < n; i++) f[i] = -1;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (expression[i] == '{') {
                v.push_back(i);
            }
            if (expression[i] == '}'){
                f[i] = v.back();
                f[v.back()] = i;
                v.pop_back();
            }
        }
        vector<string> ans = expr(expression, 0, n - 1);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
