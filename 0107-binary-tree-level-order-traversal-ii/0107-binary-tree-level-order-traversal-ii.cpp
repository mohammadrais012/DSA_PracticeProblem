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
    vector<vector<int>> ans;
    void bfs(TreeNode* root){
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            vector<int> curr;
            while(sz--){
            TreeNode * temp = q.front();
            q.pop();

            curr.push_back(temp->val);

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }

            ans.push_back(curr);
           
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        bfs(root);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};