/**
 * @file solution.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26]={0};
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            hash[t[i] - 'a']--;
        }
        for(int i =0 ; i < 26; i++){
            if(hash[i] != 0)
                return false;
        }
            return true;
    }
};