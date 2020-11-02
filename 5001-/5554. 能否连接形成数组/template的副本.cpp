//
//  main.cpp
//  本来还没想到什么办法，但发现每个元素都是不一样的，那就方便多了，直接建立索引
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int ind[128];
        memset(ind, 0, sizeof(ind));
        for(int i = 0; i < arr.size(); i++) {
            ind[arr[i]] = i + 1;
        }
        for(int i = 0; i < pieces.size(); i++) {
            for(int j = 0; j < pieces[i].size(); j++) {
                if(!ind[pieces[i][j]]) return false;
                if(j && ind[pieces[i][j]] != ind[pieces[i][j - 1]] + 1) return false;
            }
        }
        return true;
    }
};
