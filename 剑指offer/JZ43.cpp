#include<string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        string res;
        for(int i=n-1;i<str.length();i++){
            res.push_back(str[i]);
        }
        for(int i=0;i<n;i++){
            res.push_back(str[i]);
        }
        str.length();
        return res;
    }
};