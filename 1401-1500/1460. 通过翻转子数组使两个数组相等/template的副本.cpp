//
//  main.cpp
//  只要元素一样，就可以翻转成target
//  类似于冒泡排序的原理
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) if(arr[i] != target[i]) return false;
        return true;
    }
};
