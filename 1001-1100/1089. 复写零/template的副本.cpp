//
//  main.cpp
//  要实现空间O(1)的话，不是一道很简单的简单题，要稍微想一下
//  遍历一遍，可以知道复写之后数组是到哪个元素为止(cnt>=n)。然后可以由cnt是否>n判断最后一个元素是写一次还是两次
//  最后填元素一定是从右往左填。因为从左往右的话，由于多写了0，填的比原数组更快，覆盖掉原来的元素了。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), cnt = 0, i = 0, j = n - 1;
        for( ; i < n; i++) {
            if(arr[i]) cnt++;
            else cnt += 2;
            if(cnt >= n) break;
        }
        while(i >= 0) {
            if(arr[i]) {
                arr[j--] = arr[i];
            } else {
                arr[j] = 0;
                j--;
                if(!(j == n - 2 && cnt > n)) {
                    arr[j] = 0;
                    j--;
                }
            }
            i--;
        }

    }
};
