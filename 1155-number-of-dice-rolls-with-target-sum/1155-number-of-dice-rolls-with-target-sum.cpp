class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        int modulo=1000000007;
        int dp[n+1][target+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++)
                dp[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(i==1 && j<=k)
                    dp[i][j]=1; 
                else{
                    for(int l=1;l<=k;l++){
                        if(j-l>=0)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-l])%modulo;

                    }
                }
            }
        }
        return dp[n][target];
    }
};