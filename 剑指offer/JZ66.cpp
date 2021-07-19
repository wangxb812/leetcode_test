/*
 * @Author: m1ng
 * @Date: 2021-07-18 01:53:33
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-19 23:48:34
 * @FilePath: \leetcode_test\剑指offer\JZ66.cpp
 * @Description: header
 */
#include<vector>
using namespace std;
class Solution {
public:
    int row, col, res;//定义全局变量,res为输出变量
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> matrix(rows, vector<bool>(cols)); //定义一个rows行cols列的矩阵容器
        row = rows, col = cols; //为全局变量赋值
        return dfs(threshold, 0, 0, matrix);
    }
    int dfs (int threshold, int x, int y, vector<vector<bool>> &matrix) { //定义回溯函数
        if (Sum(x) + Sum(y) > threshold || x <0 || x >= row || y < 0 || y >= col || matrix[x][y]) return false;
        matrix[x][y] = true;//将访问的地方赋值true
        return dfs(threshold, x - 1, y, matrix) //up
              +dfs(threshold, x + 1, y, matrix) //down
              +dfs(threshold, x, y - 1, matrix) //left
              +dfs(threshold, x, y + 1, matrix) //right
              +1;
    }
    int Sum(int x) { //单个横纵坐标的各个位数之和
        int sum = 0;
        while(x) sum += x % 10, x /= 10;
        return sum;
    }
};