/*
 *给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

class Solution {
public:
    //翻转字符串某段位置的字符
    void rever(int left, int right, string& s){
        while(left < right){
            int temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
    }
    //删除多余的空格
    void remove(string& s){
        int slow = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                if(slow != 0) s[slow++] = ' ';
                while(i < s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
       remove(s);
       rever(0, s.size() - 1, s);
       int preindex = 0;
       for(int i = 0; i < s.size(); i++){
           if(s[i] == ' '){
               rever(preindex, i - 1, s);
               preindex = i + 1;
           }
       } 
       rever(preindex, s.size() - 1, s);
       return s;
    }

};




//第二种解法
class Solution {
public:
    //翻转字符串某段位置的字符
    void rever(int left, int right, string& s){
        while(left < right){
            int temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
       string test = {};
       if(s[0] != ' ') test.push_back(s[0]);
       //将要翻转的字符串标准化，因为可能有的字符串中有多个连着的空格；
       for(int i = 1 ; i < s.size(); i++){
           if(s[i] != ' '|| (s[i] == ' '&& s[i-1] != ' ')){
               test.push_back(s[i]);
           }
       }
       if(test[test.size() - 1] == ' ') test.erase(test.size() - 1,test.size());
       //先将标准化后的字符串整体翻转；
       rever(0, test.size() - 1, test);
       //再将每个单词翻转。
       int preindex = 0;
       for(int i = 0; i < test.size(); i++){
           if(test[i] == ' '){
               rever(preindex, i - 1, test);
               preindex = i + 1;
           }
       } 
       rever(preindex, test.size() - 1, test);
       return test;
    }

};

