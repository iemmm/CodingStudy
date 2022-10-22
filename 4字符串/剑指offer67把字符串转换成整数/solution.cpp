/**
 * @file solution.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

 

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include<iostream>
#include<String>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int size = str.size();
        int result =0;
        enum FLAG {POSITIVE, NEGITIVE};
        FLAG flag = POSITIVE;
        int i = 0;
        //遍历字符串至第一个非空字符
        for(i; i < str.size(); i++){
            if(str[i] != ' ') break;
        }
        //如果第一个非空字符不能与数字无关直接return0
        if(str[i] != '-' && (str[i] < 48 || str[i] >=58) && str[i] != '+') return 0;
        //第一个非空字符为‘-’
        if(str[i] == '-') flag = NEGITIVE;
        //第一个非空字符为‘+’和‘-’，是直接将指针下移一位
        if(flag == NEGITIVE || str[i] == '+') i++;
        //开始转换
        for(int  j = i; j < str.size(); j++){
            if(str[j] > 47 && str[j] < 58) { 
                if(result > 214748364) return (flag == NEGITIVE ? INT_MAX * (-1) - 1 : INT_MAX);
                else if(result == 214748364){
                    if(str[j]-'0'>7) return (flag == NEGITIVE ? INT_MAX * (-1) - 1 : INT_MAX);
                    else {
                        result = result * 10 + (str[j] -'0');
                        return (flag == NEGITIVE ? result * (-1) : result);
                    }

                }
                else result = result * 10 + str[j] - '0';
                
            }
            else break;
        } 
        return (flag == NEGITIVE ? result * (-1) : result);
    }
        
};

int main(){
    string test = {' ', ' ', '-', '4', '2'};
    string test1 = "world and 890";
    string test2 = "42";
    string test3 = "-91283472332";
    string test4 = "2147483646";
    int res = Solution().strToInt(test4);
    cout << res;
}
