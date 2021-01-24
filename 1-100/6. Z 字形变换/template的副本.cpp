//
//  main.cpp
//  自认为写的还挺简洁
//  i是每行第一个元素，t是每次循环有几个元素
//  比如例子里numRows=3的情况，第一个循环包括PAYP，就是四个元素，每次从一个元素开始
//  只有最上层和最下层的元素每次循环只push一个，其余都要放进去第二个
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int t = numRows == 1 ? 1 : 2 * numRows - 2, i = 0, n = s.size();
        while (i < numRows) {
            int j = i;
            while (j < n) {
                res.push_back(s[j]);
                if (i && i != numRows - 1) {
                    int jj = j + 2 * (numRows - i) - 2;
                    if (jj < n) res.push_back(s[jj]);
                }
                j += t;
            }
            i++;
        }
        return res;
    }
};
