class Solution {
public:
    int dp[1001][1001];
    int findLength(vector<int>& a, vector<int>& b) {
        int maxL=0;
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        dfs(a,b,0,0,maxL);
        return maxL;
    }
    int dfs(vector<int>& a, vector<int>& b,int i,int j,int& maxL){
        
        if(i==a.size() or j==b.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int L=0;
        if(a[i]==b[j]){
        L =  1+dfs(a,b,i+1,j+1,maxL);
        maxL = max(maxL,L);    
        }
            dfs(a,b,i,j+1,maxL);
            dfs(a,b,i+1,j,maxL);
        return dp[i][j] = L;
    }
    
};