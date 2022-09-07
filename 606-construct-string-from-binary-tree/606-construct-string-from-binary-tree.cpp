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
    string solve(TreeNode* &root){
        //base case
        if(root==NULL)
            return "";
        
        string str="";
        str+= to_string(root->val);
        string left = solve(root->left);
        string right= solve(root->right);
        // when right is "" we can / cannot take left
        if(right==""){
            if(left!="")
                str+= "(" + left +  ")";
        }
        
        //when right is not "" then we have to take left
        else{
            str+= "(" + left + ")" + "(" + right + ")";
        }
        return str;
    }
    string tree2str(TreeNode* root) {
        
        return solve(root);
    }
};