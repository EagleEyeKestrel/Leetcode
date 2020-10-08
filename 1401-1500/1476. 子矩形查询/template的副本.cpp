//
//  main.cpp
//  虽然是中等，但几乎是比简单题还简单的。暴力就行了，大概就是熟悉一下构造类题目的流程
//  Copyright © 2020 ji luyang. All rights reserved.
//

class SubrectangleQueries {
public:
    int a[110][110];
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int m = rectangle.size(), n = rectangle[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = rectangle[i][j];
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) {
                a[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return a[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
