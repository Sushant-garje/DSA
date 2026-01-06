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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* temp = root;
        stack<TreeNode*> st;
        st.push(root);
        for(int i =1;i<preorder.size();i++){
            if(temp->val >preorder[i]){
                temp->left = new TreeNode(preorder[i]);
                temp = temp->left;
                st.push(temp);
            }
            else{
                TreeNode* curr =  temp;
                while(!st.empty()){
                    if(st.top()->val > preorder[i]){
                        break;
                    }
                    curr=st.top();
                    st.pop();
                }
                 temp = curr;
                temp->right = new TreeNode(preorder[i]);
                temp = temp->right;
                st.push(temp);
            }
        }

        return root;

        
    }
};