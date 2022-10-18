class Solution {
public:
    string countAndSay(int n) {
        string ans = "1", curr = "";
        int cnt = 1 , i = 0;
        while(--n) {
            while(i < ans.size()) {
                while((i < ans.size()-1) and (ans[i] == ans[i+1]))
                      i++, cnt++;
                curr += to_string(cnt) + ans[i++];
                cnt = 1;
            }
            ans = curr, curr = "", i = 0;
        }
        return ans;
    }
};