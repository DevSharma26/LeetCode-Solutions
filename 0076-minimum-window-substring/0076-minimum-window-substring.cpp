class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> cnt_t;
        for (const char &c : t)
            cnt_t[c]++;
        int alive_char = 0;
        for (const auto &[c, cnt] : cnt_t)
            alive_char++;
        
        int left = 0, right = -1;
        int min_left = 0, min_right = INT_MAX;
        
        int n_s = s.size();
        while (right < n_s - 1)
        {
           
            right++;
            if (cnt_t.count(s[right]))
                if (--cnt_t[s[right]] == 0)
                {
                    alive_char--;
                    
                    while (alive_char == 0 && left <= right)
                    {
                        if (right - left < min_right - min_left)
                            min_right = right, min_left = left;
                        
                        if (cnt_t.count(s[left]))
                            if (++cnt_t[s[left]] == 1)
                                alive_char++;
                        left++;
                    }
                }
        }
        return min_right == INT_MAX ? "" : s.substr(min_left, min_right - min_left + 1);
    }
};