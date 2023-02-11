class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 1 2 3 1 5 6 3 4
        unordered_map<char, int> last_meet;
        int beg_i = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (last_meet.find(s[i]) == last_meet.end())
                last_meet[s[i]] = 0;
            
            beg_i = max(last_meet[s[i]], beg_i);
            res = max(res, i - beg_i + 1);
            last_meet[s[i]] = i + 1;
        }
        return res;
    }
};