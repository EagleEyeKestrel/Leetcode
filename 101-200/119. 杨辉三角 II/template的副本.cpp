//
//  main.cpp
//  之前的118写的不好，因为不需要每行新建一个newtmp然后copy
//  递推方程是tmp[j]=tmp[j]+tmp[j-1]，所以j逆序就可以在原来的tmp直接推出新的tmp，最后再推一个1进来
//  另一种思路，由于第k行刚好是k为底的一系列二项式系数，所以可以直接算出所有二项式系数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int> tmp = {1};
        for(int i = 2; i <= rowIndex + 1; i++) {
            for(int j = tmp.size() - 1; j >= 1; j--) {
                tmp[j] = tmp[j] + tmp[j - 1];
            }
            tmp.push_back(1);
        }
        return tmp;
    }
};
