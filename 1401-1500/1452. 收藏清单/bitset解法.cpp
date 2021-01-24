//
//  main.cpp
//  别人的解法，其实复杂度还是100*100*500，但是常数小
//  用了bitset这个数据结构，之前没有接触过
//  nmap表示一个网页被哪些人收藏过。这里不好状压在一个int/long里
//  所以要压在一个128的bitset里
//  Copyright © 2021 ji luyang. All rights reserved.
//

#include <unordered_map>

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies)
    {
        unordered_map<string, bitset<128>> nmap;
        vector<int> res;
        int length(favoriteCompanies.size());

        for (int i=0; i < length; ++i)
        {
            for (auto& work : favoriteCompanies[i])
            {
                nmap[work].set(i);
                // cout<<i<<" :"<<word<<endl;
            }
        }

        // print_map(nmap);
        for (int i = 0; i < length; ++i )
        {
            auto bits = nmap[favoriteCompanies[i][0]];

            for (int j = 1; j < favoriteCompanies[i].size(); ++j)
            {
                bits &= nmap[favoriteCompanies[i][j]];
            }
            if (bits.count() <= 1)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

