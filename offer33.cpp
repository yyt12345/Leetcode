/*
 * @Descripttion: 剑指 Offer 33. 二叉搜索树的后序遍历序列
        输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
        如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-22 11:09:21
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-22 11:51:36
 */ 
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了60.50% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了100.00% 的用户
bool isBinTree(vector<int>& postorder,int start,int end){
    // if(postorder[start]>postorder[end]) return false;
    if(end-start<2) return true;
    
    int i;
    bool left=true,right=true;
    for(i=start;i<end;i++){
        if(postorder[i]>postorder[end]) break;
    }
    for(int j=start;j<i;j++){
        if(postorder[j]>postorder[end]) return false;
    }
    for(int j=i;j<end;j++){
        if(postorder[j]<postorder[end]) return false;
    }
    
    if(i==end)
        return isBinTree(postorder,start,i-1);
    else if(i==start)
        return isBinTree(postorder,i,end-1);
    else
        return isBinTree(postorder,start,i-1) && isBinTree(postorder,i,end-1);
}
bool verifyPostorder(vector<int>& postorder) {
    return isBinTree(postorder,0,postorder.size()-1);
}
int main(){
    vector<int> nums={1,2,3,4,5};
    cout << verifyPostorder(nums) << endl;
}