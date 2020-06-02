/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */
#include "vector"
using namespace std;
// @lc code=start
class Solution
{
public:
    bool guess(long max, vector<int> &nums, long m)
    {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((sum + nums[i]) <= max)
            {
                sum = sum + nums[i];
            }
            else
            {
                --m;
                sum = nums[i];
                if(sum > max){
                    return false;
                }
            }
        }
        return m >= 1;
    }
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        long r = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            r += nums[i];
        }
        long l = 0;
        long ans = 0;
        while (l < r)
        {
            long mid = (l + r) / 2;
            if (guess(mid, nums, m))
            {
                ans = mid;
                r = mid ;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
