/*
 * @Descripttion: 94. 二叉树的中序遍历
        给定一个二叉树，返回它的中序 遍历。
        进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-01 10:47:07
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-01 13:47:46
 */
#include <stack>
#include <vector>
using std::stack;
using std::vector;
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
    vector<int> res;

public:
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：7.3 MB, 在所有 C++ 提交中击败了34.80% 的用户
    void func(TreeNode* root)
    {
        if (root == nullptr)
            return;
        func(root->left);
        res.push_back(root->val);
        func(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        func(root);
        return res;
    }
    // 执行用时：4 ms, 在所有 C++ 提交中击败了45.99% 的用户
    // 内存消耗：7.5 MB, 在所有 C++ 提交中击败了11.25% 的用户
    vector<int> inorderTraversal2(TreeNode* root)
    {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* curr = root;
        while (curr != nullptr && !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top;
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }
};
int main()
{
}