/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void vadd(vector<int> & v,TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        
        vadd(v,root->left);
        v.push_back(root->val);
        vadd(v,root->right);
        
        return ;
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> v;
        
        vadd(v,root);
       
        int i = 0;
        int j = v.size()-1;
        int sum;
        
        while(i<j)
        {
            sum = v[i]+v[j];
            

            if(sum == k)
            {
                return true;
            }
            else if(sum > k)
            {
                sum -= v[j];
                j--;
            }
            else if(sum < k)
            {
                sum -= v[i];
                i++;
            }
        }
        
        
        return false;
    }
};