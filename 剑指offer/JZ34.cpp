//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
#include<string>
using namespace std;
class Solution {
public:
    //使用哈希表实现
    int FirstNotRepeatingChar(string str) {
        int res=0;
        if(str.length() == 0) return-1;
        int tablesize=256;
        int hashTable[256]={0};
        for(int i=0;i<str.length();i++){
            if(str[i]!='\0'){
                hashTable[str[i]]++;
            }
        }
        for(int i=0;i<str.length();i++){
            if(str[i]!='\0'){
                if(hashTable[str[i]]==1)
                    return i;
            }
        }
        return -1;
    }
};