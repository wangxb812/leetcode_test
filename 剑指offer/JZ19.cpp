//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int len = matrix.size();
        int column = matrix[0].size();
        vector<int> resMatrix;
        int pos = len > column ? (column-1)/2:(len-1)/2;
        for(int i=0;i<=pos;i++){
            for(int c=i;c<column-i;c++){
                resMatrix.push_back(matrix[i][c]);
            }
            for(int r=i+1;r<len-i;r++){
                resMatrix.push_back(matrix[r][column-1-i]);
            }
            if (i != len - 1 - i && i != column - 1 - i) {        // 添加判断条件：最后一环为单行或单列的情况下，不重复打印
            for (int c = column - 2 - i; c >= i; c--)
                resMatrix.push_back(matrix[len - 1 - i][c]);
            for (int r = len - 2 - i; r > i; r--)
                resMatrix.push_back(matrix[r][i]);
            }
        }
        return resMatrix;
    }
};