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
    pair<int,int> diameterFast(TreeNode* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);   // diameter  height
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second+right.second;

        pair<int,int> ans;
        ans.first = max(op3,max(op1,op2));
        ans.second = max(left.second+1,right.second+1);
        return ans;
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int leftHeight = maxDepth(root->left)+1;
        int rightHeight = maxDepth(root->right)+1;
        return max(leftHeight,rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL) return 0;

        // int left = diameterOfBinaryTree(root->left);
        // int right = diameterOfBinaryTree(root->right);
        // int combined = maxDepth(root->left)+maxDepth(root->right);

        // return max(max(left,right),combined);

        return diameterFast(root).first;
    }
};