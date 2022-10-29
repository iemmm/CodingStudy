/*给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 * 第一种方法：
 * 如果一个字符串s是由一个子字符串重复多次构成，那么s+s去头去尾后的字符串一定至少包含一个s.
 * 第二种方法：
 * 在由重复子串组成的字符串中，最后一个字符的最长相等前后缀不包含的子串就是最小重复子串。
 * */
//方法一：
class Solution {
public:

//CMP算法
    //最大相等前后缀长度数组的生成
    void getNext(string& s, int* next){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }
    bool find(string t, string s){
        int next[s.size()];
        getNext(s, next);
        int j = 0;
        for(int i = 0 ; i < t.size(); i++){
            while(j > 0 && s[j] != t[i]){
                j = next[j - 1];
            }
            if(s[j] == t[i]){
                j++;
            }
            if(j == s.size()) return true;
        }
        return false;
    }
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end()-1);
        if(find(t, s)) return true;
        return false;
    }
};


//方法二：

class Solution {
public:

//CMP算法
    //最大相等前后缀长度数组的生成
    void getNext(string& s, int* next){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(s, next);
        int len = s.size();
        cout << (s.size() - next[len -1]);
        if(next[len - 1] != 0 && len%(len - next[len -1]) == 0) return true;
        return false;
    }
};
