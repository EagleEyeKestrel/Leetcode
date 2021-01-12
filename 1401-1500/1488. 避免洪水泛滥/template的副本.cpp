//
//  main.cpp
//  个人认为挺难的一道题，没想出来
//  自己的想法是，预处理每一个池塘的所有下雨序列，然后每一个晴天贪心取最近的即将下一个下雨的池塘。但是想不到有什么logn的方法
//  归根结底还是要在很多池塘中找，很不方便。其实换个角度来想
//  suns存储目前所有晴天，每次遇到晴天先不操作，等之后雨天了来考虑抽哪个池塘
//  mp存储每个池塘上一次下雨的时间
//  每次如果下雨，在晴天里找大于等于上一次下雨的索引，把水抽掉，更新mp和suns
//  别忘了抽干水之后也要更新mp[rains[i]]
//  另外，map的lower_bound要用内置的，如果用通用的会超时。这个问题有人说是因为通用的先会看容器是否支持随机访问，支持才会二分。map不支持，所以会很慢。
//  数组最后一题，终于做完啦！
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        set<int> suns;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (rains[i]) {
                if (mp.count(rains[i])) {
                    auto it = suns.lower_bound(mp[rains[i]]);
                    if (it == suns.end()) {
                        return {};
                    } else {
                        res[*it] = rains[i];
                        suns.erase(it);
                        mp[rains[i]] = i;
                    }
                } else {
                    mp[rains[i]] = i;
                }
                res[i] = -1;
            } else {
                suns.insert(i);
            }
        }
        return res;
    }
};
