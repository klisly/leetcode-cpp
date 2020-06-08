/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = nums[0];
        int cur_max = nums[0];
        int neg_max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int mx = cur_max, mn = neg_max;
            cur_max = max(mx * nums[i], max(nums[i], mn * nums[i]));
            neg_max = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(cur_max, ans);
        }
        return ans;
        // if (nums.size() == 1)
        // {
        //     return nums[0];
        // }

        // int global_max = nums[0];
        // int cur_max = nums[0];
        // int neg_max = nums[0];
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     cur_max = max(nums[i], cur_max * nums[i]);
        //     if (nums[i] == 0)
        //     {
        //         neg_max = 0;
        //     }
        //     else
        //     {
        //         neg_max *= nums[i];
        //         cur_max = max(cur_max, neg_max);
        //     }

        //     global_max = max(cur_max, global_max);
        // }
        // global_max = max(cur_max, global_max);
        // return global_max;
        // int maxF = nums[0], minF = nums[0], ans = nums[0];
        // for (int i = 1; i < nums.size(); ++i)
        // {
        //     int mx = maxF, mn = minF;
        //     maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        //     minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        //     ans = max(maxF, ans);
        // }
        // return ans;
    }
};
// @lc code=end
