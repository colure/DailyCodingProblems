/**
 * Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, 
 * and deserialize(s), which deserializes the string back into the tree.
 *  For example, given the following Node class
 * class Node:
 *   def __init__(self, val, left=None, right=None):
 *       self.val = val
 *       self.left = left
 *       self.right = right
 * The following test should pass:
 *
 * node = Node('root', Node('left', Node('left.left')), Node('right'))
 * assert deserialize(serialize(node)).left.left.val == 'left.left'
 *
 *
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    
    int helper(string &data)
    {
        int pos = data.find(',');
        int v = stoi(data.substr(0, pos));
        data = data.substr(pos+1);
        return v;
    }
    
    TreeNode* deserializeUtil(string &data) {
        if (data[0] == '#')
        {
            if (data.size() > 1) data = data.substr(2);
            return NULL;
        }
        
        TreeNode* root = new TreeNode(helper(data));
        root->left = deserializeUtil(data);
        root->right = deserializeUtil(data);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeUtil(data);
    }
    
    
};
