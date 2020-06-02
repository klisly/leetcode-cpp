/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include "math.h"
// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int begin = 0, end = x;
        int ans;
        while (begin <= end)
        {
            int mid = (end + begin) / 2;
            long res = long(mid) * long(mid);
            if (res > x)
            {
                end = mid - 1;
            }
            else if (res < x)
            {
                ans = mid;
                begin = mid + 1;
            }
            else if (res == x)
            {
                ans = mid;
                break;
            }

            mid = (begin + end) / 2;
        }

        return ans;
    }
};
// @lc code=end
