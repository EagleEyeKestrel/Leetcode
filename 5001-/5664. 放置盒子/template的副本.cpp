//
//  main.cpp
//  最后一题也不难，主要是怎么把思想变成code，实现方法也各不相同
//  都知道大概思路是怎么叠，样例其实也给了我们很大提示
//  我的思路，用level表示最后有多少层，now表示，level层至少有多少个方块
//  level层方块，方块可能的个数是[now, nextnow)
//  res是当level层摆成样例那种基本情况时底层方块的数量，然后还要再摆left个
//  可以发现方块可以从左视图开始，地上摆一个，然后摆两个(一个地上一个在第二层)
//  然后摆三个(一个地上，两个在方块上)，所以依次减少left，直到left<=0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumBoxes(int n) {
        int level = 1, now = 1;
        while (n >= now) {
            int nextnow = now + (level + 1) * (level + 2) / 2;
            if (n < nextnow) break;
            else {
                level++;
                now = nextnow;
            }
        }
        int res = level * (level + 1) / 2, left = n - now;
        now = 1;
        while (left > 0) {
            left -= now;
            res++;
            now++;
        }
        return res;
    }
};
