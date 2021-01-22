#include "dependOn.h"
#include <quene>
#include <vector>
using namespace std;
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(!pRoot) return res;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int n=q.size();
                vector<int> tmp;
                for(int i=0;i<n;i++){
                    TreeNode* s=q.front();
                    q.pop();
                    tmp.push_back(s->val);
                    if(s->left) q.push(s->left);
                    if(s->right) q.push(s->right);
                }
                res.push_back(tmp);
            }
            return res;
        }
};

