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
    unordered_map<int,int> mp;
    int inOrder(TreeNode* root){
        if(!root){
            return 0;
        }

        int sum= root->val + inOrder(root->left)+inOrder(root->right);
        mp[sum]++;

        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        priority_queue<pair<int,int>> pq;
        inOrder(root);
        int maxi = INT_MIN;
        for(auto it: mp){
            maxi = max(maxi,it.second);
            pq.push({it.second,it.first});
        }
        vector<int> result;
        while(!pq.empty()){
            auto[freq,val]=pq.top();
            pq.pop();
            if(freq==maxi){
                result.push_back(val);
            }
            else{
                break;
            }
        }
        return result;
    }
};