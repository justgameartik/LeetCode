class Solution {
public:
    int myAtoi(string s) {
        int result=0;
        int sign = 0;
        
        int ptr = 0;
        while(s[ptr] == ' ')
            ptr += 1;

        if (s[ptr] == '-')
            sign = -1;

        if (s[ptr] == '-' || s[ptr] == '+')
            ptr += 1;

        while(s[ptr] - '0' >= 0 && s[ptr] - '0' < 10)
        {
            int cur_digit = s[ptr] - '0';
            if (result < INT_MAX / 10 && result > INT_MIN/10 || 
                result == INT_MAX/10*(2*sign+1) && cur_digit <= 7 - sign)
            {
                result = result * 10 + (2*sign + 1)*cur_digit;
            }
            else
            {
                if (sign == 0)
                    result = INT_MAX;
                else
                {
                    result = INT_MIN;
                    sign = 0;
                }
                break;
            }
            ptr += 1;
        }

        return result;
    }
};