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
class Solution
{
public:
    int ans = 0;
    vector<int> v;
    void recur(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            int n = v.size();
            int num = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i])
                    num += pow(2, v[i] * (n - i - 1));
            }
            ans += num;
            return;
        }
        if (root->left)
        {
            v.push_back(root->left->val);
            recur(root->left);
            v.pop_back();
        }
        if (root->right)
        {
            v.push_back(root->right->val);
            recur(root->right);
            v.pop_back();
        }
    }

    int sumRootToLeaf(TreeNode *root)
    {
        v.push_back(root->val);
        cout << v[0] << endl;
        recur(root);
        return ans;
    }
};