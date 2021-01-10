//
//  main.cpp
//  异或的结合律
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = { first };
        for (int i = 0; i < encoded.size(); i++) {
            res.push_back(encoded[i] ^ first);
            first = res.back();
        }
        return res;
    }
};
