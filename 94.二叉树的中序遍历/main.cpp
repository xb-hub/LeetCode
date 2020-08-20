#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归实现
// class Solution {
//     vector<int> result;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root)
//         {
//             inorderTraversal(root->left);
//             result.push_back(root->val);
//             inorderTraversal(root->right);
//         }
//         return result;
//     }
// };

// 迭代实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode> s;
        TreeNode* p = root;
        while (!s.empty() || p != NULL)
        {
            while (p != NULL)
            {
                s.push(*p);
                p = p->left;
            }
            if(!s.empty())
            {
                cout << s.top().val << " ";
                s.pop();
                p = p->right;
            }
        }
        
    }
};

int main()
{
    
}
