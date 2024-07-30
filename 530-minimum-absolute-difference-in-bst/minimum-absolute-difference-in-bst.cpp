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
    void inorder(TreeNode* root,int &prev,int &ans){
        if(root==NULL) return;

        
        inorder(root->left,prev,ans);
        if(prev==-1){
            prev = root->val;
        }
        else{
            ans = min(ans,abs(root->val-prev));
            prev = root->val;
        }
        inorder(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        int prev = -1;
        inorder(root,prev,ans);
        
        return ans;
    }
};