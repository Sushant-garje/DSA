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
    void track_par(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& par) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left) {
                par[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                par[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target->val};

        unordered_map<TreeNode*, TreeNode*> par;
        track_par(root, par);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (level == k) break;

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left && !visited.count(temp->left)) {
                    visited.insert(temp->left);
                    q.push(temp->left);
                }

                if (temp->right && !visited.count(temp->right)) {
                    visited.insert(temp->right);
                    q.push(temp->right);
                }

                if (par.count(temp) && !visited.count(par[temp])) {
                    visited.insert(par[temp]);
                    q.push(par[temp]);
                }
            }
            level++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};