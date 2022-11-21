//
//  main.cpp
//  更优的解法，只需要log(min(m, n))
//  转化成，找到最大的i，使得nums1[i] <= nums2[j+1]（我习惯于i从1开始）
//  把二分变成了我习惯的写法，用个get处理边界问题
//  assert m <= n是为了保证j不为负
//  这里的方法比较tricky，条件是l<=r，然后判断个成立
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int get(vector<int> &v, int index) {
        if (index <= 0)
            return INT_MIN;
        if (index > v.size())
            return INT_MAX;
        return v[index - 1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = m, half = (m + n + 1) / 2;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            int i = mid, j = half - mid;
            if (get(nums1, i) <= get(nums2, j + 1)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        int res1 = max(get(nums1, low), get(nums2, half - low));
        int res2 = min(get(nums1, low + 1), get(nums2, half - low + 1));
        return (m + n) % 2 ? res1 : (res1 + res2) / 2.0;
    }
};
