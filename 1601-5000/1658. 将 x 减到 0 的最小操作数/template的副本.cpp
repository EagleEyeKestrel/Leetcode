//
//  main.cpp
//  意思是从两头最短拿x，那就说明要从中间拿最长的sum-x
//  拿哈希表记一下前缀和就可以了。当然也可以空间O(1)，用双指针(注释)
//  WA了一次，当所有数加起来等于x时，中间一段会变成0，需要讨论一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), s = 0, maxl = 0, sum = 0;
        for(int num: nums) sum += num;
        if(x == sum) return n;
        unordered_map<int, int> m;
        m[0] = 0;
        for(int i = 1; i <= n; i++) {
            s += nums[i - 1];
            if(m.count(s - (sum - x))) {
                maxl = max(maxl, i - m[s - sum + x]);
            }
            if(!m.count(s)) m[s] = i;
        }
        return maxl ? n - maxl : -1;
    }
};
/*
 class Solution {
 public:
     int minOperations(vector<int>& nums, int x) {
         int n = nums.size(), sum = 0, l = 0, tmp = 0, maxl = 0;
         for(int num: nums) sum += num;
         if(sum == x) return n;
         for(int r = 0; r < n; r++) {
             tmp += nums[r];
             while(l < r && tmp > sum - x) {
                 tmp -= nums[l++];
             }
             if(tmp == sum - x) {
                 maxl = max(maxl, r - l + 1);
             }
         }
         return maxl ? n - maxl : -1;
     }
 };
*/
