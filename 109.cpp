/*
 * @Descripttion: 109. 有序链表转换二叉搜索树
        给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
        本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-18 09:47:39
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-18 10:33:33
 */
#include <iostream>
#include <vector>
using std::vector;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
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

class Solution {
    vector<int> arr;

public:
    // 执行用时：52 ms, 在所有 C++ 提交中击败了39.28% 的用户
    // 内存消耗：24.6 MB, 在所有 C++ 提交中击败了100.00% 的用户
    TreeNode* buildTree(int start, int end)
    {
        if (start == end)
            return new TreeNode(arr[start]);
        else if (start > end)
            return nullptr;
        int mid = (start + end) >> 1;
        TreeNode* right = buildTree(mid + 1, end);
        TreeNode* left = buildTree(start, mid - 1);
        return new TreeNode(arr[mid], left, right);
    }
    // 执行用时：32 ms, 在所有 C++ 提交中击败了99.34% 的用户
    // 内存消耗：24.5 MB, 在所有 C++ 提交中击败了100.00% 的用户
    TreeNode* buildTree(int start, int end)
    {
        if (start == end)
            return new TreeNode(arr[start]);
        else if (start > end)
            return nullptr;
        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(arr[mid]);

        root->right = buildTree(mid + 1, end);
        root->left = buildTree(start, mid - 1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode* p = head;
        while (p != nullptr) {
            arr.push_back(p->val);
            p = p->next;
        }
        return buildTree(0, arr.size() - 1);
    }
};