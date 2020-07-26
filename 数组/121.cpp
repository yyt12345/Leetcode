/*
 * @Descripttion: 121. 买卖股票的最佳时机
        给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
        如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
        注意：你不能在买入股票前卖出股票。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-04 17:50:08
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-04 18:16:06
 */ 
#include <vector>
#include <iostream>
using namespace std;
//  8 ms    88.01%      12.9 MB     6.56%
int maxProfit(vector<int>& prices) {
    if(prices.size()==0) return 0;
    int pre=prices[0],maxP=0;
    for(int i=1;i<prices.size();i++){
        pre=min(prices[i],pre);
        maxP=max(prices[i]-pre,maxP);
    }
    return maxP;
}
int main(){
    vector<int> prices={7,1,5,3,6,4};
    int res=maxProfit(prices);
    cout << res << endl;
}
