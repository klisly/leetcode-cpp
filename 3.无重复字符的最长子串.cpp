/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include "string"
#include "unordered_map"
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int mx = 0;
        int left = 0;
        // 找到左界右界的极限
        for (int i = 0; i < s.length(); i++)
        {
            if (map.count(s[i]))
            {
                left = max(left, map[s[i]] + 1);
            }
            map[s[i]] = i;
            mx = max(mx, i - left + 1);
        }
        return mx;
    }
};
// @lc code=end
