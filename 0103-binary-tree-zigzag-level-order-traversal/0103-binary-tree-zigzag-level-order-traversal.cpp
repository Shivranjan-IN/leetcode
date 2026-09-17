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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // If tree is empty
        if (root == nullptr) {
            return ans;
        }

        // Queue for BFS / Level Order Traversal
        queue<TreeNode*> q;
        q.push(root);

        // Direction of current level
        bool leftToRight = true;

        while (!q.empty()) {

            // Number of nodes in current level
            int size = q.size();

            // Store current level
            vector<int> level(size);

            for (int i = 0; i < size; i++) {

                // Take node from front
                TreeNode* node = q.front();
                q.pop();

                int index;

                // Decide position according to direction
                if (leftToRight) {
                    index = i;
                }
                else {
                    index = size - 1 - i;
                }

                // Store node value
                level[index] = node->val;

                // Add left child
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Add right child
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Add current level to answer
            ans.push_back(level);

            // Change direction
            leftToRight = !leftToRight;
        }

        return ans;
    }

};