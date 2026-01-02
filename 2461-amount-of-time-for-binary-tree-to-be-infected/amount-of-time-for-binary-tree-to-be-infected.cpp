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
    TreeNode* parent_track(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par,int target){
        queue<TreeNode*> q;
        TreeNode* goal = nullptr;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp->val==target){
                goal = temp;
            }
            q.pop();
            if(temp->left){
                par[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                par[temp->right] = temp;
                q.push(temp->right);
            }
        }


        return goal;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> par;
        TreeNode* target = parent_track(root,par,start);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !visited.count(curr->left)){
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right && !visited.count(curr->right)){
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if(par.count(curr) && !visited.count(par[curr])){
                    visited.insert(par[curr]);
                    q.push(par[curr]);
                }
            }
            time++;
        }
        
        return time;
    }
};