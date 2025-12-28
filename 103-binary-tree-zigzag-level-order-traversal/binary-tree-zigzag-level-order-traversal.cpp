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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool l_to_r = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> curr(size);
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop(); 
                int idx = (l_to_r) ?(i) :(size-1-i) ;
                curr[idx] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);             
            }
            l_to_r = !l_to_r;
            ans.push_back(curr);
        }
        return ans;
    }
};