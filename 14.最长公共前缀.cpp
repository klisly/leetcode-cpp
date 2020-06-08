/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret = "";
        if (strs.size() > 0)
        {
            string old = strs[0];
            int csize = old.length();
            for (int i = 1; i < strs.size(); i++)
            {
                string cstr = strs[i];
                int j = 0;
                for (; j < cstr.length() && j < old.length(); j++)
                {
                    if (cstr[j] != old[j])
                    {
                        break;
                    }
                }
                csize = min(csize, j);
            }
            ret = old.substr(0,csize);
        }
        return ret;
    }
};
// @lc code=end
