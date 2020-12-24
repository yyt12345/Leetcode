/*** 
 * @Author: whh
 * @Date: 2020-12-22 10:47:50
 * @LastEditTime: 2020-12-24 10:43:51
 * @LastEditors: whh
 * @Description: 总结并实现八大排序算法
 * @FilePath: /Leetcode/sort.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
class Algorithm {
public:
    /*** 
     * @description:插入排序 
     */
    void InsertSort(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); i++) {
            int key = nums[i];
            int j = i - 1;
            while ((j >= 0) && (key < nums[j])) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }
    /*** 
     * @description: dk 缩小增量
     */
    void ShellInsertSort_my(vector<int>& nums)
    {
        int length = nums.size();
        int k = length / 2;
        while (k >= 1) {
            for (int i = 0; i < k; i++) {
                for (int j = k + i; j < length; j += k) {
                    int key = nums[j];
                    int z = j - 1;
                    while ((z >= 0) && (key < nums[z])) {
                        nums[z + k] = nums[z];
                        z -= k;
                    }
                    nums[z + k] = key;
                }
            }
            k /= 2;
        }
    }
    void ShellInsertSort(vector<int>& nums)
    {
        int length = nums.size();
        int k = nums.size() / 2;
        while (k >= 1) {
            for (int i = k; i < length; i++) {
                int key = nums[i];
                int j = i - k;
                for (; j >= 0 && (key < nums[j]); j -= k)
                    nums[j + k] = nums[j];
                nums[j + k] = key;
            }
            k /= 2;
        }
    }
    /*** 
     * @description:选择排序 
     */
    void SelectSort(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++) {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[min] > nums[j])
                    min = j;
            }
            swap(nums[i], nums[min]);
        }
    }
    /*** 
     * @description: 堆排序
     */
    void HeapSort(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = (n - 1) / 2; i >= 0; i--) { //从最后一个非叶子结点开始
            downAdjust(nums, i, n - 1);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            downAdjust(nums, 0, i - 1);
        }
    }
    void downAdjust(vector<int>& arrs, int root, int n)
    {
        if (n <= 0)
            return;
        int child = 2 * root + 1;
        while (child <= n) {
            if (child < n && arrs[child + 1] > arrs[child])
                child++;
            if (arrs[child] <= arrs[root])
                return;

            swap(arrs[root], arrs[child]);
            root = child;
            child = 2 * root + 1;
        }
    }
    /*** 
     * @description: 冒泡排序
     */
    void BubbleSort(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }
    }
    /*** 
     * @description: 快速排序
     */
    int partition(vector<int>& arrs, int start, int end)
    {
        int pivot = arrs[start];
        int i = start + 1, j = end;
        while (true) {
            while (i <= j && arrs[i] <= pivot)
                i++;
            while (i <= j && arrs[j] >= pivot)
                j--;
            if (i >= j)
                break;
            swap(arrs[i], arrs[j]);
        }
        arrs[start] = arrs[j];
        arrs[j] = pivot;
        return j;
    }
    void QuickSort(vector<int>& arrs, int start, int end)
    {
        if (start < end) {
            int pivot = partition(arrs, start, end);
            QuickSort(arrs, start, pivot - 1);
            QuickSort(arrs, pivot + 1, end);
        }
    }
    /*** 
     * @description: 并归排序
     */
    void MergeSort(vector<int>& arrs, int start, int end)
    {
        if (start < end) {
        }
    }
    void merge(vector<int>& arrs, int start, int end)
    {
        vector<int> res(end - start + 1);
    }
};
int main()
{
    Algorithm a;

    vector<int> nums = { 3, 1, 5, 7, 2, 4, 9, 6 };
    cout << "插入排序： ";
    a.InsertSort(nums);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    vector<int> nums2 = { 3, 1, 5, 7, 2, 4, 9, 6 };
    cout << "希尔排序： ";
    a.ShellInsertSort(nums2);
    for (auto n : nums2)
        cout << n << " ";
    cout << endl;

    vector<int> nums3 = { 3, 1, 5, 7, 2, 4, 9, 6 };
    cout << "选择排序： ";
    a.SelectSort(nums3);
    for (auto n : nums3)
        cout << n << " ";
    cout << endl;

    nums = { 3, 1, 5, 7, 2, 4, 9, 6 };
    cout << "堆排序：   ";
    a.HeapSort(nums);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    nums = { 3, 1, 5, 7, 2, 4, 9, 6 };
    cout << "冒泡排序： ";
    a.BubbleSort(nums);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    nums = { 3, 1, 5, 7, 2, 4, 9, 6 };
    cout << "快速排序： ";
    a.QuickSort(nums, 0, nums.size() - 1);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
}