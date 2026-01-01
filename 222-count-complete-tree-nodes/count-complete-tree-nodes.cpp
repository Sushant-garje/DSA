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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int dleft = ldepth(root);
        int dright = rdepth(root);
        if(dleft==dright){
            return (1<<dleft)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);   
    }

    int ldepth(TreeNode* root){
        if(!root) return 0;
        int h =0;
        TreeNode* temp = root;
        while(temp){
            h++;
            temp = temp->left;
        }
        return h;
    }
    int rdepth(TreeNode* root){
        if(!root) return 0;
        int h =0;
        TreeNode* temp = root;
        while(temp){
            h++;
            temp = temp->right;
        }
        return h;
    }
};