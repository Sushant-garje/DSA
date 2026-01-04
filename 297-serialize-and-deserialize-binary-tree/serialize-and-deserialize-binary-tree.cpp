/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp) {ans +="#,"; continue;}
            ans = ans+to_string(temp->val);
            ans+=',';
            q.push(temp->left); 
            q.push(temp->right); 
           
        }

        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        vector<string> values;
        string token;
        queue<TreeNode*> q;
        for(char c:data){
            if(c==','){
                values.push_back(token);
                token.clear();
            }
            else{
                token.push_back(c);
            }
        }

        int idx =0;
        TreeNode* root = new TreeNode(stoi(values[idx++]));
        q.push(root);

        while(!q.empty() && idx < values.size()){
            TreeNode* front = q.front(); q.pop();

            if(values[idx]!="#"){
                front->left = new TreeNode(stoi(values[idx]));
                q.push(front->left);
            }
            idx++;
            if(idx<values.size() &&values[idx]!="#"){
                front->right = new TreeNode(stoi(values[idx]));
                q.push(front->right);
            }
            idx++;
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));