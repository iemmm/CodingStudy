/**
 *给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> temp;
        for(int i = 0; i < s.size(); i++){
            if(temp.empty() || s[i] != temp.top()){//当栈为空时，直接访问栈的top会报地址错误。
                temp.push(s[i]);
            }
            else{
                temp.pop();
            }
        }
        string res = "";
        while(!temp.empty()){
        res.push_back(temp.top());
        temp.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
