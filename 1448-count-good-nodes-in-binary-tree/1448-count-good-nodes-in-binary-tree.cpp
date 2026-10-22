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
    int cnt=0;
    void helper(TreeNode* root,int prev){
        if(root==NULL){
            return;
        }
        if(prev <= root->val){
            cnt++;
        }
        prev=max(prev,root->val);

        helper(root->left,prev);
        helper(root->right,prev);
    }
   
    int goodNodes(TreeNode* root) {
        helper(root,INT_MIN);

        return cnt;
    }
};