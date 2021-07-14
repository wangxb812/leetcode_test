#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        vector<string> sentence;
        string ret;
        int i=0,j=0;int len=str.length();
        while(i<len)
        {
            if(str[i]!=' ')
            {
                sentence[j].push_back(str[i]);
            }
            else if(str[i]==' '&& str[i+1]!=' ')
            {
                j++;
            }//这里是考虑了多个空格
            else{
                continue;
            }
            i++;
        }
        for(int i=0;i<sentence.size();i++)
        {
            if(i!=sentence.size()-1){
                ret+=sentence[i]+' ';
            }
            else    ret+=sentence[i];
        }
        return ret;
    }
    //翻转解法
    string ReverseSentence(string str) {
        string ret=str;
        int len=str.size();
        if(len == 0)    return "";
        ret+=' ';
        int mark=0;
        for(int i=0;i<len+1;i++){
            if(ret[i]==' '){
                reverse(ret,mark,i-1);
                mark =i+1;
            }
        }
        ret = ret.substr(0,len);
        reverse(ret,0,len-1);
        return ret;
    }
    void reverse(string &str,int begin,int end){
        while(begin<end){
            swap(str[begin++],str[end--]);
        }
    }
};