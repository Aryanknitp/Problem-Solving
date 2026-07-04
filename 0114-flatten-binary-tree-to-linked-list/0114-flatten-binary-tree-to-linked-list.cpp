
class Solution {
public:
    void in(TreeNode* root, vector<TreeNode*>& v) {
        if (root == nullptr)
            return;
        v.push_back(root);
        in(root->left, v);
        in(root->right, v);
    }
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        vector<TreeNode*> v;
        // TreeNode* d = new TreeNode(-1);
        in(root, v);
        TreeNode* t = root;
        for (int i = 1; i < v.size(); i++) {
            t->left = nullptr;
            t->right = v[i];
            t = t->right;
        }
        // return d->next;
    }
};