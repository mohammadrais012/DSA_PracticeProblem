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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(subRoot==NULL && root==NULL) return true;
        if (!root || !subRoot) return false;
        if(root->val==subRoot->val){
            return isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
        }

        return false;
    }
    bool preOrder(TreeNode* root, TreeNode* subRoot){
       if(root==NULL) return false;
       if(root->val==subRoot->val){
           if(isSame(root,subRoot)) return true;
       }
        return preOrder(root->left,subRoot) || preOrder(root->right,subRoot);

      
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        return preOrder(root,subRoot);
    }
};