/*
 * @Author: m1ng
 * @Date: 2021-07-18 01:53:25
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-19 22:36:48
 * @FilePath: \leetcode_test\剑指offer\JZ65.cpp
 * @Description: header
 */
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        if(matrix.size()==0) return false;
        int len1=matrix.size();int len2=matrix[0].size();
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(dfs(matrix,word,i,j,0))  return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >& matrix,string word,int i,int j,int index){
        if(i>=matrix.size() || i<0 ||j>=matrix[0].size() || j<0 || matrix[i][j] != word[index])
        return false;
        if(index == word.length()-1)    return true;
        char temp = matrix[i][j];
        matrix[i][j]='#';
        bool res=dfs(matrix, word, i + 1, j, index + 1)
            || dfs(matrix, word, i - 1, j, index + 1)
            || dfs(matrix, word, i, j + 1, index + 1)
            || dfs(matrix, word, i, j - 1, index + 1);
        matrix[i][j] = temp;
        return res;
    }
};