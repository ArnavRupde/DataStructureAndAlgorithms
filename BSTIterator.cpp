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
class BSTIterator {
public:
    vector<int>v;
    int idx;
    void recur(TreeNode* root)
    {
        if(root==NULL)
            return;
        recur(root->left);
        v.push_back(root->val);
        recur(root->right);
    }
    BSTIterator(TreeNode* root) {
        idx=-1;
        recur(root);
        
    }
    
    /** @return the next smallest number */
    int next() {
        idx+=1;
        return v[idx];
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(idx+1<v.size())
            return true;
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */