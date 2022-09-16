class Solution {
public:

    
//     to avoid TLE using DP
    vector<vector<int>> dp;
    int solve(vector<int>& nums, vector<int>& multipliers, int index, int left, int right){
//         base case 
        if(index==multipliers.size()){
            return 0;
        }
//         checking dp value
        if(dp[index][left]!=INT_MIN){
            return dp[index][left];
        }
//         for left side
        int l=multipliers[index]*nums[left]+solve(nums,multipliers,index+1,left+1,right);
//         for right side
        int r=multipliers[index]*nums[right]+solve(nums,multipliers,index+1,left,right-1);
        return dp[index][left]=max(l,r);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        dp.assign(m+1,vector<int>(m+1,INT_MIN));
        int n=nums.size();
        int index=0;
        int left=0;
        int right=n-1;
        return solve(nums,multipliers,index,left,right);
    }
};