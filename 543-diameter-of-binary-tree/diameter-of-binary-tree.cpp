/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> diameter_of_tree_opt(TreeNode* root) {

        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> leftinfo = diameter_of_tree_opt(root->left); // LD LH
        pair<int, int> rtinfo = diameter_of_tree_opt(root->right);  // RD RH

        int lh = leftinfo.second;
        int rh = rtinfo.second;

        int maxdia = max(lh + rh + 1, max(leftinfo.first, rtinfo.first));
        int maxht = max(lh, rh) + 1;

        return {maxdia, maxht};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter_of_tree_opt(root).first - 1;
    }
};