#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

void PrintTree(TreeNode* root)
{
    if (root == NULL) {
        printf("%s", "{}");
        return;
    }
    printf("%s", "{");
    vector<TreeNode*> v;
    if (root != NULL) {
        v.push_back(root);
    }
    size_t c = 0;
    string none;
    while (c < v.size()) {
        if (c == 0) {
            printf("%d", v[c]->val);
            v.push_back(v[c]->left);
            v.push_back(v[c]->right);
        } else {
            if (v[c] == NULL) {
                none.append(",#");
            } else {
                printf("%s,%d", none.c_str(), v[c]->val);
                none.clear();
                v.push_back(v[c]->left);
                v.push_back(v[c]->right);
            }
        }
        ++c;
    }
    printf("%s", "}\n");
}

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }
};
void PrintTreeLinkNode(TreeLinkNode* root)
{
    if (root == NULL) {
        printf("%s", "{}");
        return;
    }
    printf("%s", "{[");
    vector<TreeLinkNode*> v;
    vector<TreeLinkNode*> label_node_v;
    if (root != NULL) {
        v.push_back(root);
        label_node_v.push_back(root);
    }
    size_t c = 0;
    string none;
    while (c < v.size()) {
        if (c == 0) {
            printf("%d", v[c]->val);
            v.push_back(v[c]->left);
            v.push_back(v[c]->right);
        } else {
            if (v[c] == NULL) {
                none.append(",#");
            } else {
                label_node_v.push_back(v[c]);
                printf("%s,%d", none.c_str(), v[c]->val);
                none.clear();
                v.push_back(v[c]->left);
                v.push_back(v[c]->right);
            }
        }
        ++c;
    }
    v.clear();
    printf("%s", "],[");
    for (size_t i = 0; i < label_node_v.size(); ++i) {
        if (i != 0) {
            printf("%s", ",");
        }
        if (label_node_v[i]->next != NULL) {
            // 注意：这里的link是根据节点的指来索引的，所以这种数据结构每个节点的val要唯一
            printf("%d", label_node_v[i]->next->val);
        } else {
            printf("%s", "#");
        }
    }
    printf("%s", "]}");
}

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

void PrintRandomListNode(RandomListNode* head)
{
    if (head == NULL) {
        printf("%s", "{}");
        return;
    }
    RandomListNode* current = head;
    printf("%s", "{");
    while (current != NULL) {
        if (current == head) {
            printf("%d", current->label);
        } else {
            printf(",%d", current->label);
        }
        current = current->next;
    }
    current = head;
    while (current != NULL) {
        if (current->random != NULL) {
            printf(",%d", current->random->label);
        } else {
            printf("%s", ",#");
        }
        current = current->next;
    }
    printf("%s", "}");
}

struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x)
        : label(x)
    {
    }
};

void PrintUndirectedGraphNode(UndirectedGraphNode* root)
{
    if (root == NULL) {
        printf("%s", "{}");
        return;
    }
    printf("%s", "{");
    if (root != NULL) {
        set<UndirectedGraphNode*> nodes_set;
        map<int, UndirectedGraphNode*> nodes_map;
        vector<UndirectedGraphNode*> nodes;
        nodes.push_back(root);
        nodes_set.insert(root);
        nodes_map[root->label] = root;
        for (size_t i = 0; i < nodes.size(); ++i) {
            for (size_t j = 0; j < nodes[i]->neighbors.size(); ++j) {
                UndirectedGraphNode* n_node = nodes[i]->neighbors[j];
                if (nodes_set.find(n_node) == nodes_set.end()) {
                    nodes_set.insert(n_node);
                    nodes.push_back(n_node);
                    nodes_map[n_node->label] = n_node;
                }
            }
        }

        // map的key从小到大，逐个输出节点
        for (map<int, UndirectedGraphNode*>::iterator it = nodes_map.begin();
             it != nodes_map.end(); ++it) {
            UndirectedGraphNode* node = it->second;
            if (it != nodes_map.begin()) {
                printf(",[%d", node->label);
            } else {
                printf("[%d", node->label);
            }
            for (size_t j = 0; j < node->neighbors.size(); ++j) {
                printf(",%d", node->neighbors[j]->label);
            }
            printf("%s", "]");
        }
    }
    printf("%s", "}");
}

// int main()
// {
//     // {1,2,3,#,#,4,#,#,5}
//     TreeNode* node1 = new TreeNode(1);
//     TreeNode* node2 = new TreeNode(2);
//     TreeNode* node3 = new TreeNode(3);
//     TreeNode* node4 = new TreeNode(4);
//     TreeNode* node5 = new TreeNode(5);
//     node1->left = node2;
//     node1->right = node3;
//     node3->left = node4;
//     node4->right = node5;
//     PrintTree(node1);
//     printf("\n");

//     // {[1,2,3,#,#,4,#,#,5],[#,3,#,#,#]}
//     TreeLinkNode* tlnode1 = new TreeLinkNode(1);
//     TreeLinkNode* tlnode2 = new TreeLinkNode(2);
//     TreeLinkNode* tlnode3 = new TreeLinkNode(3);
//     TreeLinkNode* tlnode4 = new TreeLinkNode(4);
//     TreeLinkNode* tlnode5 = new TreeLinkNode(5);
//     tlnode1->left = tlnode2;
//     tlnode1->right = tlnode3;
//     tlnode3->left = tlnode4;
//     tlnode4->right = tlnode5;
//     tlnode2->next = tlnode3;
//     PrintTreeLinkNode(tlnode1);
//     printf("\n");

//     // { -1, 8, 7, -3,4, 4,-3,#,#,8}
//     RandomListNode* rlnode1 = new RandomListNode(-1);
//     RandomListNode* rlnode2 = new RandomListNode(8);
//     RandomListNode* rlnode3 = new RandomListNode(7);
//     RandomListNode* rlnode4 = new RandomListNode(-3);
//     RandomListNode* rlnode5 = new RandomListNode(4);
//     rlnode1->next = rlnode2;
//     rlnode2->next = rlnode3;
//     rlnode3->next = rlnode4;
//     rlnode4->next = rlnode5;
//     rlnode1->random = rlnode5;
//     rlnode2->random = rlnode4;
//     rlnode5->random = rlnode2;
//     PrintRandomListNode(rlnode1);
//     printf("\n");

//     //{[0,1],[1,2],[2,2]}
//     UndirectedGraphNode* ugn1 = new UndirectedGraphNode(0);
//     UndirectedGraphNode* ugn2 = new UndirectedGraphNode(1);
//     UndirectedGraphNode* ugn3 = new UndirectedGraphNode(2);
//     ugn1->neighbors.push_back(ugn2);
//     ugn2->neighbors.push_back(ugn3);
//     ugn3->neighbors.push_back(ugn3);
//     PrintUndirectedGraphNode(ugn1);
//     return 0;
// }
