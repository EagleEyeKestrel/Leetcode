//
//  main.cpp
//  这个第三题有点水，双指针就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), res = 0, l = 0;
        int st = 0, sf = 0;
        for (int r = 0; r < n; r++) {
            if (answerKey[r] == 'T') st++;
            else sf++;
            while (min(st, sf) > k) {
                if (answerKey[l] == 'T') st--;
                else sf--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
