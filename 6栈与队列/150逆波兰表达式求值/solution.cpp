/**
 *根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

 

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> temp;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long t1 = temp.top();
                temp.pop();
                long long t2 = temp.top();
                temp.pop();
                if(tokens[i] == "+"){
                    temp.push(t1 + t2);
                }
                if(tokens[i] == "-"){
                    temp.push(t2 - t1);
                }
                if(tokens[i] == "*"){
                    temp.push(t2 * t1);
                }
                if(tokens[i] == "/"){
                    temp.push(t2 / t1);
                }
            }
            else temp.push(stoll(tokens[i]));
    }
    return temp.top();
    }

};
