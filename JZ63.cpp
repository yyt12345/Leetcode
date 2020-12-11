#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> nums;
    void Insert(int num)
    {
        //二分法插入
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
};
