//
//  main.cpp
//  自定义排序，这里用了stringstream，真香
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        string s;
        int id;
    };
    string arrangeWords(string text) {
        stringstream ss(text);
        string tmp;
        vector<node> v;
        int cnt = 0;
        while (ss >> tmp) {
            tmp[0] = tolower(tmp[0]);
            node t;
            t.s = tmp;
            t.id = cnt++;
            v.push_back(t);
        }
        sort(v.begin(), v.end(), [](node& a, node& b) {
            if (a.s.size() == b.s.size()) return a.id < b.id;
            return a.s.size() < b.s.size();
        });
        string res;
        for (auto t: v) {
            if (res.empty()) res += t.s;
            else {
                res.push_back(' ');
                res += t.s;
            }
        }
        res[0] = toupper(res[0]);
        return res;
    }
};
