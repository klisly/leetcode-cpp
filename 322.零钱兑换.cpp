/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> count;
    int dp(vector<int> &coins, int rem)
    {
        if (rem < 0)
        {
            return -1;
        }
        if (rem == 0)
        {
            return 0;
        }
        // 检查缓存
        if (count[rem - 1] != 0)
            return count[rem - 1];
        int min = INT_MAX;
        for (int coin : coins)
        {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < min)
            {
                min = res + 1;
            }
        }
        // 加入缓存
        count[rem - 1] = min == INT_MAX ? -1 : min;
        return count[rem - 1];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        // f(n) = min(f(n-ci)(i = 0->size -1)) + 1
        if (amount < 1)
        {
            return 0;
        }
        count.resize(amount);
        return dp(coins, amount);
    }
};
// @lc code=end
