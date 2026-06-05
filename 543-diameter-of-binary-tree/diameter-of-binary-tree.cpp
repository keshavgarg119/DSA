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
    int diameter(TreeNode* root, int &dia) {
        if(root==nullptr) return 0;

        int lh = diameter(root->left, dia);
        int rh = diameter(root->right, dia);
        dia = max(lh+rh, dia);

        return 1+max(lh,rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameter(root, dia);
        return dia;
    }
};