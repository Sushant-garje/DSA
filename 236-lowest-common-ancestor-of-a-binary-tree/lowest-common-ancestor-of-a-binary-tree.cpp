/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(root==p && left) return root;
        else if(root==q && right) return root;
        else if(root==p) return p;
        else if((root==q)) return q;
        else if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        
        return nullptr;
        
    }
};