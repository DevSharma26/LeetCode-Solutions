class TimeMap {
    unordered_map<string, map<int, string> > mpp;
   
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value;     
    }
    
    string get(string key, int timestamp) {
       
        if((mpp.find(key) != mpp.end()) && (!mpp[key].empty()) && ((mpp[key].begin())->first <= timestamp) ) {
            
            for(auto it = mpp[key].rbegin(); it != mpp[key].rend(); ++it) {
                if(it->first <= timestamp) {
                    return it->second;
                }
            }
        }
      
        return "";
    }
};