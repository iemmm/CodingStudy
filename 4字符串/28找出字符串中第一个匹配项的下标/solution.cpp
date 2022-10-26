/*
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle
 * 不是 haystack 的一部分，则返回  -1 。
 * 这是一个标准的KMP算法的题目
 * 可以用暴力解法做，时间复杂度为O(m*n);
 * 用KMP算法做时间复杂度为O(m+n);
 * */
//暴力解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        //如果haystack的长度小于needle直接返回-1
        if(haystack.size() < needle.size()) return -1;
        //遍历haystack如果haystack[i]跟needl的第一个值不等，直接遍历下一个数。
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] != needle[0]) continue;
            else{
                for(int j = 0; j < needle.size(); j++){
                    if(haystack[i + j] != needle[j]) break;
                    if(j == needle.size() - 1) return i;
                }
            }
        }  
        return -1;      
    }
};
