/**
 * @file solution.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include<unordered_set>

class Solution {
public:
    //计算每个位置的平方和
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10)*(n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> sumSet;
        while(1){
            int sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(sumSet.find(sum) != sumSet.end()){//查看结果是否重复，如果得到重复结果，则说明不是快乐数。
                return false;
            }else
                sumSet.insert(sum);
            n=sum;
        }
    }
};