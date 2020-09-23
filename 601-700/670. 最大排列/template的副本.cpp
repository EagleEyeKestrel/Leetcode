//
//  main.cpp
//  感觉最省力的做法就是排个序，然后从高位开始比对，哪一位不一样的就换
//  注意如果有多个位置可换，应该换最右边的那个
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num);
        string sorted = res;
        sort(sorted.begin(), sorted.end(), greater<char>());
        for(int i = 0; i < res.size(); i++) {
            if(res[i] != sorted[i]) {
                for(int j = res.size() - 1; j > i; j--) {
                    if(res[j] == sorted[i]) {
                        swap(res[j], res[i]);
                        break;
                    }
                }
                break;
            }
        }
        return stoi(res);
    }
};
