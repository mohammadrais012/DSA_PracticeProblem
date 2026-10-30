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
    bool inorder(TreeNode* root, int targetSum,int sum){
        if(!root) return false;
        if(!root->left && !root->right){
            sum+=root->val;
            return targetSum==sum;
        }
        
        bool left= inorder(root->left,targetSum,sum+root->val);
        bool right= inorder(root->right,targetSum,sum+root->val);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return inorder(root,targetSum,0);
    }
};