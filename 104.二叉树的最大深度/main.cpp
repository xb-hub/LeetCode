#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// private:
//     int max_level = 0;
// public:
//     void dfs(TreeNode* root, int level)
//     {
//         if(root == nullptr)
//         {
//             max_level = max(max_level, level);
//             return;
//         }
//         dfs(root->left, level + 1);
//         dfs(root->right, level + 1);
//     }

//     int maxDepth(TreeNode* root) {
//         if(root == nullptr) return 0;
//         dfs(root, 0);
//         return this->max_level;
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int LD, RD;
        if(root == nullptr) return 0;
        else
        {
            LD = maxDepth(root->left);
            RD = maxDepth(root->right);
            return (LD > RD ? LD : RD) + 1;
        }
    }
};