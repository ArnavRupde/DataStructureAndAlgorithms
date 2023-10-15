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
    TreeNode* recur(TreeNode* root, TreeNode* prv)
    {
        if(root==NULL)
            return prv;
        if(prv!=NULL)
        {
            prv->left=NULL;
            prv->right=root;
        }
        TreeNode* leftNode=root->left;
        TreeNode* rightNode=root->right;
        prv=recur(leftNode,root);
        return recur(rightNode,prv);

    }
    void flatten(TreeNode* root) {
        root=recur(root,NULL);
    }
};