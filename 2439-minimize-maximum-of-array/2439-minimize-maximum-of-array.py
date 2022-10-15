class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long s=0,ma=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            long long d=s/(i+1);
            long long rem=s%(i+1);
            if(rem!=0) rem=1;
            ma=max(ma,d+rem);
        }
        return ma;
    }
};