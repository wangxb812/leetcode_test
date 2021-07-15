#include<string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        bool ret = true;
        return matchCore(str,pattern);
    }
    bool matchCore(string str, string pattern){
        if(str[0]=='\0' && pattern[0] == '\0')    return true;
        if(str[0]!='\0' && pattern[0]=='\0')    return false;
        if(pattern[1]=='*'){
            if(pattern[0] == str[0] || (pattern[0] == '.' && str[0] != '\0')){
                return matchCore(str.substr(1), pattern.substr(2)) || /* *前面字符出现1次*/
                    matchCore(str.substr(1), pattern) || /* *前面字符出现2次*/
                    matchCore(str, pattern.substr(2));/* *前面字符出现0次*/
            }
            else{
                return matchCore(str, pattern.substr(2));
            }
        }
        if(pattern[0] == str[0] || (pattern[0] == '.' && str[0] != '\0'))
            return matchCore(str.substr(1), pattern.substr(1));
        return false;
    }
};