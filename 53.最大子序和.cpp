/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int global_max = nums[0];
        int cur_max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // cur_max + nums[i] ? nums[i] ? cur_max
            // 判断是不是跟前面的连续 
            /**
             * f(i)=max{f(i−1)+ai,ai​	
             * */
            if (cur_max + nums[i] > nums[i])
            {
                cur_max = cur_max + nums[i];
            }
            else
            {
                cur_max = nums[i];
            }
            global_max = max(cur_max, global_max);
        }
        return global_max;
    }
};
// @lc code=end
