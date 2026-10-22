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
    int maxi = INT_MIN;
    unordered_map<int,int> mp;
    int inOrder(TreeNode* root){
        if(!root){
            return 0;
        }

        int sum= root->val + inOrder(root->left)+inOrder(root->right);
        mp[sum]++;
        maxi = max(maxi,mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        inOrder(root);
      
        for(auto [val,freq]: mp){
            if(freq==maxi){
                result.push_back(val);
            }
        }
       
        return result;
    }
};