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
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        //basically inorder with counter variable
        int ans=-1;
        dfs(root,k,ans);
        return ans;
    }
    void dfs(TreeNode* root, int k, int& ans) {
        if(!root) return;
        dfs(root->left,k,ans);
        count++;
        if(k==count){
            ans=root->val;
            return;
        }
        dfs(root->right,k,ans);
    }
};