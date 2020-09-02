/*
 * @Descripttion: 剑指 Offer 20. 表示数值的字符串
        请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-02 08:47:53
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-02 09:58:08
 */
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char ch)
    {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else if (ch == ' ') {
            return CHAR_SPACE;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s)
    {
        unordered_map<State, unordered_map<CharType, State>> transfer {
            { STATE_INITIAL, {
                                 { CHAR_SPACE, STATE_INITIAL },
                                 { CHAR_NUMBER, STATE_INTEGER },
                                 { CHAR_POINT, STATE_POINT_WITHOUT_INT },
                                 { CHAR_SIGN, STATE_INT_SIGN },
                             } },
            { STATE_INT_SIGN, {
                                  { CHAR_NUMBER, STATE_INTEGER },
                                  { CHAR_POINT, STATE_POINT_WITHOUT_INT },
                              } },
            { STATE_INTEGER, {
                                 { CHAR_NUMBER, STATE_INTEGER },
                                 { CHAR_EXP, STATE_EXP },
                                 { CHAR_POINT, STATE_POINT },
                                 { CHAR_SPACE, STATE_END },
                             } },
            { STATE_POINT, {
                               { CHAR_NUMBER, STATE_FRACTION },
                               { CHAR_EXP, STATE_EXP },
                               { CHAR_SPACE, STATE_END },
                           } },
            { STATE_POINT_WITHOUT_INT, {
                                           { CHAR_NUMBER, STATE_FRACTION },
                                       } },
            { STATE_FRACTION, {
                                  { CHAR_NUMBER, STATE_FRACTION },
                                  { CHAR_EXP, STATE_EXP },
                                  { CHAR_SPACE, STATE_END },
                              } },
            { STATE_EXP, {
                             { CHAR_NUMBER, STATE_EXP_NUMBER },
                             { CHAR_SIGN, STATE_EXP_SIGN },
                         } },
            { STATE_EXP_SIGN, {
                                  { CHAR_NUMBER, STATE_EXP_NUMBER },
                              } },
            { STATE_EXP_NUMBER, {
                                    { CHAR_NUMBER, STATE_EXP_NUMBER },
                                    { CHAR_SPACE, STATE_END },
                                } },
            { STATE_END, {
                             { CHAR_SPACE, STATE_END },
                         } }
        };

        int len = s.size();
        State st = STATE_INITIAL;
        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};

int main()
{
    Solution s;
    std::cout << s.isNumber("-3.14e1.10") << std::endl;
}