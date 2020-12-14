/*** 
 * @Author: your name
 * @Date: 2020-12-14 13:52:40
 * @LastEditTime: 2020-12-14 14:31:45
 * @LastEditors: whh
 * @Description: 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 * @FilePath: /Leetcode/JZ02.cpp
 */
#include <string>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 返回值为void 原地赋值
     */
    void replaceSpace(char* str, int length)
    {
        if (str == nullptr || length <= 0)
            return;
        //遍历一遍，获得空格个数
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] != ' ')
                count++;
        }
        if (!count)
            return;
        //从右往左遍历
        int resLen = length + count * 2;
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[resLen--] = '0';
                str[resLen--] = '2';
                str[resLen--] = '%';
            } else
                str[resLen--] = str[i];
        }
    }
};
int main()
{
}