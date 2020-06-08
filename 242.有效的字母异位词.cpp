/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> df(('z' - 'a' + 1), 0);

        for (int i = 0; i < s.length(); i++)
        {
            df[(s[i] - 'a')] += 1;
        }
        for (int i = 0; i < t.length(); i++)
        {
            df[(t[i] - 'a')] -= 1;
        }
        for (int i = 0; i < df.size(); i++)
        {
            if (df[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
