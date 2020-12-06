#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //暴力破解解法，O(n^2)，因为最坏情况下，数组中的元素都需要遍历一次
        if(array.size() == 0)
            return false;
        int row = 0;
        int rows = array.size();        // 行
        int colunms = array[0].size();  // 列
        int colunm = colunms - 1;

        while(row < rows && colunm >= 0)
        {
            if(target == array[row][colunm])
                return true;
            else if(target > array[row][colunm])
                row++;
            else
                colunm--;
        }
        return false;
    }

};