/*
 * @Author: m1ng
 * @Date: 2021-07-15 23:04:19
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-16 00:27:31
 * @FilePath: \leetcode_test\剑指offer\JZ53.cpp
 * @Description: header
 */
#include <string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return bool布尔型
     */
        bool isNumeric(string str) {
        int size = str.length();
        int index= 0 ;
        // 默认全部是false
        bool hashNum=false ,hasE=false ,hasSign=false ,hasDot=false;
        // 跳过空格
        while(index<size&&str[index]==' '){
            index++;
        }
        while(index<size){
            while(index<size&&str[index]>='0'&& str[index]<='9'){
                index++;
                // 表示前面有数字
                hashNum = true;
            }
            // 到末尾直接跳出
            if(index==size){
                break;
            }
            char c = str[index];
            if(c=='e'||c=='E'){
                // 前面有E或者没有数字在前面
                if(hasE||!hashNum){
                    return false;
                }
                hasE = true;
                // 出现E了后面又可以出现数字了
                hashNum = false;
                hasSign = false;
                hasDot = false;
            }else if(c=='+'||c=='-'){
                if(hasSign||hashNum||hasDot){
                    return false;
                }
                hasSign = true;
            }else if(c=='.'){
                if(hasDot||hasE){
                    return false;
                }
                hasDot =true;
            }else if(c==' '){
                break;
            }else{
                return false;
            }
            index++;
        }        
        // 跳过空格
        while(index<size&&str[index]==' '){
            index++;
        }
        return hashNum &&index==size;
    }
};