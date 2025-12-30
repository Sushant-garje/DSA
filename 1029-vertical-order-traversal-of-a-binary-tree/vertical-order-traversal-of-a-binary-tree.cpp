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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,map<int,multiset<int>>> coordi;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* temp = curr.first;
            int x=curr.second.first;
            int y = curr.second.second;
            coordi[x][y].insert(temp->val);

            if(temp->left) q.push({temp->left,{x-1,y+1}});
            if(temp->right) q.push({temp->right,{x+1,y+1}});

        }
        for(auto i:coordi){
            vector<int> verticle;
            for(auto j:i.second){
                verticle.insert(verticle.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(verticle);

        }

        return ans;
    }
};