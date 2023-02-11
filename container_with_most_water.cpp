class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int ptr_1 = 0, ptr_2 = height.size() - 1;
        
        while(ptr_1 < ptr_2)
        {
            int h1 = height[ptr_1], h2 = height[ptr_2];
            int cur_s = min(h1, h2) * (ptr_2 - ptr_1);
            res = max(res, cur_s);

            if (h1 < h2)
                ptr_1 += 1;
            else
            {
                if (h1 > h2)
                    ptr_2 -= 1;
                else
                {
                    if (height[ptr_1 + 1] > height[ptr_2 - 1])
                        ptr_1 += 1;
                    else
                        ptr_2 -= 1;
                }
            }
        }
        return res;
    }
};