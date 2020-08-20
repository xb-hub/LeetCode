#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root->left != nullptr && root->right != nullptr)
        {
            if(root->left->val > root->val || root->right->val < root->val)
            {
                return false;
            }
            isValidBST(root->left);
            isValidBST(root->right);
        }
        else if(root->left != nullptr)
        {
            if(root->left->val > root->val)
            {
                return false;
            }
            isValidBST(root->left);
        }
        else if(root->right != nullptr)
        {
            if(root->right->val < root->val)
            {
                return false;
            }
            isValidBST(root->right);
        }
    }
};