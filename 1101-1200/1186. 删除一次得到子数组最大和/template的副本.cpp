//
//  main.cpp
//  如果不删除，那就是最简单的最大子数组和问题
//  如果删除。考虑删除i，那么记录以i-1为末尾的子数组的最大值，以及以i+1为开头的子数组的最大值
//  这里有两个细节问题。一个是，比如说l[i-1]<0，那么按理来说我不应该加上l[i-1]
//  有两种办法，一种就是进行特判，只有两边至少取了一边的和才取max
//  另一种，其实如果只取一边的结果，相当于只取这一段子数组，没有进行删除操作。所以直接加上不会影响
//  但是必须要加上n==1的特判，因为如果只有一个负数，tmp就会是0。但如果不止一个元素，tmp的值就是有意义的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        int l[n], r[n];
        int minv = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            l[i] = s - minv;
            minv = min(minv, s);
        }
        s = 0, minv = 0;
        for (int i = n - 1; i >= 0; i--) {
            s += arr[i];
            r[i] = s - minv;
            minv = min(minv, s);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            if (i > 0) tmp += l[i - 1];
            if (i < n - 1) tmp += r[i + 1];
            res = max(res, max(l[i], tmp));
        }
        return res;
    }
};
