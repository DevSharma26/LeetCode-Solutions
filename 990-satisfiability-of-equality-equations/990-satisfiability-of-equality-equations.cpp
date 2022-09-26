class Solution {
public:
    vector<int>parent;
 	int find(int x) {
 		if (parent[x] == -1)
            return x;
        
        return parent[x] = find(parent[x]);
        
 	}
    bool equationsPossible(vector<string>& equations) {
        
        
        parent.resize(26,-1);
        for(string equation : equations){
            
            int x = find(equation[0] - 'a');
            int y = find(equation[3] - 'a');
            
            
            if(equation[1] == '=' && x != y)
                parent[y] = x;
        }
        for(string equation: equations){
            int x = find(equation[0] - 'a');
            int y = find(equation[3] - 'a');
           
            if(equation[1] == '!' && x == y)
                return false;
        }
        return true;
    }
};