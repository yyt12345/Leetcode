/*** 
 * @Author: whh
 * @Date: 2020-12-14 13:07:32
 * @LastEditTime: 2020-12-16 10:44:03
 * @LastEditors: whh
 * @Description: 
 * @FilePath: /Leetcode/dependOn.h
 */
#ifndef _DEPENDON_H_
#define _DEPENDON_H_

#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr)
    {
    }

    Node(int _val)
        : val(_val)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr)
    {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {
    }
};
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
        : label(x)
        , next(NULL)
        , random(NULL)
    {
    }
};

#endif