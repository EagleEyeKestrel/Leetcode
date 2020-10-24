//
//  main.cpp
//  now标记当前所有偶数的和。根据每次加的数是奇数还是偶数进行更新
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int now = 0;
        for(int a: A) {
            if(a % 2 == 0) now += a;
        }
        vector<int> res;
        for(auto &q: queries) {
            if(q[0] % 2) {
                if(!(A[q[1]] % 2)) now -= A[q[1]];
                else now += (A[q[1]] + q[0]);
                A[q[1]] += q[0];
            } else {
                if(!(A[q[1]] % 2)) now += q[0];
                A[q[1]] += q[0];
            }
            res.push_back(now);
        }
        return res;
    }
};
