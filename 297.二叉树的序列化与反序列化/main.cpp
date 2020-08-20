#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "[]";
        string ans = "";
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if(front == NULL)
            {
                ans += "null,";
            }
            else
            {
                ans += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
            
        }
        ans = "[" + ans.substr(0, ans.size() - 1) + "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size() - 2);
        if(data.size() == 0)    return nullptr;
        stringstream ss;
        ss.str(data);
        string value;

        getline(ss, value, ',');
        TreeNode *root = new TreeNode(stoi(value));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if(!getline(ss, value, ','))    break;
            if(value != "null")
            {
                TreeNode *node = new TreeNode(stoi(value));
                front->left = node;
                q.push(node);
            }

            if(!getline(ss, value, ','))    break;
            if(value != "null")
            {
                TreeNode *node = new TreeNode(stoi(value));
                front->right = node;
                q.push(node);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    root->left = node2;    root->right = node3;
    node3->left = node4;    node3->right = node5;
    Codec codec;
    cout << codec.serialize(codec.deserialize(codec.serialize(root))) << endl;
}