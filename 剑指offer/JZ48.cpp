#include<vector>
using namespace std;
class Solution {
public:

    int Add(int num1, int num2)
    {
        return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
    }
};
