/*
 * @Author: your name
 * @Date: 2021-01-28 20:50:53
 * @LastEditTime: 2021-01-28 22:10:08
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 37. 序列化二叉树
 * 请实现两个函数，分别用来序列化和反序列化二叉树。
 * @FilePath: /offer2/37.cpp
 */
#include <iostream>
#include <queue>
#include <string>
#include "../dependOn.h"
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        res.push_back('{');

        if(!root) return "{}";
        queue<TreeNode*> q;
        q.push(root);
        int flag=true;
        while(flag && !q.empty()){
            int n=q.size();
            flag=false;
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp)
                    res+=to_string(tmp->val);
                else 
                    res.push_back('*');
                res.push_back(',');

                if(tmp){
                    q.push(tmp->left);
                    q.push(tmp->right);
                    if(tmp->left || tmp->right) flag=true;
                }
            }
        }
        res.push_back('}');
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data=data.substr(1,data.size()-2);
        queue<string> vec;
        for(int i=0,j=0;i<data.size() && j<data.size();j++){
            if(data[j]==','){
                string ss=data.substr(i,j-i);
                vec.push(ss);
                i=j+1;
            }
        }
        if(vec.size()==0) return nullptr;
        TreeNode* root=new TreeNode(stoi(vec.front()));
        vec.pop();
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && !vec.empty()){
            auto node=q.front();
            q.pop();
            string out=vec.front();
            vec.pop();

            if(out!="*"){
                node->left=new TreeNode(stoi(out));
                q.push(node->left);
            }
            if(vec.empty()) break;
            out=vec.front();
            vec.pop();
            if(out!="*"){
                node->right=new TreeNode(stoi(out));
                q.push(node->right);
            }
        }
        return root;
    }
};
int main(){
    vector<TreeNode*> t;
    for(int i=1;i<8;i++){
        t.push_back(new TreeNode(i));
    }
    t[0]->left=t[1];
    t[0]->right=t[2];
    t[1]->left=t[3];
    t[2]->left=t[5];
    t[2]->right=t[6];
    TreeNode* root=t[0];

    Codec c;
    string res1=c.serialize(root);
    TreeNode* res2=c.deserialize(res1);
    string res3=c.serialize(res2);
    cout << res1 << endl;
    cout << res2 << endl;
}