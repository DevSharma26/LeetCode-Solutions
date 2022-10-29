class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> plant;

        for(int i=0;i<plantTime.size();i++)
        {
            plant.push_back({growTime[i],plantTime[i]});
        }
        sort(plant.begin(),plant.end());
        int grow=0;
        long long ans=0;
        for(int i=plant.size()-1;i>=0;i--)
        {
            ans+=plant[i].second;
            grow=max(grow-plant[i].second,plant[i].first);
        }

        return ans+grow;
    }
};