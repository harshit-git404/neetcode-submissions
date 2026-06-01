/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr;
        //don't ignore dfs values, return them
        if(root->val < p->val && root->val < q->val) return dfs(root->right, p, q);
        if(root->val > p->val && root->val > q->val) return dfs(root->left, p, q);
                                   //no need to put this condn, if both above condn not satisfied, then root is the answer
        // if((root->val > p->val && root->val < q->val)||((root->val < p->val && root->val > q->val))||(root->val == p->val)||(root->val == q->val))             //don't assume p<q
        //     return root;

        return root;
    }
};