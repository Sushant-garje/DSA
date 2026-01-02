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
    void track_par(TreeNode* root,map<TreeNode*,TreeNode*> &par){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            TreeNode* temp =q.front();
            q.pop();
            if(temp->left) {
                par[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                par[temp->right] = temp;
                 q.push(temp->right);
            }
            
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*,TreeNode*> par;
        track_par(root,par);
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int level =0;
        while(!q.empty()){
            int size = q.size();
            if(level==k) break;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right]){
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                if(par[temp] && !visited[par[temp]]){
                    visited[par[temp]] =true;
                    q.push(par[temp]);
                }
                
            }
            level++;

        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
        
    }

};