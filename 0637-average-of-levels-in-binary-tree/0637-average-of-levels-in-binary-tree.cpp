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
     vector<double> ans;
    void bfs(TreeNode* root){
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            int d= sz;
            double avg=0;
            while(sz--){
            TreeNode * temp = q.front();
            q.pop();

            avg+=temp->val;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }
            avg/=d;
            ans.push_back(avg);
           
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        bfs(root);
        return ans;
    }
};