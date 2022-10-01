class Solution {
public:
    
    int numDecodingshelper(int i, string s, int dp[]) {

        if(i >= s.size()) {
            
            return 1;
        }
        
        else if(int(s[i] - '0') == 0) {
            return 0;
        }
        
        else if(dp[i] != -1)
            return dp[i];
         
            int ans = 0;
            if(i + 2 <= s.size()) {
                int sum = 10*(s[i] -'0') + (s[i+1] - '0');
                if(sum <= 26) {
                    ans = numDecodingshelper(i+2, s, dp);
                }
            }
            
            ans += numDecodingshelper(i+1, s, dp);
            dp[i] = ans;
            return dp[i] ;
        
    }
    int numDecodings(string s) {
        
        int *dp = new int[s.size()+1]();
        
        for(int i =0  ; i <= s.size() ; i++) {
            dp[i] = -1;
        }
        return numDecodingshelper(0, s, dp);
    }
};