class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        int start_index = 0;
        int size = s.size();

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int l_ptr = i, r_ptr = i + j;
                while(l_ptr >=0 && r_ptr < size && s[l_ptr] == s[r_ptr])
                {
                    l_ptr -= 1;
                    r_ptr += 1;
                }
                if (r_ptr - l_ptr - 2 + 1 > max_len)
                {
                    max_len = r_ptr - l_ptr - 2 + 1;
                    start_index = l_ptr + 1;
                }
            }
        }

        string res;
        res.resize(max_len);
        for (int i = 0; i < max_len; i++)
            res[i] = s[start_index + i];

        return res;
    }
};