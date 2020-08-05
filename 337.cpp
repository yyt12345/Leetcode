/*
 * @Descripttion: 337. 打家劫舍 III
        在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 
        除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一
        棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
        计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-05 19:45:12
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-05 21:11:06
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// 执行用时：56 ms, 在所有 C++ 提交中击败了11.95% 的用户
// 内存消耗：29.5 MB, 在所有 C++ 提交中击败了31.40% 的用户
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};
class Solution {
private:
    map<TreeNode*, int> f, g;

public:
    void dfs(TreeNode* o)
    {
        if (!o)
            return;
        dfs(o->left);
        dfs(o->right);
        f[o] = o->val + g[o->left] + g[o->right];
        g[o] = max(f[o->left], g[o->right]) + max(f[o->right], g[o->right]);
    }
    int rob(TreeNode* o)
    {
        dfs(o);
        return max(f[o], g[o]);
    }
};