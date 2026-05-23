/*
  Given the root of a binary tree, 
  return the preorder traversal of its nodes' values.
  Time complexity: O(n)
  Space complexity: O(h)
  */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;        
    }
private:
    void preorder(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }    
};
