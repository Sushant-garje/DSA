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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int count = 0;
        inorder(root,ans,k,count);
        return ans;
        
    }
    void inorder(TreeNode* root,int & ans,int k,int &count){
        if(!root || count>=k) return;
        inorder(root->left,ans,k,count);
        count++;
        if(count==k) {ans = root->val;return ;}
        inorder(root->right,ans,k,count);

    }
};