//
//  main.cpp
//  方法h当然很多，这里用的是转化成偶奇偶奇...的形式
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2) low--;
        if(!high % 2) high--;
        return (high - low + 1) / 2;
    }
};
