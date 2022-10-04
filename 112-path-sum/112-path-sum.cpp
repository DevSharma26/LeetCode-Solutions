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
    private:
    bool solve(TreeNode* &root, int t)
    {
        if(!root)
            return false;
        
        if(root -> left == NULL && root -> right == NULL && t == root->val)
            return true;
        
        
        t = t - root -> val;
        return solve(root -> left, t) | solve(root -> right, t);
        
            
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};