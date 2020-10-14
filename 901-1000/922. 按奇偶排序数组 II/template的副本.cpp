//
//  main.cpp
//  想法肯定很多，把所有的奇数/偶数存一下然后顺序存放
//  这里写一个空间O(1)的，用odd和even表示下一个奇数/偶数的位置
//  遍历A[i]发现位置不对，就往后放。如果位置对的，i < odd时不用odd += 2了
//  因为这个应该就是之前换过来的，已经加过2了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size(), odd = 1, even = 0;
        for(int i = 0; i < n; i++) {
            while(A[i] % 2 != i % 2) {
                if(A[i] % 2) {
                    swap(A[i], A[odd]);
                    odd += 2;
                } else {
                    swap(A[i], A[even]);
                    even += 2;
                }
            }
            if(i % 2 && i == odd) odd += 2;
            else if(i % 2 == 0 && i == even) even += 2;
        }
        return A;
    }
};
