/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <cmath>

class Solution
{
public:
    // 倍增法、快速幂 x^y = (x^y/2) * (x^y/2)
    // log(n) 算法复杂度
    // 矩阵乘法快速幂 
    double myPow(double x, int n)
    {

        if (n == 0)
        {
            return 1;
        }
        bool isNeg = false;
        if (n < 0)
        {
            isNeg = true;
        }
        double base = 1;
        if (isNeg)
        {
            base *= x;
            n += 1;
        }
        n = int(fabs(n));
        double hp = myPow(x, n / 2);
        double res = 0.0;
        if (n % 2 == 0)
        {
            res = hp * hp;
        }
        else
        {
            res = x * hp * hp;
        }

        if (isNeg)
        {
            return 1 / (res * base);
        }
        else
        {
            return (res * base);
        }
    }
};
// @lc code=end
