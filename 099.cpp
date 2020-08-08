/*
 * @Descripttion: 99. 恢复二叉搜索树
        二叉搜索树中的两个节点被错误地交换。
        请在不改变其结构的情况下，恢复这棵树。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-08 10:10:23
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-08 10:33:09
 */
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
/*
    二叉搜索树的中序遍历，模板为
            void inorder(TreeNode* root){
                if(root==nullptr) return;
                inorder(root->left);
                //对当前节点的操作
                inorder(root->right);
            }
    对于中序遍历，结果为单调递增数组，若出现下降沿则表示当前接地错误。

*/
// 执行用时：64 ms, 在所有 C++ 提交中击败了5.55% 的用户
// 内存消耗：53.4 MB, 在所有 C++ 提交中击败了57.56% 的用户
TreeNode *t1, *t2, *pre;
void inorder(TreeNode* root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    if (pre != nullptr && pre->val > root->val) {
        if (t1 == nullptr)
            t1 = pre;
        t2 = root;
    }
    pre = root;
    inorder(root->right);
}
void recoverTree(TreeNode* root)
{
    inorder(root);
    swap(t1->val, t2->val);
}