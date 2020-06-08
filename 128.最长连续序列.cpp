/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> numset;
        for (const int &num : nums)
        {
            numset.insert(num);
        }

        int longestStreak = 0;
        for (const int &num : numset)
        {
            if (!numset.count(num - 1))
            {
                int curNum = num;
                int curStreak = 1;
                while (numset.count(curNum + 1))
                {
                    curNum += 1;
                    curStreak += 1;
                }
                longestStreak = max(curStreak, longestStreak);
            }
        }
        return longestStreak;
        // // 有界范围才适用下述方法
        // if(nums.size() == 0){
        //     return 0;
        // }

        // long mn = nums[0];
        // long mx = nums[0];
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     mn = min(mn, (long)nums[i]);
        //     mx = max(mx, (long)nums[i]);
        // }
        // long arrs[mx - mn + 1];
        // for (int i = 0; i < mx - mn + 1; i++)
        // {
        //     arrs[i] = 0;
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     arrs[nums[i] - mn] = 1;
        // }
        // int ans = 0;
        // int size = 0;
        // for (int i = 0; i < mx - mn + 1; i++)
        // {
        //     if (arrs[i] != 0)
        //     {
        //         size += arrs[i];
        //     }
        //     else
        //     {
        //         ans = max(ans, size);
        //         size = 0;
        //     }
        // }
        // ans = max(ans, size);
        // return ans;
    }
};
// @lc code=end
