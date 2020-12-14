//
//  main.cpp
//  一个个递减肯定不行
//  我们设想，对于相邻的两位ab，如果发现a>b
//  b之后都是递增的，调整b更小肯定不可行，所以只能把a减一。为了这个数尽量大，a-1后面应该全部是9
//  从个位往前依次做这样的事情
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n = to_string(N);
        if (n.size() == 1) return N;
        for (int i = n.size() - 2; i >= 0; i--) {
            if (n[i] > n[i + 1]) {
                n[i]--;
                for (int j = i + 1; j < n.size(); j++) n[j] = '9';
            }
        }
        return stoi(n);
    }
};
