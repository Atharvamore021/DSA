/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
          if(root==NULL) return 0;
          int left = height(root->left);
          int right = height(root->right);
          int ans =  max(left,right)+1; 
          return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        // one case slove
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight-rightHeight);
        bool ans1 = (diff<=1);
        // remaining recursion will see
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(ans1 && left && right) return true;
        else return false;
    }
};