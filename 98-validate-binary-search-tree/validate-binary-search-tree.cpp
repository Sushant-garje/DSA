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
    bool isValidBST(TreeNode* root) {
        long l = LONG_MIN;
        long r = LONG_MAX;
        return isBST(root,l,r);
        
    }

    bool isBST(TreeNode* root,long long l,long long r){
        if(!root) return true;
        if(!((root->val>l) && (root->val<r))) return false;

        return isBST(root->left,l,root->val) && isBST(root->right,root->val,r);
    }
};