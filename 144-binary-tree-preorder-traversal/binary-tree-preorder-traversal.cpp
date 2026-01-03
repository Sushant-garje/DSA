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
        vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* curr = root;
        while(curr){
            if(!(curr->left)){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }

                if(prev->right==nullptr){
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    curr= curr->right;
                }

            }
        }
        
        return ans;
    }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(!root) return {};
    //     vector<int> ans;
    //     stack<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode* temp = q.top();
    //         q.pop();
    //         ans.push_back(temp->val);
    //         if(temp->right) q.push(temp->right);
    //         if(temp->left)  q.push(temp->left);
            
    //     }
    //     return ans;
        
    // }
    // void preorder(vector<int> &ans,TreeNode* root){
    //     if(root==nullptr) return;
    //     ans.push_back(root->val);
    //     preorder(ans,root->left);
    //     preorder(ans,root->right);

    // }
};