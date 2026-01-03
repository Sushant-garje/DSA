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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }

        TreeNode* root = buildTree(inorder,0,inorder.size()-1,
                                    postorder,0,postorder.size()-1,map);

        return root;
    }

    TreeNode* buildTree(vector<int>&inorder,int inst,int inen,
                        vector<int>&postorder,int psst,int psen,
                        unordered_map<int,int> &map){
            if(inst>inen || psst>psen) return nullptr;
            int node = postorder[psen];
            int idx = map[postorder[psen]];
            int diff = idx-inst;
            TreeNode* root = new TreeNode(node);

            TreeNode* left = buildTree(inorder,inst,idx-1,
                                        postorder,psst,psst+diff-1,map);
            TreeNode* right = buildTree(inorder,idx+1,inen,
                                        postorder,psst+diff,psen-1,map);

            root->left = left;
            root->right = right;

            return root;


    }
};