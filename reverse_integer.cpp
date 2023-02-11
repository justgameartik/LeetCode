class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return x;
        int new_x = 0;
        int sign = x / abs(x);
        x = abs(x);
        int int_max = std::numeric_limits<int>::max();
        int int_min = std::numeric_limits<int>::min();
        while(x > 0)
        {
            if (new_x > int_max / 10)
                return 0;
            new_x *= 10;

            int added_value = x % 10;
            if (new_x > int_max - added_value && sign > 0 || (-new_x) < (int_min + added_value) && sign < 0)
                return 0;
            new_x += added_value;
            x /= 10;
        }
        
        return new_x * sign;
    }
};