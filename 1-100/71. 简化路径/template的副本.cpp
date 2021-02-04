//
//  main.cpp
//  文件路径类似于栈的结构
//  '.'不变，'..'弹出一个元素
//  每次处理一段/之间的内容
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string> s;
        int n = path.size(), i = 0;
        while (i < n) {
            while (i < n && path[i] == '/') i++;
            if (i >= n) break;
            int j = i;
            while (j < n && path[j] != '/') j++;
            if (j - i) {
                string tmp = path.substr(i, j - i);
                i = j + 1;
                if (tmp == ".." && !s.empty()) {
                    s.pop();
                }
                if (tmp != ".." && tmp != ".") {
                    s.push(tmp);
                }
            }
            i = j + 1;
        }
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res == "" ? "/" : res;
    }
};
