/*
 * @Author: your name
 * @Date: 2021-01-27 20:59:39
 * @LastEditTime: 2021-01-27 21:57:36
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 33. 二叉搜索树的后序遍历序列
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
 * 假设输入的数组的任意两个数字都互不相同
 * @FilePath: /offer2/33.cpp
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    //递归分治
    bool recur(vector<int>& postorder,int start,int end){
        if(end-start<3) return true;
        
        int root=postorder[end];
        int i=start;
        while(postorder[i]<root) i++;
        int line=i;
        for(;i<end;i++){
            if(postorder[i]<root) return false;
        }
        return recur(postorder,start,line-1) && recur(postorder,line,end-1);
    }
    bool verifyPostorder2(vector<int>& postorder) {
        if(postorder.size()==0) return true;
        return recur(postorder,0,postorder.size()-1);
    }
    //辅助单调栈
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0) return true;
        stack<int> s;
        int root=INT_MAX;
        for(int i=postorder.size()-1;i>=0;i--){
            if(postorder[i]>root) return false;
            while(!s.empty() && postorder[i]<s.top()) {
                root=s.top();
                s.pop();
            }
            s.push(postorder[i]);
        }
        return true;
    }
};
int main(){
    vector<int> nums={179, 437, 1405, 5227, 8060, 8764, 8248, 4687, 3297, 13038, 12691, 15744, 16195, 15642, 19813, 17128, 21051, 20707, 22177, 21944, 23644, 23281, 19970, 23652, 26471, 31467, 33810, 32300, 33880, 27334, 25987, 35643, 35103, 36489, 42534, 42990, 42942, 37090, 36075, 34516, 16624, 11335, 10737, 44641, 45754, 47096, 46021, 49150, 48013, 49814, 51545, 52555, 50701, 47875, 56783, 57558, 53812, 62008, 61737, 63052, 63478, 62799, 59246, 64765, 64066, 63862, 65384, 67449, 66552, 57741, 45618, 44412, 667, 69718, 75519, 76819, 72971, 79319, 78145, 80615, 84280, 80984, 86598, 85903, 84334, 80867, 87993, 92361, 88465, 87738, 80364, 94380, 94446, 96785, 93694, 76847, 99655, 98675, 97001, 72112};
    Solution s;
    cout << s.verifyPostorder(nums) << endl;
}