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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int iL, int iR, int pL, int pR)
    {
        if(pL > pR) return nullptr;
        int index;
        for(index = iL; index <=iR; index++)
        {
            if(inorder[index] == postorder[pR])  break;
        }
        TreeNode* node = new TreeNode(postorder[pR]);
        int move = index - iL;
        node->left = build(inorder, postorder, iL, index - 1, pL, pL + move - 1);
        node->right = build(inorder, postorder, index + 1, iR, pL + move, pR - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

int main()
{
    return 0;
}