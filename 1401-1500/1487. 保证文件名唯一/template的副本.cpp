//
//  main.cpp
//  很久以前的比赛题，直接把我心态搞炸了当时
//  其实就只需要一个数据结构
//  用一个map，标记一个文件名当前后缀已经加到了多少
//  还没出现过的话好办，标记成1就行了
//  出现过的话，还要检查往后的一些后缀，比如顺序是a,a(1),a，第三个a就只能是a(2)
//  然后更新a的value。另外a(1) a(2)也是第一次出现，放入map
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> res;
        for (string& name: names) {
            if (!mp.count(name)) {
                res.push_back(name);
                mp[name] = 1;
            } else {
                int now = mp[name];
                while (mp.count(name + "(" + to_string(now) + ")")) now++;
                mp[name] = now + 1;
                res.push_back(name + "(" + to_string(now) + ")");
                mp[name + "(" + to_string(now) + ")"] = 1;
            }
        }
        return res;
    }
};
