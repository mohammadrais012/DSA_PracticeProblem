/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> graph;

    void buildGraph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right);
        }
    }

    int bfs(int start) {
        queue<int> q;
        unordered_set<int> vis;

        q.push(start);
        vis.insert(start);

        int time = -1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int nei : graph[node]) {
                    if (!vis.count(nei)) {
                        vis.insert(nei);
                        q.push(nei);
                    }
                }
            }

            time++;
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        return bfs(start);
    }
};