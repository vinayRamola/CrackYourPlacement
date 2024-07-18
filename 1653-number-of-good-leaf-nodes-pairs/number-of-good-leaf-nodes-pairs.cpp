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
    vector<int> helper(TreeNode* root,int distance,int &count){
        if(!root) return {};
        if(!root->left and !root->right) return {1};
        
        vector<int> leftDis,rightDis;

        if(root->left) leftDis = helper(root->left,distance,count); 
        if(root->right) rightDis = helper(root->right,distance,count);


        // compareing left+right distance of each node
        for(auto ld:leftDis){
            for(auto rd:rightDis){
                if(ld+rd <= distance) count++;
            }
        }

        vector<int> combinedDis;
        // sedinf the combined distance
        for(auto ld:leftDis)  combinedDis.push_back(ld+1);
        for(auto rd:rightDis)  combinedDis.push_back(rd+1);

        return combinedDis;
    }
    int countPairs(TreeNode* root, int distance) {
        int count=0;
        helper(root,distance,count);
        return count;
    }
};