//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        int sum = 0;
        int pos = 0;
        set<int> res;
        for(int i=0;i<len;i++)
        {
            res.insert(numbers[i]);
            sum = sum > res.count(numbers[i]) ? sum:res.count(numbers[i]);
            pos = sum > res.count(numbers[i]) ? pos:i;
        }
        return sum>len/2?numbers[pos]:0;
    }
    //排序法.数组排序，然后可能的众数肯定在数组中间，然后判断一下
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int cond = numbers[numbers.size() / 2];
        int cnt = 0;
        for (const int k :numbers) {
            if (cond == k) ++cnt;
        }
        if (cnt > numbers.size() / 2) return cond;
        return 0;
    }
};