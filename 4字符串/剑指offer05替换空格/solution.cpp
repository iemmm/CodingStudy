/*
 *请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * */
class Solution {
public:
    string replaceSpace(string s) {
        int m = 0;
        int old = s.size();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
               m++;
            } 
        }
        //  s.resize(s.size() + m * 2);
        s.append(2*m,' ');
        int slow =s.size() - 1;
        for(int fast = s.size() -1 - 2*m; fast < slow; fast--){
            if(s[fast] != ' '){
                s[slow] = s[fast];
                slow--;
            }
            else{
                s[slow--] = '0';
                s[slow--] = '2';
                s[slow--] = '%';
            }
        }
        return s;
    }
};
