#include <vector>
using namespace::std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        vector<int> digits;
        while(x > 0)
        {
            digits.push_back(x%10);
            x /= 10;
        }

        int ptr_1 = 0, ptr_2 = digits.size() - 1;
        bool res = true;
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[ptr_1 + i] != digits[ptr_2 - i])
            {
                res = false;
                break;
            }
        }

        return res;
    }
};