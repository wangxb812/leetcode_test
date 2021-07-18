#include<iostream>
#include<cstring>
using namespace std;
//现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
    //从前向后递进需要每次移动后面所有字符串，因此从后往前递进
	void replaceSpace(char *str,int length) {
        if(str==nullptr || length<=0)
            return;
        int num=0;
        for(int i=0;i<length;i++)
        {
            if(str[i]==' ')
                num++;
        }
        int newlength = length +num*2;
        for(int i=length;i>=0;i--)
        {
            if(str[i]==' '){
                str[newlength--]='0';
                str[newlength--]='2';
                str[newlength--]='%';
            }else{
                str[newlength--]=str[i];
            }
        }
	}
    //使用string的方式进行查找复制，空间复杂度比第一种高
    //或者使用string中的 replace(pos, 1, "%20") 也可
    void replaceSpace_2(char *str,int length){
        if(str == nullptr || length <= 0){
            return;
        }
        string res;
        for(int i = 0;i <length; i++){
            char x = str[i];
            if(x!=' '){
                res+=x;
            }else{
                res+="%20";
            }
        }
        strcpy(str,res.c_str());//c_str()函数返回一个指向正规c字符串的指针
    }
    //有序数组A1,A2，将A2数字插入A1并且是排序的
    void replaceSpaceAtoB(char *str1,int len1,char *str2,int len2){
        if(str1 == nullptr && str2==nullptr)
            return;
        int newlength = len1+len2;
        int i=len1,j=len2;
        while(i >= 0 && j>=0)
        {
            if(str1[i]>str2[j]){
                str1[newlength--]=str1[i];
                i--;
            }else{
                str1[newlength--]=str2[j];
                j--;
            }
        }
    }
    string replaceSpace(string s) {
        string ret;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' '){
                ret+="%20";
            }
            else ret += s[i];
        }
        return ret;
    }
};