#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left != nullptr)    q.push(tmp->left);
                if(tmp->right != nullptr)   q.push(tmp->right); 
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main()
{

}