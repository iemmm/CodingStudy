/**
 * @file solution.cpp
 * @author Jialing Chen (chenjialing333@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
    本题是翻转字符串，用的是双指针，之前做过的翻转链表更复杂，也是使用双指针的方式。
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int left = 0;
        int  right = size - 1;
        int temp = 0;
        while (left < right){
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

int main(){
    vector<char> test = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};
    Solution a;
    a.reverseString(test);
    for(int i = 0; i < test.size(); i++){
        cout << test[i]<< " ";
    }
    return 0;
}