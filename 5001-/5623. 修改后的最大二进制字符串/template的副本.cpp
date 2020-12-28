//
//  main.cpp
//  贪心。肯定要优先满足高位能变成1，后面无论情况如何，高位能变成1是最关键的。遍历，遍历到binary[i]的时候，

//如果是1，不用变

//如果是0，如果binary[i+1]='0'，那么可以直接让binary[i]变成'1'。如果binary[i+1]是'1'，我们发现对于一个子串 0 11...10(中间是连续的1)，我们可以转化成101...11来使得binary[i]变成'1'。这里用now标记binary[i]右侧最近的'0'，可以进行这样的操作。 空间O(1)，时间O(n)。
//  注意，本来我想用一个数组r[i]来标记i右侧最近的0，但要注意到上述修改的过程可能会对很多元素的r[i]造成变化，所以不行。后来一想用一个指针now就可以轻松实现了
//
//  看评论看到另外一种更本质的思路。10变成01的本质是0提前一格，00变成10的本质是两个0相遇，前面的0变成1
//  所以每次操作的过程都是把0提前，和前面的0合并，然后之前的0变成1 ，最后也只会剩下1个0
//  关键就是看这个0的位置。假设一开始最左边的0坐标是index，最后0的位置就是index + count0 - 1
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size(), now = 0;
        for (int i = 0; i < n; i++) {
            if (now == i) now++;
            while (now < n && binary[now] != '0') now++;
            if (binary[i] == '0') {
                if (i + 1 < n && binary[i + 1] == '0') {
                    binary[i] = '1';
                } else if (i + 1 < n && binary[i + 1] == '1') {
                    if (now < n) {
                        binary[i] = '1';
                        binary[i + 1] = '0';
                        binary[now++] = '1';
                        while (now < n && binary[now] != '0') now++;
                    }
                }
            }
        }
        return binary;
    }
};
