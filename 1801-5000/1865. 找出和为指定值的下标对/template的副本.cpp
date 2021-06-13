//
//  main.cpp
//  比较简单的题，对nums2建立一个哈希表就行了，每次count的时候遍历nums1即可
//  注意观察数据范围
//  Copyright © 2021 ji luyang. All rights reserved.
//

class FindSumPairs {
public:
    unordered_map<int, int> mp;
    vector<int> v1, v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num: nums2) mp[num]++;
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index] += val;
        mp[v2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int num: v1) {
            res += mp[tot - num];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
