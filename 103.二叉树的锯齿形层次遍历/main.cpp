#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            int size = s.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = s.top();
            }
        }
        
    }
};