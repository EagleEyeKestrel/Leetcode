//
//  main.cpp
//  居然WA了两次。。要注意，不仅要i1 != i2，还要i1 + 1 < i2 !
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size(), sum = 0;
        for(int i = 0; i < n; i++) {
            sum += A[i];
        }
        if(sum % 3) return false;
        int i1 = -1, i2 = -1, now = 0;
        for(int i = 0; i < n; i++) {
            now += A[i];
            if(now == sum / 3) {
                i1 = i;
                break;
            }
        }
        now = 0;
        for(int i = n - 1; i >= 0; i--) {
            now += A[i];
            if(now == sum / 3) {
                i2 = i;
                break;
            }
        }
        return i1 >= 0 && i2 >= 0 && i1 + 1 < i2;
    }
};
