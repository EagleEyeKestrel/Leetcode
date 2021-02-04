//
//  main.cpp
//  第一种解法。看到题目我就想维护两个差不多大小的堆，其中small的大小>=big
//  small的最大数，和big的最小数，求平均即可。 所以small做大顶堆，big做小顶堆
//  但不知道每次怎么排除nums[i-k]。。
//  其实不用堆，用multiset即可实现
//  实现两个api，insert和remove即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    multiset<double> small, big;
    void insert(double x) {
        if (!small.empty() && x <= *small.rbegin()) {
            small.insert(x);
            if (small.size() > big.size() + 1) {
                int val = *small.rbegin();
                big.insert(val);
                small.erase(small.find(val));
            }
        } else {
            big.insert(x);
            if (big.size() > small.size()) {
                int val = *big.begin();
                small.insert(val);
                big.erase(big.begin());
            }
        }
    }
    void remove(double x) {
        if (!small.empty() && x <= *small.rbegin()) {
            small.erase(small.find(x));
            if (big.size() > small.size()) {
                int val = *big.begin();
                small.insert(val);
                big.erase(big.begin());
            }
        } else {
            auto it = big.find(x);
            big.erase(it);
            if (small.size() > big.size() + 1) {
                int val = *small.rbegin();
                big.insert(val);
                small.erase(small.find(val));
            }
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i >= k) remove(nums[i - k]);
            insert(nums[i]);
            if (i >= k - 1) {
                double tmp = *small.rbegin();
                if (k % 2 == 0) tmp = (tmp + *big.begin()) / 2;
                res.push_back(tmp);
            }
        }
        return res;
    }
};
