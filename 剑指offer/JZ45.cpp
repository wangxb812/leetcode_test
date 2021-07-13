/*
 * @Author: m1ng
 * @Date: 2021-07-11 01:12:16
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-11 15:26:11
 * @FilePath: \leetcode_test\剑指offer\JZ45.cpp
 * @Description: header
 */
#include<vector>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
      sort(numbers.begin(),numbers.end());
      int numberZero=0;
      int numberGap=0;
      for(int i=0;i<numbers.size();i++){
          if(numbers[i]==0){
              numberZero++;
          }
          else if(numbers[i]==numbers[i+1]){
              return false;
          }
          else{
              numberGap+=numbers[i+1]-numbers[i]-1;
          }  
      }
      return (numberGap>numberZero)?false:true;  
    }
};