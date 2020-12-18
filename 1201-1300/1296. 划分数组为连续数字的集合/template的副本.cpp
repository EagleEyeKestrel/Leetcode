//
//  main.cpp
//  贪心，每次从最小的数取连续k个
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k) return false;
        map<int, int> m;
        for (int num: nums) m[num]++;
        while (!m.empty()) {
            int start = m.begin()->first;
            for (int i = 0; i < k; i++) {
                int val = start + i;
                if (m.find(val) != m.end()) {
                    m[val]--;
                    if (m[val] == 0) m.erase(val);
                } else return false;
            }
        }
        return true;
    }
};
