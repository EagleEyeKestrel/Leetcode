//
//  main.cpp
//  我的思路：二分答案再进行check
//  先考虑两个数组都只有正数的情况 对于一个mid，我们可以穷举一个数组的数，二分计数另一个数组有多少个和他的积< mid，从而计算出mid的排名。
//  但这里有负数和0，怎么办？我把每个数组分成负数，0和正数
//  0比较烦，先特判答案是不是0 。然后关键是负数
//  如果答案是负数的话，其实就是找负数的绝对值里第neg-k+1小的数。把负数变成正数然后一样处理即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> v1, v2, v3, v4;
    long long f(long long rank) {
        long long l = 1, r = 10000000000;
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            long long num = 0;
            for (int i = 0; i < v1.size(); i++) {
                int x = v1[i];
                int id = lower_bound(v3.begin(), v3.end(), mid % x ? mid / x + 1 : mid / x) - v3.begin();
                num += id;
            }
            for (int i = 0; i < v2.size(); i++) {
                int x = v2[i];
                int id = lower_bound(v4.begin(), v4.end(), mid % x ? mid / x + 1 : mid / x) - v4.begin();
                num += id;
            }
            if (num + 1 > rank) r = mid - 1;
            else l = mid;
        }
        return l;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long m = nums1.size(), n = nums2.size();
        
        int z1 = 0, z2 = 0;
        for (int x: nums1) {
            if (x < 0) v1.push_back(x);
            else if (x > 0) v2.push_back(x);
            else z1++;
        }
        for (int x: nums2) {
            if (x < 0) v3.push_back(x);
            else if (x > 0) v4.push_back(x);
            else z2++;
        }
        long long n1 = v1.size(), n2 = v2.size(), n3 = v3.size(), n4 = v4.size();
        long long neg = n1 * n4 + n2 * n3, pos = n1 * n3 + n2 * n4;
        if (k > neg && k <= m * n - pos) return 0;
        for (int i = 0; i < v1.size(); i++) v1[i] *= (-1);
        for (int &x: v3) x *= (-1);
        if (k > m * n - pos) {
            reverse(v1.begin(), v1.end());
            reverse(v3.begin(), v3.end());
            return f(k - (m * n - pos));
        }
        swap(v3, v4);
        reverse(v1.begin(), v1.end());
        reverse(v4.begin(), v4.end());
        return -f(neg - k + 1);
    }
};
