/*
 * @Author: m1ng
 * @Date: 2021-07-08 23:05:54
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-08 23:10:42
 * @FilePath: \leetcode_test\剑指offer\JZ50.cpp
 * @Description: header
 */
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        sort(numbers.begin(),numbers.end());
        int i=0;
        while(i<numbers.size()){
            if(numbers[i]==numbers[i+1]){
                return numbers[i];
            }
            i++;
        }
        return -1;
    }
};