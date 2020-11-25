/*** 
 * @Date: 2020-11-23 10:24:50
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-25 10:39:44
 * @FilePath: /Leetcode/JZ53.cpp
 * @Reference: 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
#include <cctype>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 状态机
     * @param : 
     * @return {*}
     */
    enum STATE {
        START = 0,
        FLAG1 = 1,
        NUM1 = 2,
        POINT = 3,
        NUM2 = 4,
        E = 5,
        FLAG2 = 6,
        NUM3 = 7,
        END = 8
    };
    bool isNumeric(char* string)
    {
        STATE state = START;
        char* q = string;
        while (*q) {
            switch (state) {
            case START:
                if (*q == '+' || *q == '-') {
                    state = FLAG1;
                    break;
                } else if (isdigit(*q)) {
                    state = NUM1;
                    break;
                } else {
                    state = END;
                    break;
                }
            case FLAG1:
                if (isdigit(*q)) {
                    state = NUM1;
                    break;
                } else if (*q == '.') {
                    state = POINT;
                    break;
                } else {
                    state = END;
                    break;
                }
            case NUM1:
                if (isdigit(*q))
                    break;
                else if (*q == '.') {
                    state = POINT;
                    break;
                } else if (*q == 'E' || *q == 'e') {
                    state = E;
                    break;
                } else {
                    state = END;
                    break;
                }
            case POINT:
                if (isdigit(*q)) {
                    state = NUM2;
                    break;
                } else {
                    state = END;
                    break;
                }
            case NUM2:
                if (isdigit(*q))
                    break;
                else if (*q == 'e' || *q == 'E') {
                    state = E;
                    break;
                } else {
                    state = END;
                    break;
                }
            case E:
                if (*q == '-' || *q == '+') {
                    state = FLAG2;
                    break;
                } else if (isdigit(*q)) {
                    state = NUM3;
                    break;
                } else {
                    state = END;
                    break;
                }
            case FLAG2:
                if (isdigit(*q)) {
                    state = NUM3;
                    break;
                } else {
                    state = END;
                    break;
                }
            case NUM3:
                if (isdigit(*q))
                    break;
                else {
                    state = END;
                    break;
                }
            }
            if (state == END)
                break;
            q++;
        }
        if (*q == '\0' && (state == NUM1 || state == NUM2 || state == NUM3)) {
            return true;
        } else
            return false;
    }
};
int main()
{
    char string[10] = "1+23";
    Solution s;
    cout << s.isNumeric(string) << endl;
}