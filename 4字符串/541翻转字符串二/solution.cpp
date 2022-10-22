/**

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

//代码随想录
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (2*k)){
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};


//自己思考

class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        int kk = 2 *  k;
        if(size >= kk){
            //翻转前面的数字
            for(int i = 1; i < size; i++){
                int m = i % kk;
                if(m == kk-1){
                int left = i - 2 *k + 1;
                int right = i - k;
                while(left < right){
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                }
                }
            }
        }
        //翻转末尾的数字
        int j = size % (2 * k);
        if(j != 0 ){
                //翻转全部
            if(j <= k){
                int left = size -j;
                int right = size - 1;
                while(left < right){
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                }
            }
            else{
                int left = size - j ;
                int right =size - j + k - 1;
                while(left < right){
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                } 
            }
        }
        return s;
    }

};