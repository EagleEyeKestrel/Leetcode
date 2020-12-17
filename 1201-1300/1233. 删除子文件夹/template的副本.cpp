//
//  main.cpp
//  排序之后，边遍历一个文件名，每到一层文件夹，检查这个文件夹之前有没有出现过
//  如果是一个子文件夹，那一定到某一层文件的路径出现过
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> fa;
        vector<string> res;
        sort(folder.begin(), folder.end());
        int n = folder.size();
        for (int i = 0; i < n; i++) {
            string tmp = "";
            int flag = 1;
            for (int j = 0; j < folder[i].size(); j++) {
                if (j && folder[i][j] == '/') {
                    if (fa.count(tmp)) {
                        flag = 0;
                        break;
                    }
                }
                tmp.push_back(folder[i][j]);
            }
            if (flag) res.push_back(folder[i]);
            fa.insert(folder[i]);
        }
        return res;
    }
};
