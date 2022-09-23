class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans = 0, mod = 1e9 + 7;
        int sz = 0;
        
        for(int i = 1; i<=n; i++){
            if((i&(i-1)) == 0)
                sz++;
            
            ans = (ans*(1<<sz) + i)%mod;
        }
        return ans;
    }
};