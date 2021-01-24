//
//  main.cpp
//  mp是文件内容对应的文件名的列表，主要还是字符串的操作
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (string path: paths) {
            stringstream ss(path);
            string tmp, dir;
            ss >> dir;
            while (ss >> tmp) {
                int id = tmp.find('(');
                string content = tmp.substr(id + 1, tmp.size() - id - 2);
                string name = dir + "/" + tmp.substr(0, id);
                mp[content].push_back(name);
            }
        }
        for (auto it: mp) {
            if (it.second.size() > 1) {
                res.push_back(it.second);
            }
        }
        return res;
    }
};
