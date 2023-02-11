class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int len = s.size();
        res.resize(len);

        int add_cur_i = numRows*2 - 2;
        if (add_cur_i == 0)
            add_cur_i = 1;
        int count = 0;
        for (int i =0; i < numRows; i++)
        {
            int cur_i = i;
            while(cur_i < len)
            {
                res[count] = s[cur_i];
                count += 1;

                if (cur_i + add_cur_i - i*2 < len && 
                cur_i % add_cur_i != 0 && (cur_i - numRows + 1) % add_cur_i != 0)
                {
                    res[count] = s[cur_i + add_cur_i - i*2];
                    count += 1;
                }

                cur_i += add_cur_i;
            }
        }

        return res;
    }
};