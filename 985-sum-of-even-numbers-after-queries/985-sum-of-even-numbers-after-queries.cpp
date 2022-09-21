class Solution {
public:

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum=0;
        for(auto i:nums){
            if(i%2==0)
              sum+=i;
        }
        vector<int>ans;
        int m=queries.size();
        for(auto i:queries){
            int val = i[0];
            int idx = i[1];
            int prev = nums[idx];
            if((prev+val)%2==0){
                if(prev%2==0){
                    sum-=prev;
                    sum+=prev+val;
                }
                else{
                    sum+=prev+val;
                }
            }
            else{
                if(prev%2==0){
                    sum-=prev;
                }
            }
            nums[idx]=prev+val;
            ans.push_back(sum);
        }
        
        return ans;
    }
};