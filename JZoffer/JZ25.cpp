/*** 
 * @Author: whh
 * @Date: 2020-12-16 10:42:52
 * @LastEditTime: 2020-12-17 11:33:32
 * @LastEditors: whh
 * @Description: 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。
 *      （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 * @FilePath: /Leetcode/JZ25.cpp
 */
#include "nowcoderds.h"
#include <map>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 首先遍历一遍链表，将next的一串链表复制。然后遍历第二遍链表，从复制的链表串中找到label相同的结点，并指向他
     */
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return nullptr;

        RandomListNode* q = pHead;
        RandomListNode* head = new RandomListNode(0);
        RandomListNode* p = head;
        while (q) {
            RandomListNode* tmp = new RandomListNode(q->label);
            p->next = tmp;
            q = q->next;
            p = p->next;
        }
        q = pHead;
        p = head->next;
        while (q) {
            if (q->random) {

                RandomListNode* tmp = head->next;
                int label = q->random->label;
                while (tmp != nullptr && tmp->label != label)
                    tmp = tmp->next;
                if (tmp)
                    p->random = tmp;
            }

            q = q->next;
            p = p->next;
        }
        return head->next;
    }
    /*** 
     * @description: 改进：用哈希表记录以生成的结点
     */
    RandomListNode* Clone2(RandomListNode* pHead)
    {
        if (!pHead)
            return nullptr;

        map<int, RandomListNode*> hash;

        RandomListNode* q = pHead;
        RandomListNode* head = new RandomListNode(pHead->label);
        RandomListNode* p = head;

        hash[head->label] = head;

        while (q) {
            if (q->next) {
                if (!hash.count(q->next->label)) {
                    hash[q->next->label] = new RandomListNode(q->next->label);
                }
                p->next = hash[q->next->label];
            } else
                p->next = nullptr;

            if (q->random) {
                if (!hash.count(q->random->label))
                    hash[q->random->label] = new RandomListNode(q->random->label);
                p->random = hash[q->random->label];
            } else
                p->random = nullptr;

            q = q->next;
            p = p->next;
        }
        return head;
    }
    /*** 
     * @description: 拼接+拆分
     */
    RandomListNode* Clone3(RandomListNode* pHead)
    {
        if (!pHead)
            return nullptr;
        RandomListNode* p = pHead;
        while (p) {
            RandomListNode* copy_node = new RandomListNode(p->label);
            copy_node->next = p->next;
            p->next = copy_node;
            p = copy_node->next;
        }
        p = pHead;
        while (p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        RandomListNode* res = pHead->next;
        RandomListNode* pre = pHead;
        p = pHead->next;
        while (p->next != nullptr) {
            pre->next = pre->next->next;
            p->next = p->next->next;

            pre = pre->next;
            p = p->next;
        }
        pre->next = nullptr;
        return res;
    }
};
int main()
{
    // { -1, 8, 7, -3,4, 4,-3,#,#,8}
    RandomListNode* rlnode1 = new RandomListNode(-1);
    RandomListNode* rlnode2 = new RandomListNode(8);
    RandomListNode* rlnode3 = new RandomListNode(7);
    RandomListNode* rlnode4 = new RandomListNode(-3);
    RandomListNode* rlnode5 = new RandomListNode(4);
    rlnode1->next = rlnode2;
    rlnode2->next = rlnode3;
    rlnode3->next = rlnode4;
    rlnode4->next = rlnode5;
    rlnode1->random = rlnode5;
    rlnode2->random = rlnode4;
    rlnode5->random = rlnode2;
    PrintRandomListNode(rlnode1);

    Solution s;
    RandomListNode* res = s.Clone3(rlnode1);
    PrintRandomListNode(res);
}