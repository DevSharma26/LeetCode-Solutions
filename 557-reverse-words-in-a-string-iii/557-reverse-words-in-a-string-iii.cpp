class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string ans = "",a = "";
        while(i < s.size()){
            if(s[i] == ' ' || i == s.size() - 1){
                if(i == s.size()-1)a=s[i]+a;
                ans += a;
                ans += ' ';
                a = "";
                i++;
                continue;
            }
            a = s[i] + a;
            i++;
        }
        ans.pop_back();
        return ans;
    }
};