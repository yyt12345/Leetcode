class Solution {
public:
//存在三种情况
//1、右边有结点 则找出右边树中最左的结点，即右孩子结点的最左孩子结点,如果右孩子结点没有左孩子就是自己
//2、右边无结点 则往根结点找 知道当前结点是父亲结点的左孩子
//3、不满足以上情况，为尾结点 返回nulllptr
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        
        if(!pNode) return pNode;
        if(pNode->right) {
            pNode=pNode->right;
            while(pNode->left) pNode=pNode->left;
            return pNode;
        }
        while(pNode->next){
            TreeLinkNode* root=pNode->next;
            if(root->left==pNode) return root;
            pNode=pNode->next;
        }
        return nullptr;
    }
};
