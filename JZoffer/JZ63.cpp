#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> nums;
    void Insert(int num)
    {
        //二分法
        int end = nums.size() - 1, start = 0;
        while (start <= end) {
            int mid = (start+end)>>1;
            if (nums[mid] > num) end = mid-1;
            else if (nums[mid] < num) start = mid + 1;
            else {
                start = mid;
                break;
            }
        }
        if (start == nums.size()) nums.push_back(num);
        else nums.insert(nums.begin() + start, num);
    }

    double GetMedian()
    {
        int n = nums.size();
        if (n % 2) return nums[n / 2];
        else return (nums[n / 2] + nums[n / 2 - 1]) / 1.0;
    }
// 使用优先队列
    priority_queue<int> a;//大顶堆
    priority_queue<int ,vector<int>, greater<int> > b;//小顶堆
    void Insert2(int num){
        a.push(num);

        b.push(a.top());
        a.pop();

        if(a.size()<b.size()){
            a.push(b.top());
            b.pop();
        }
    }
    double GetMedian2(){
        return a.size()>b.size()?a.top():(a.top()+b.top())*0.5;
    }

};
int main(){
    Solution s;
    vector<int> nums={5,2,3,4,1,6,7,0,8};
    for(int i=0;i<nums.size();i++ ){
        s.Insert2(nums[i]);
        cout << s.GetMedian2() << endl;
    }
}