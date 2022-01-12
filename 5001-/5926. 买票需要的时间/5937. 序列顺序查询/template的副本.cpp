//
//  main.cpp
//  题目的意思就是对于一个字符串+int 的数据结构，维护第i好的组合
//  i是随着查询递增的
//  自然用两个multiset维护，保持第一个的大小是cnt即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class SORTracker {
public:
    struct node {
        string name;
        int score;
        bool operator < (const node& nn) const {
            if (score == nn.score) return name < nn.name;
            return score > nn.score;
        }
    };
    multiset<node> s1, s2;
    int cnt = 1;
    SORTracker() {

    }
    
    void add(string name, int score) {
        node tmp;
        tmp.name = name;
        tmp.score = score;
        s1.insert(tmp);
        if (s1.size() > cnt) {
            auto out = *(s1.rbegin());
            auto p = s1.end();
            p--;
            s1.erase(p);
            s2.insert(out);
        }
    }
    
    string get() {
        auto out = *(s1.rbegin());
        string res = out.name;
        cnt++;
        if (!s2.empty()) {
            auto in = *(s2.begin());
            s1.insert(in);
            s2.erase(s2.begin());
        }
        return res;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
