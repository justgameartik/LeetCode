#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace::std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<multiset<int>> res_set;

        unordered_map<int, int> numbers;
        for (int i = 0; i < nums.size(); i++)
            numbers[nums[i]] += 1;

        unordered_map<int,int>::iterator it = numbers.begin();
        for (it; it != numbers.end(); it++)
        {
            unordered_map<int, int>::iterator it_2 = it;
            if (it->second == 1)
                it_2++;

            for (it_2; it_2 != numbers.end(); it_2++)
            {
                unordered_map<int, int>::iterator it_3 = 
                    numbers.find(-it->first - it_2->first); 
                
                if (it_3 != numbers.end())
                {
                    if (it_3 != it_2 && it_3 != it)
                    {
                        multiset<int> temp_set;
                        temp_set.insert(it->first);
                        temp_set.insert(it_2->first);
                        temp_set.insert(it_3->first);

                        res_set.insert(temp_set);
                    }
                    else
                        if ( (it_3 == it && it_3 != it_2 ||
                            it_3 == it_2 && it_3 != it) && it_3->second > 1)
                        {
                            multiset<int> temp_set;
                            temp_set.insert(it->first);
                            temp_set.insert(it_2->first);
                            temp_set.insert(it_3->first);

                            res_set.insert(temp_set);
                        }
                        else
                            if (it_3 == it && it_3 == it_2 && it->second > 2)
                            {
                                multiset<int> temp_set;
                                temp_set.insert(it->first);
                                temp_set.insert(it_2->first);
                                temp_set.insert(it_3->first);

                                res_set.insert(temp_set);
                            }

                }
            }
        }
        set<multiset<int>>::iterator set_it = res_set.begin();
        for (set_it; set_it != res_set.end(); set_it++)
        {
            vector<int> temp;
            multiset<int>::iterator set_it_2 = (*set_it).begin();
            for (set_it_2; set_it_2 != (*set_it).end(); set_it_2++)
            {
                temp.push_back(*set_it_2);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> arr = {-2,0,1,1,2};
    vector<vector<int>> res = a.threeSum(arr);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}