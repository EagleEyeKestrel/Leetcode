//
//  main.cpp
//  滑动窗口的做法有点难想，需要去遍历字符的种类数kinds，找到种类是kinds的最长子串
//  如何保证答案一定在里面？我还没能想到
//  后来想通了。结果字符串比如说有k种字符，那么在kinds=k的时候一定会搜到这个字符串。当r到了这个右边界的时候，左边界也一定到位。左边界肯定不会更右，因为到了这个地方的时候已经是kinds种了。但也不会更左，如果更左，且种类数不变，那么结果字符串也应该可以继续左移。
//  还有分治的解法，很妙
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), res = 0;
        int cnt[26];
        for (int kinds = 1; kinds <= 26; kinds++) {
            memset(cnt, 0, sizeof(cnt));
            int l = 0, unique = 0;
            for (int r = 0; r < n; r++) {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1) unique++;
                while (unique > kinds) {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == 0) unique--;
                    l++;
                }
                int flag = 1;
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] > 0 && cnt[i] < k) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
