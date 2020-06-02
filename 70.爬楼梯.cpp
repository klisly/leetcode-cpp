/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int l1 = 1;
        int l2 = 2;
        for(int i = 3; i <=n; i++){
            int tmp = l1 + l2;
            l1 = l2;
            l2 = tmp;   
        }
        return l2;
    }
};
// @lc code=end
