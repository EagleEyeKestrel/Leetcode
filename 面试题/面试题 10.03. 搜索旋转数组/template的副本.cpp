//
//  main.cpp
//  并不容易的题，比81更难
//  这里讨论标准用arr[l]和arr[mid]的大小关系
//  第一种情况，arr[l]<arr[mid]说明mid左边一定有序
//  第二种情况，是右侧有序，但为什么多了个arr[l]>target?比如5，5，5，1，2，3，4，5，最左侧的5在左边
//  第三种情况，[l,r]是当前搜索区间，如果arr[l]不等于target，就只能从左往右寻找了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        if (!n) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[l] < arr[mid]) {
                if (arr[l] <= target && target <= arr[mid]) r = mid;
                else l = mid + 1;
            } else if (arr[l] > arr[mid]) {
                if (arr[mid] < target && target <= arr[r] && arr[l] > target) l = mid + 1;
                else r = mid;
            } else {
                if (arr[l] != target) l++;
                else return l;
            }
        }
        return arr[l] == target ? l : -1;
    }
};
