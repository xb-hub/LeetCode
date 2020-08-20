#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        stack<vector<int>> s;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left != nullptr)    q.push(tmp->left);
                if(tmp->right != nullptr)   q.push(tmp->right);
            }
            s.push(level);
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};