class Solution {
public:
    vector<string> res;

    void paths(TreeNode* root, string s1){
        if (!root) return;

        
        if (s1 != "") s1 += "->";
        s1 += to_string(root->val);

        
        if (!root->left && !root->right) {
            res.push_back(s1);
            return;
        }

        
        paths(root->left, s1);
        paths(root->right, s1);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        paths(root, "");
        return res;
    }
};
