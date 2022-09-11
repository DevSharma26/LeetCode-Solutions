class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      // to store the pair of efficiency and speed
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i], speed[i]});
        }
      
        // to maintain the min heap of size k we will use priority queue
       priority_queue<int, vector<int>, greater<int>> pq;

        // sort in decreasing order of efficiency
        sort(v.rbegin(), v.rend());

        // totSpeed is the sum of speed of k engineers
        long totSpeed=0;
        long ans=0;

        // iterate over all engineers        
        for(int i=0;i<n;i++){
            int curSpeed=v[i].second;
            int curEff=v[i].first;

            // remove the minimum speed from the pq
            if(pq.size()==k){
                int speedValue=pq.top();
                totSpeed-=speedValue;
                pq.pop();
            }
            
            // push the current speed in the pq
            pq.push(curSpeed);
            
            // add the current speed to the totSpeed
            totSpeed+=curSpeed;
           
            
            // int performance=totSpeed*curEff;
            // update the ans
            ans = max(ans, totSpeed * curEff); 
        }
        return ans%1000000007;  
        
    }
};