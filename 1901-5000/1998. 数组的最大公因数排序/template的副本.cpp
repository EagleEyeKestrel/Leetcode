//
//  main.cpp
//  对两个数字如果有相同的公因数，那就连边组成并查集
//  每个并查集内的数字可以任意交换，所以只需看分组排序之后结果是不是排序的
//  关键是要能想到每个并查集内 可以任意交换的结论
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[100010];
    int find(int x) {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        p[pa] = pb;
    }
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <= 1e5; i++) p[i] = i;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 2; j * j <= num; j++) {
                if (num % j != 0) continue;
                merge(j, nums[i]);
                while (num % j == 0) num /= j;
            }
            if (num > 1) merge(nums[i], num);
        }
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < n; i++) {
            if (find(nums[i]) != find(sorted_nums[i])) return false;
        }
        return true;
    }
};
