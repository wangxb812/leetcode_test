//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
#include<vector>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        int len = str.length();
        if(len == 0)    return {};
        set<string> ret;
        Perm(0, str, ret);
        return vector<string>({ret.begin(), ret.end()});
    }
    //递归法
    void Perm(int pos,string s,set<string> &ret){
        if((pos=s.length()-1)){
            ret.insert(s);
            return ; 
        }
        for( int i=pos;i<s.length();i++){
            swap(s[pos],s[i]);
            Perm(pos+1,s,ret);
            swap(s[pos],s[i]);
        }
    }
    //set去重/剪枝/追溯法：
    set<string> res; //去重
    vector<string> Permutation(string str) {
        if (str.empty()) return {};
        string s;
        cutdown (str, s);
        return vector<string> (res.begin(), res.end());
    }
    void cutdown(string str, string s) {
        if (str.size() == 0) res.insert(s);
        for (int i = 0; i < str.size(); i ++) {
            string temp = str;
            cutdown(temp.erase(i, 1), s + str[i]);
        }
    }
};