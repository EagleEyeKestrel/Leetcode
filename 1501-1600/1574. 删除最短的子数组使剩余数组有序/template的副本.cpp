//
//  main.cpp
//  自己的一个思路
//  先找到第一个arr[i1]>arr[i1+1]，（如果不存在输出0
//  找到最小的arr[i2]，使得arr[i2]以后都是有序的
//  即现在arr[0]-arr[i1] arr[i2]-arr[n-1]都是有序的
//  如果arr[i1]<=arr[i2]只需要删除中间的
//  否则，遍历arr[0]-arr[i1]的每个元素，以arr[i]为第一段结束，在arr[i2]-arr[n-1]寻找最小的arr[id]，使得arr[id]>=arr[i]，直接用lower_bound即可，复杂度O(nlogn)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), i1 = -1, i2 = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                i1 = i;
                break;
            }
        }
        if (i1 == -1) return 0;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                i2 = i;
                break;
            }
        }
        if (arr[i2] >= arr[i1]) return i2 - i1 - 1;
        int res = i2;
        for (int i = 0; i <= i1; i++) {
            int id = lower_bound(arr.begin() + i2, arr.end(), arr[i]) - arr.begin();
            res = min(res, id - 1 - i);
        }
        return res;
    }
};
