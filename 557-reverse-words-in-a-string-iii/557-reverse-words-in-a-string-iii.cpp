class Solution {
public:
    string reverseWords(string s) {
        
        // add guard space
        s.insert(s.begin(), ' ');   s.push_back(' ');
        vector<int> space_indexes;
        for (int i = 0; i < int(s.size()); i++){
            if (s[i] == ' '){
                space_indexes.push_back(i);
            }
        }
        vector<string> words;
        for (int i = 0; i < (int)space_indexes.size() - 1; i++){
            int start = space_indexes[i] + 1;
            int back = space_indexes[i + 1] - 1;
            int word_sz = back - start + 1;
            words.push_back(s.substr(start, word_sz));
        }
        string result;
        for (auto word: words){
            reverse(word.begin(), word.end());
            result += word;
            result.push_back(' ');
        }
        result.pop_back();
        return result;
    }
};