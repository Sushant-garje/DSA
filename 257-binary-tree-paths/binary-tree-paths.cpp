class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s ="";
        path(root ,ans,s);
        return ans;
    }

    void path(TreeNode* root, vector<string>& ans, string& s) {
    if (!root) return;

    int len = s.size();   // save current length

    s += to_string(root->val);

    if (!root->left && !root->right) {
        ans.push_back(s);
    } else {
        s += "->";
        path(root->left, ans, s);
        path(root->right, ans, s);
    }

    s.resize(len);  // backtrack safely
}
};