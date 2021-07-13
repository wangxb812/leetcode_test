/*
 * @Author: m1ng
 * @Date: 2021-07-11 15:30:19
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-11 17:37:39
 * @FilePath: \leetcode_test\剑指offer\JZ46.cpp
 * @Description: header
 */
#include <vector>
#include <List>
using namespace std;
class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n <= 0 || m <= 0) {
            return -1;
        }
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
    int LastRemaining_Solution(int n, int m){
        if(n<1||m<1)    return -1;
        list<int>numbers(n-1);
        list<int>::iterator current = numbers.begin();
        while(numbers.size()>1){
            for(int i=1;i<m;i++){
                current++;
                if(current == numbers.end())    current=numbers.begin();
            }
            list<int>::iterator next = ++current;
            if(next==numbers.end())
                next=numbers.begin();
            --current;
            numbers.erase(current);
            current=next;
        }
        return *(current);
    }
};