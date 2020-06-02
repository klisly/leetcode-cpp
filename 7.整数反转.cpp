/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <cmath>

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        const int maxint = 0x7fffffff;
        const int minint = 0x80000000;
        long long ans = 0;
       
        long long fx = fabs(long(x));
        while (fx != 0)
        {
            ans = ans * 10 + fx % 10;
            fx /= 10;
        }
        if(ans > maxint){
            return 0;
        }
        if (x < 0)
        {
            return -ans;
        }
        else
        {
            return ans;
        }
    }
};
// @lc code=end
