class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> values;
        for (int i = 0; i < nums.size(); i++)
            values[nums[i]].push_back(i);
        vector<int> result(2, -1);
        for (int i = 0; i <nums.size(); i++)
        {
            if (values.find(target - nums[i]) != values.end())
            {
                for (int j = 0; j < values[target - nums[i]].size(); j++)
                    if (values[target-nums[i]][j] == i)
                        continue;
                    else
                    {
                        result[0] = i;
                        result[1] = values[target - nums[i]][j];
                        return result;
                    }
            }
        }
        return result;
    }
};