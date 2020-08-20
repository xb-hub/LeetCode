#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pL, int pR, int iL, int iR)
    {
        if(iL > iR) return nullptr;
        int index;
        for(index = iL; index <= iR; index++)
        {
            if(inorder[index] == preorder[pL])  break;
        }
        int move = index - iL;
        TreeNode* node = new TreeNode(preorder[pL]);
        node->left = build(preorder, inorder, pL + 1, pL + move, iL, index - 1);
        node->right = build(preorder, inorder, pL + 1 + move, pR, index + 1, iR);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};