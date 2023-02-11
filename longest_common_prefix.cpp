class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        
        for (int i = 0; i < strs[0].size(); i++)
        {
            bool append = true;
            char cur_letter = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != cur_letter)
                {
                    append = false;
                    break;
                }
            }
            if (append)
                result.push_back(cur_letter);
            else
                return result;
        }

        return result;
    }
};