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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] =i;
        }

        TreeNode* root = buildTree(preorder,0,preorder.size()-1,
                                    inorder,0,inorder.size()-1,map);
        return root;
        
    }

    TreeNode* buildTree(vector<int>& preorder,int prest,int preen,vector<int> &inorder,
                        int inst,int inen,unordered_map<int,int> &map){
            if (prest > preen || inst > inen) return nullptr;
            
                int idx = map[preorder[prest]];
                int diff = idx-inst;

                TreeNode* root = new TreeNode(preorder[prest]);
                TreeNode* left = buildTree(preorder,prest+1,prest+diff,
                                            inorder,inst,idx-1,map);
                TreeNode* right = buildTree(preorder,prest+diff+1,preen,
                                            inorder,idx+1,inen,map);

                root->left = left;
                root->right = right;
            return root;

    }
};